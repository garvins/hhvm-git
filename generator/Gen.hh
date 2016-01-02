<?hh //strict

require_once 'Header.hh';
require_once 'Source.hh';

class Gen {
    
    public function __construct() {
    }
    
    public function postUnkownTypes(): void {
        foreach (Type::$unknownTypes as $type) {
            echo $type ."\n";
        }
    }
    
    public function generateFuncFiles(array<string, array<Func>> $fileFuncList): void {
        foreach ($fileFuncList as $file => $functions) {
            $header = new Header(preg_replace("/\.[\s\S]*/", "", $file));
            $header->setFunctions($functions);
            $header->print(true);
            
            $source = new Source(preg_replace("/\.[\s\S]*/", "", $file));
            $source->setFunctions($functions);
            $source->print();
        }
    }
    
    public function generateSysLib(array<string, array<string, array<string>>> $enums): void {
        if ($handle = opendir(dirname(__FILE__)."/../src")) {
            $pattern = "/(\w+) HHVM_FUNCTION\((\w+),((?:\s*(?:const \w+&|\w+)\s*\**\w+(?:,\n|\);))*)/";
            $ignore = "/([^h]|[^\.]h)$/";
            $content = "<?hh\n";
            
            $content2 = "#include \"hphp/runtime/base/base-includes.h\"\n\n";
            $content2 .= "namespace HPHP {\n\n";
            $content2 .= "#define REG_SAME_CONST(name) HHVM_RC_INT(name, k_ ## name);\n\n";
            $content2 .= "static class Git2Extension : public Extension  {\n";
            $content2 .= "  public:\n";
            $content2 .= "    Git2Extension() : Extension(\"git2\") {}\n";
            $content2 .= "    virtual void moduleInit() {\n";
            
            while (false !== ($entry = readdir($handle))) {
                if (!preg_match($ignore, $entry)) {
                    $match = array();
                    $file = file_get_contents(dirname(__FILE__)."/../src/".$entry);
                    
                    if (preg_match_all($pattern, $file, $match)) {
                        $content .= "\n\n// --------------- ". $entry . " ---------------\n";
                        
                        $content2 .= "\n\n      // --------------- ". $entry . " ---------------\n";
                        
                        foreach ($match[3] as $k => $v) {
                            $v = rtrim($v, ';)');
                            $v = explode(",\n", $v);
                            
                            $content .= "\n<<__Native>>\n";
                            $content .= "function ".$match[2][$k]."(";
                            $size = 10 + strlen($match[2][$k]);
                            
                            foreach ($v as $k1 => $v1) {
                                if($k1 > 0) {
                                    $content .= ",\n" . str_repeat(" ", $size);
                                }
                                
                                $match2 = array();
                                
                                if (preg_match("/^([\s\S]+?)\s+\**(\w+)$/", $v1, $match2)) {
                                    $content .= Type::hhvmTypeToHack(trim($match2[1]))." $".$match2[2];
                                } else {
                                    $content .= "ERROR";
                                }
                            }
                            
                            $content .= "): ". Type::hhvmTypeToHack(trim($match[1][$k])) . ";\n";
                            
                            $content2 .= "      HHVM_FE(". $match[2][$k] .");\n";
                        }
                    }
                }
            }
            
            
            $content2 .= "\n\n      /*            ---- CONSTANTS ----\n";
            $content2 .= "       * register constants of all known enums in libgit2\n";
            $content2 .= "       * todo: register only necessary constants!!!\n";
            $content2 .= "       */\n";
            
            /* add constants to register file */
            foreach ($enums as $name => $enum) {
                if (count($enum) > 0) {
                    $content2 .= "\n\n      // --------------- ". $name . " ---------------\n";
                    
                    foreach ($enum as $enumName => $constants) {
                        $content2 .= "\n      // --------------- ". $enumName . " ---------------\n";
                        
                        foreach ($constants as $constant) {
                            $content2 .= "      REG_SAME_CONST(". $constant . ");\n";
                        }
                    }
                }
            }
            
            closedir($handle);
            
            $content2 .= "\n\n      loadSystemlib();\n";
            $content2 .= "  }\n";
            $content2 .= "} s_git2_extension;\n\n";
            $content2 .= "HHVM_GET_MODULE(git2)\n} // namespace HPHP\n";
            
            file_put_contents(dirname(__FILE__)."/../ext_git2.cpp", $content2);
            file_put_contents(dirname(__FILE__)."/../ext_git2.php", $content);
        }
    }
}