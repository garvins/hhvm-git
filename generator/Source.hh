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
        $body = "";
        
        foreach ($this->functions as $function) {
            $hasOutValue = false;

            if (count($function->getParams()) && preg_match("/out/" ,$function->getParams()[0]->getName())) {
                $returnType = $function->getParams()[0]->getType();
                $hasOutValue = true;
            } else {
                $returnType = $function->getReturnType();
            }
            
            $body .= "\n";
            $body .= $returnType->getHHVMReturnType() ." HHVM_FUNCTION(".$function->getName().",";
            
            foreach ($function->getParams() as $k => $param) {
                if($k == 0 && preg_match("/out/" ,$param->getName())) {
                    continue;
                }
                
                $body .= "\n\t" . $param->getType()->getHHVMType() . str_repeat("*", $param->getPointerLvl()) . " " .  $param->getName() .",";
            }
            
            $body = rtrim($body, ",");
            $body .= ")\n{";
            
            if ($returnType->typeToHackType() != HackType::VOID) {
            	$body .= "\n\t" . $function->getReturnType()->getType() . " result;\n";
            	$body .= "\t" . $returnType->getHHVMReturnType() . " return_value;\n";
            }
            
            /*
            foreach ($function->getParams() as $param) {
                if ($param->getType()->typeToHackType() == HackType::RESOURCE) {
                    $body .= "\t" . $param->getType()->getType() . " _" . $param->getName() . ";\n";
                }
            }*/
            
            // todo only assign to result if return type isnt void
            $body .= "\n\t". ($returnType->typeToHackType() != HackType::VOID ? "result = " : "") . $function->getName() . "(";
            
            foreach ($function->getParams() as $param) {
                $body .= $param->getName() .", ";
            }
            
            $body = rtrim(rtrim($body), ",");
            
            $body .= ")\n}\n";
        }
        
        $this->add(rtrim($body, ""));
    }
}
