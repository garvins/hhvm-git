<?hh

require_once 'Source.hh';
require_once 'Header.hh';
require_once 'Func.hh';

$generator = new Gen();
$generator->create($_SERVER['argv']);

class Gen {
    private array<string, string> $files = array();
    private array<Func> $functions = array();
    
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
        if (isset($this->files[$argv[1]])) {
            $match = array();
            
            $file = file_get_contents(dirname(__FILE__)."/../libgit2/include/git2/".$argv[1]);
            
            if (preg_match_all("/GIT_EXTERN\((.+?)\)\s*([a-zA-Z0-9_-]+)\((.+?)\);/s", $file, $match)) {
                $cnt = count($match[0]);
                
                for ($i = 0; $i < $cnt; $i++) {
                    $function = new Func($match[2][$i]);
                    $args = explode(",", $match[3][$i]);
                    
                    foreach ($args as $arg) {
                        $arg = trim($arg);
                        $pos = strrpos($arg, " ");
                        $key = trim(substr($arg, $pos));
                        $type = trim(substr($arg, 0, $pos));
                        
                        $param = new Parameter();
                        
                        $function->add2Params($param);
                    }
                    
                    $this->functions[] = $function;
                }
            }
            
            $header = new Header(preg_replace("/\.[\s\S]*/", "", $argv[1]));
            $header->setFunctions($this->functions);
            $header->print(true);
            
            $source = new Source(preg_replace("/\.[\s\S]*/", "", $argv[1]));
            $source->setFunctions($this->functions);
            $source->print();
        }
    }

}