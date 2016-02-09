<?hh //strict

require_once 'Printer.hh';
require_once 'Func.hh';

class Source extends Printer {
    private array<Func> $functions = array();
    
    public function __construct(string $filename) {
        $this->fileName = $filename;
        $this->fileType = "cpp";
    }
    
    public function getFunctions() : array<Func> {
        return $this->functions;
    }
    
    public function setFunctions(array<Func> $functions) : this {
        $this->functions = $functions;
        return $this;
    }
    
    public function add2Functions(Func $function) : this {
        if (is_array($this->functions)) {
            $this->functions[] = $function;
        } else {
            $this->functions = array($function);
        }
        
        return $this;
    }
    
    protected function printDefines() : void {
        
    }
    
    protected function printIncludes() : void {
        $this->add("#include \"". $this->fileName .".h\"");
    }
    
	protected function printBody() : void {
		/*
		 * list of functions where libgit2 return a number of something
		 * throw exception if return < 0
		 */
		$funcList = array(
			"git_oid_shorten_add",
			"git_packbuilder_set_threads",
			"git_patch_num_lines_in_hunk");
		
		/*
		 * list of functions where libgit2 return value is boolen
		 * throw exception if return < 0 || 1 < return
		 */
		$funcList2 = array(
			"git_object_typeisloose",
			"git_oid_iszero",
			"git_remote_connected",
			"git_repository_head_detached",
			"git_repository_head_unborn",
			"git_submodule_fetch_recurse_submodules");
		
        $body = "";
        
        $body .= "\nusing namespace HPHP;\n";
        
        foreach ($this->functions as $function) {
            $hasOutValue = false;
            $outValPointerLvl = 0;
            
            if (count($function->getParams()) &&
                	(preg_match("/out/" ,$function->getParams()[0]->getName()) ||
                    (preg_match("/_((dup|lookup|open|peel|gen_ancestor|create|next|load|rename|add_setup)($|_)|diff_[\w]*?_to_)/", $function->getName()) && count($function->getParams()) > 1))) {
                $returnType = $function->getParams()[0]->getType();
                $outValPointerLvl = $function->getParams()[0]->getPointerLvl();
                $hasOutValue = true;
            } else {
                $returnType = $function->getReturnType();
            }
            
            /* Build function header, skip out param if exist */
            $body .= "\n" . $returnType->getHHVMReturnType() ." HHVM_FUNCTION(".$function->getName().",";
            foreach ($function->getParams() as $k => $param) {
                if ($k == 0 && $hasOutValue) {
                    continue;
                }
                
                if ($param->getPointerLvl() > 1) {
                    $body .= "\n\tconst Array& " . $param->getName() . ",";
                } else {
                    $body .= "\n\t" . $param->getType()->getHHVMType() . " " . $param->getName() .",";
                }
            }
            $body = rtrim($body, ",") . ")\n{";
            
            if ($returnType->typeToHackType() != HackType::VOID) {
                if ($function->getReturnType()->getType() == "int") {
                    $body .= "\n\tint result;";
                } else if (!$hasOutValue) {
                    $body .= "\n\t" . ($function->isConstant() ? "const " : "") . $function->getReturnType()->getType() . " " . str_repeat("*", $function->getPointerLvl()) . "result;";
                }
                
                if ($returnType->typeToHackType() == HackType::RESOURCE) {
                    $body .= "\n\tauto return_value = req::make<Git2Resource>();\n";
                } else if ($returnType->getType() == "git_oid" || ($hasOutValue && $function->getParams()[0]->getType()->getType() == "git_oid")) {
                    $body .= "\n\tchar return_value[GIT_OID_HEXSZ+1] = {0};\n";
                } else {
                    $body .= "\n\t" . $returnType->getHHVMReturnType() . " return_value;\n";
                }
            }
            
            $body = rtrim($body) . "\n\n";
            
            /* Declaration of needed variables for libgit function call */
            foreach ($function->getParams() as $k => $param) {
                $hackType = $param->getType()->typeToHackType();
                
                if ($k == 0 && $hasOutValue) {
                    $body .= "\t" . ($param->isConstant() ? "const " : "") . $param->getType()->getType() . " " . ($outValPointerLvl > 1 ? "*" : "") . $param->getName() .  ($outValPointerLvl > 1 ? " = NULL" : "") . ";\n";
                } else if ($param->getPointerLvl() > 1) {
                    $body .= "\t" . ($param->isConstant() ? "const " : "") . $param->getType()->getType() . " " . str_repeat("*", $param->getPointerLvl()) . $param->getName() . "_;\n";
                } else {
                    switch ($hackType) {
                        case HackType::VOID :
                            $body .= "\t" . $param->getType()->getType() . " " . str_repeat("*", $param->getPointerLvl()) . $param->getName() . "_ = NULL;\n";
                            break;
                        case HackType::CALLABLE :
                            $body .= "\t" . $param->getType()->getType() . " " . str_repeat("*", $param->getPointerLvl()) . $param->getName() . "_ = NULL;\n";
                    		break;
                        case HackType::STRING :
                            if ($param->getType()->getType() == "git_oid") {
                                $body .= "\t" . $param->getType()->getType() . " " . $param->getName() . "_;\n";
                            }
                            break;
                        default : break;
                    }
                }
            }
            
            $body = rtrim($body) . "\n\n";
            
            /* Convert given params from hhvm-type to needed type in libgit function call */
            foreach ($function->getParams() as $k => $param) {
                if ($k == 0 && $hasOutValue) {
                    continue;
                }
                
                $hackType = $param->getType()->typeToHackType();
                
                // todo add convertion of void and callback params
                
                if ($hackType == HackType::CALLABLE) {
                    $body .= "\t" . $param->getName() . "_ = NULL;\n";
                } else if ($hackType == HackType::RESOURCE) {
                    $body .= "\tauto " . $param->getName() . "_ = dyn_cast<Git2Resource>(" . $param->getName() . ");\n";
                } else if ($hackType == HackType::STRING && $param->getType()->getType() == "git_oid") {
                    $body .= "\tif (git_oid_fromstr(&" . $param->getName() . "_, " . $param->getName() . ".c_str()) != GIT_OK) {\n";
                    $body .= "\t\tconst git_error *error = giterr_last();\n";
                    $body .= "\t\tSystemLib::throwInvalidArgumentExceptionObject(error ? error->message : \"no error message\");\n";
                    $body .= "\t}\n";
                }
            }
            
            $body = rtrim($body) . "\n\n";
            
            /* Build call of libgit function, only assign result if return-type of libgit function ins't void */
            $body .= "\t". ($returnType->typeToHackType() != HackType::VOID && ($function->getReturnType()->getType() == "int" || !$hasOutValue) ? "result = " : "") . $function->getName() . "(";
            foreach ($function->getParams() as $k => $param) {
                $hackType = $param->getType()->typeToHackType();
                
                if ($k == 0 && $hasOutValue) {
                    $body .= ($outValPointerLvl >= 1 ? "&" : "") . $param->getName() . ", ";
                    continue;
                }
                
                if ($param->getPointerLvl() > 1) {
                    $body .= $param->getName() . "_";
                } else {
                    switch ($hackType) {
                        case HackType::BOOL : $body .= $param->getName(); break;
                        default :
                            switch ($hackType) {
                                case HackType::INT :
                                case HackType::FLOAT :
                                    $body .= "(" . $param->getType()->getType() . ($param->getPointerLvl() > 0 ? "*" : "") . ") " . $param->getName(); break;
                                case HackType::STRING :
                                    if ($param->getType()->getType() == "git_oid") {
                                        $body .= "&" . $param->getName() . "_";
                                    } else if ($param->isConstant()) {
                                        $body .= $param->getName() . ".c_str()";
                                    } else {
                                        $body .= $param->getName() . ".mutableData()";
                                    }
                                    break;
                                case HackType::RESOURCE :
                                    $body .= "HHVM_GIT2_V(" . $param->getName() . "_, " . preg_replace("/^git_/", "", $param->getType()->getType()) . ")"; break;
                                case HackType::CALLABLE :
                                    $body .= "/* todo */ " . $param->getName() . "_";break;
                                case HackType::VOID :
                                    $body .= $param->getName() . "_";break;
                                default : break;
                            }
                            break;
                    }
                }
                

                $body .= ", ";
            }
            $body = rtrim(rtrim($body), ",") . ");\n";
            
            /*
             * if error occurs throw an exception (todo depends on function maybe return null)
             */
            if ($function->getReturnType()->getType() == "int" && !preg_match("/(cmp|_foreach_)/", $function->getName())) {
                if (preg_match("/_next$/", $function->getName())) {
                    $body .= "\n\tif (result == GIT_ITEROVER) {\n" .
                    	"\t\t/* todo return nullptr */\n" .
                    	"\t\tconst git_error *error = giterr_last();\n" .
                    	"\t\tSystemLib::throwInvalidArgumentExceptionObject(error ? error->message : \"no error message\");\n" .
						"\t} else ";
                } else {
                    $body .= "\n\t";
                }
				
                if (in_array($function->getName(), $funcList) || preg_match("/(?:count|_prettify)$/", $function->getName())) {
                    $body .= "if (result < 0) {\n";
                } else {
                	$body .= "if (result != GIT_OK";
					
					if (in_array($function->getName(), $funcList2) || preg_match("/_(?:(?:is|has|exists|valid|matches)(?:_|$))/", $function->getName())) {
						$body .= " && result != 1";
					}
					
					$body .= ") {\n";
                }
                
                $body .= "\t\tconst git_error *error = giterr_last();\n" .
                	"\t\tSystemLib::throwInvalidArgumentExceptionObject(error ? error->message : \"no error message\");\n" .
                	"\t}\n\n";
            }
            
            /*
             * Cast type of result/out value to required type of return_value
             * not needed if returnType of hhvm function is void
             */
            $hackType = $returnType->typeToHackType();
            if ($hackType != HackType::VOID) {
                switch ($hackType) {
                    /* Never become HackType::VOID because of if-statment */
                    case HackType::VOID :
                        $body .= "\treturn_value = "; break;
                    /* No cast needed for bool value */
                    case HackType::BOOL :
                        $body .= "\treturn_value = "; break;
                    /* Need to be changed for unsigned int with more than 32 bit */
                    case HackType::INT :
                        $body .= "\treturn_value = ";
                        $body .= "(int64_t)";
                        $body .= " " . ($hasOutValue ? $function->getParams()[0]->getName() : "result") . ";\n"; break;
                    case HackType::FLOAT :
                        $body .= "\treturn_value = ";
                        $body .= "(double)";
                        $body .= " " . ($hasOutValue ? $function->getParams()[0]->getName() : "result") . ";\n"; break;
                    case HackType::STRING :
                        if (!$hasOutValue && $function->getReturnType()->getType() == "git_oid") {
                            $body .= "\tgit_oid_fmt(return_value, result);\n";
                        } else if ($hasOutValue && $function->getParams()[0]->getType()->getType() == "git_oid") {
                            $body .= "\tgit_oid_fmt(return_value, " . ($outValPointerLvl > 1 ? "" : "&") . $function->getParams()[0]->getName() . ");\n";
                        } else {
                            $body .= "\treturn_value = ";
                            $body .= "String(" . ($hasOutValue ? ($outValPointerLvl > 1 ? "" : "&") . $function->getParams()[0]->getName() : ($function->getPointerLvl() == 0 ? "&" : "") . "result") . ");\n";
                        } break;
                    case HackType::ARR :
                        $body .= "\treturn_value = ";
                        $body .= "ARR";
                        $body .= " " . ($hasOutValue ? $function->getParams()[0]->getName() : "result") . ";\n"; break;
                    case HackType::RESOURCE :
                        $body .= "\t";
                        
                        if (($hasOutValue && $function->getParams()[0]->isConstant()) || (!$hasOutValue && $function->isConstant())) {
                            $body .= "//";
                        }
                        
                        $body .= "HHVM_GIT2_V(return_value, " . preg_replace("/^git_/", "", ($hasOutValue ? $function->getParams()[0]->getType()->getType() : $function->getReturnType()->getType())) . ") = ";
                        
                        if ($hasOutValue) {
                            $body .= ($outValPointerLvl > 1 ? "" : "&") .  $function->getParams()[0]->getName() . ";";
                        } else {
                            $body .= "result;";
                        }
                        
                        if (($hasOutValue && $function->getParams()[0]->isConstant()) || (!$hasOutValue && $function->isConstant())) {
                            $body .= " todo return as array";
                        }
                        
                        $body .= "\n"; break;
                    case HackType::CALLABLE :
                        $body .= "\treturn_value = ";
                        $body .= "CALLABLE";
                        $body .= " &" . ($hasOutValue ? $function->getParams()[0]->getName() : "result") . ";\n"; break;
                }
                
                if ($hackType == HackType::RESOURCE) {
                    $body .= "\treturn Resource(return_value);\n";
                } else if ($hackType == HackType::STRING &&
                           ((!$hasOutValue && $function->getReturnType()->getType() == "git_oid") ||
                            ($hasOutValue && $function->getParams()[0]->getType()->getType() == "git_oid") )) {
                    $body .= "\treturn String(return_value);\n";
                } else {
                    $body .= "\treturn return_value;\n";
                }
            }
            
            $body .= "}\n";
        }
        
        $this->add($body);
    }
}
