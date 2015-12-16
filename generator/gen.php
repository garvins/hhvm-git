<?hh

require_once 'Parameter.hh';
require_once 'Source.hh';
require_once 'Header.hh';
require_once 'Type.hh';
require_once 'Func.hh';

$generator = new Gen();
$generator->create($_SERVER['argv']);

class Gen {
    private array<string, string> $files = array();
    
    public function __construct() {
        $match = array();
        
        $git2_h = (string) file_get_contents(dirname(__FILE__)."/../libgit2/include/git2.h");
        
        if (preg_match_all("/#include \"[^\"]+\/([^\"]+?)\"/", $git2_h, $match)) {
            foreach ($match[1] as $v) {
                $this->files[$v] = "../libgit2/include/git2/".$v;
            }
        }
    }
    
    public function create(array<string> $argv): void {
        if ($argv[1] == "syslib") {
            $this->generateSysLib();
        } else if ($argv[1] == "all") {
			foreach ($this->files as $file => $path) {
                $this->generateFuncFiles($file);
            }
            
            $this->generateSysLib();
        } else if (isset($this->files[$argv[1]])) {
            $this->generateFuncFiles($argv[1]);
        }
        
        $this->postUnkownTypes();
    }
    
    private function postUnkownTypes() {
        foreach (Type::$unknownTypes as $type) {
            echo $type ."\n";
        }
    }
    
    private function generateFuncFiles(string $inputFile): void {
        $functions = array();
        $match = array();
        $file = file_get_contents(dirname(__FILE__)."/../libgit2/include/git2/".$inputFile);
        
        if (preg_match_all("/\nGIT_EXTERN\((.+?)\)\s*([a-zA-Z0-9_-]+)\(([\S\s]+?)\);/", $file, $match)) {
            $cnt = count($match[0]);
            
            for ($i = 0; $i < $cnt; $i++) {
                $function = new Func($match[2][$i]);
                
                $typeName = $match[1][$i];
                $typeName = preg_replace("/const /", "", $typeName);
                $typeName = str_replace("*", "", $typeName);
                $typeName = str_replace(" ", "", $typeName);
                $function->setReturnType(new Type($typeName));
                $params = explode(",", $match[3][$i]);
                
                foreach ($params as $param) {
                    $param = trim($param);
                    $pos = strrpos($param, " ");
                    $pointerLvl = 0;
                    
                    $parameter = new Parameter(trim(str_replace("*", "" , substr($param, $pos), $pointerLvl)));
                    
                    $typeName = str_replace("*", "", substr($param, 0, $pos), $pointerLvl);
                    $typeName = preg_replace("/const /", "", $typeName);
                    $parameter->setType(new Type($typeName));
                    $parameter->setPointerLvl($pointerLvl);
                    $parameter->setConstant(strpos($param, "const") ? true : false);
                    
                    $function->add2Params($parameter);
                }
                
                $functions[] = $function;
            }
        }
        
        $header = new Header(preg_replace("/\.[\s\S]*/", "", $inputFile));
        $header->setFunctions($functions);
        $header->print(true);
        
        $source = new Source(preg_replace("/\.[\s\S]*/", "", $inputFile));
        $source->setFunctions($functions);
        $source->print();
    }
    
    private function generateSysLib(): void {
        if ($handle = opendir(dirname(__FILE__)."/../src")) {
            $pattern = "/([\w]+) HHVM_FUNCTION\(([\w]+), ((?:(?:const [\w]+&|[\w]+)[\s]*[\w]+(?:,\n|\);))*)/";
            $ignore = "/([^h]|[^\.]h)$/";
            $content = "<?hh\n";
            
            $content2 = "#include \"hphp/runtime/base/base-includes.h\"\n\n";
            $content2 .= "namespace HPHP {\n\n";
            $content2 .= "static class Git2Extension : public Extension  {\n";
            $content2 .= "  public:\n";
            $content2 .= "    Git2Extension() : Extension(\"git2\") {}\n";
            $content2 .= "    virtual void moduleInit() {\n";
            
            while (false !== ($entry = readdir($handle))) {
                if (!preg_match($ignore, $entry)) {
                    $match = array();
                    $file = file_get_contents(dirname(__FILE__)."/../src/".$entry);
                    
                    $content .= "\n\n// --------------- ". $entry . " ---------------\n";
                    
                    $content2 .= "\n      // --------------- ". $entry . " ---------------\n";
                    
                    if (preg_match_all($pattern, $file, $match)) {
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
                                preg_match_all("/^([\s\S]+?)[\s]+([\w]+)$/", $v1, $match2);
                                if (isset($match2[1][0])) {
                                    $content .= Type::hhvmTypeToHack($match2[1][0])." $".$match2[2][0];
                                } else {
                                    $content .= "ERROR";
                                }
                            }
                            
                            $content .= "): ". Type::hhvmTypeToHack($match[2][$k]) . ";\n";
                            
                            $content2 .= "      HHVM_FE(". $match[2][$k] .");\n";
                        }
                    }
                }
            }
            
            closedir($handle);
            
            $content2 .= "      loadSystemlib();\n";
            $content2 .= "  }\n";
            $content2 .= "} s_git2_extension;\n\n";
            $content2 .= "HHVM_GET_MODULE(git2)\n} // namespace HPHP\n";
            
            file_put_contents(dirname(__FILE__)."/../ext_git2.cpp", $content2);
            file_put_contents(dirname(__FILE__)."/../ext_git2.php", $content);
        }
    }
}