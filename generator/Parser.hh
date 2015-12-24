<?hh

require_once 'Func.hh';
require_once 'Type.hh';
require_once 'Parameter.hh';

class Parser {
    
    /**
     * parse the file with the given filenName for constants
     * and return their names and associated values as array
     *
     * @param $fileName - name of the file to be loaded
     *
     * @return array<string, array<string, string>>
     */
    public function parseConstants(string $fileName): array<string, array<string>> {
        $fileContent = file_get_contents(dirname(__FILE__)."/../libgit2/include/git2/".$fileName);
        $result = array();
        
        /**
         * @var $pattern string - pattern to parse constants in file like this:
         *   typedef enum {
         *       <content>
         *   } git_blame_flag_t;
         */
        $pattern = "/\n[ \t]*?typedef[\s]+enum[\s]*[\w]*[\s]*{([\s\S]*?)}[\s]+([\w]+?);/";
        
        /** @var $pattern2 - pattern to parse constant name and value */
        $pattern2 = "/\n[\s]*(?:\/\*\*[\s\S]\*\/)*[\s]*([A-Z_][A-Z0-9_]*)[\s]*(?:=[\s\S]*?)?(?:,|$)/";
        
        $match = array();
        
        if (preg_match_all($pattern, $fileContent, $match)) {
            $cnt = count($match[0]);
            
            for ($i = 0; $i < $cnt; $i++) {
                $enumName = $match[2][$i];
                $constants = array();
                
                $content = $match[1][$i];
                $match2 = array();
                
                if (preg_match_all($pattern2, $content, $match2)) {
                    $cnt2 = count($match2[0]);
                    
                    for ($j = 0; $j < $cnt2; $j++) {
                        $constants[] = (string)$match2[1][$j];
                    }
                }
                
                $result[$enumName] = $constants;
            }
        }
        
        return $result;
    }
    
    
    /**
     * @param $fileName - name of the file to be loaded
     *
     * @return array<string>
     */
    public function parseStructs(string $fileName): array<string> {
        $fileContent = file_get_contents(dirname(__FILE__)."/../libgit2/include/git2/".$fileName);
        $result = array();
        
        $pattern = "/\n?[ \t]*typedef[\s]+struct[\s]+([\w]+)[\s]*(?:{(?:[\s\S]*)})?[\s]*((?:[\w]+[\s]*,[\s]*)*?[\w]+)?[\s]*;/";
        $match = array();
        
        if (preg_match_all($pattern, $fileContent, $match)) {
            $cnt = count($match[0]);
            
            for ($i = 0; $i < $cnt; $i++) {
                $name = $match[2][$i];
                
                $result[] = $name;
            }
        }
        
        return $result;
    }
    
    
    /**
     * @param $fileName - name of the file to be loaded
     *
     * @return array<Func>
     */
    public function parseFunctions(string $fileName): array<Func> {
        $fileContent = file_get_contents(dirname(__FILE__)."/../libgit2/include/git2/".$fileName);
        $result = array();
        
        $pattern = "/\nGIT_EXTERN\((.+?)\)\s*([a-zA-Z0-9_-]+)\(([\S\s]+?)\);/";
        $match = array();
        
        if (preg_match_all($pattern, $fileContent, $match)) {
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
                
                $result[] = $function;
            }
        }
        
        return $result;
    }
    
    
    public function parseCallbacks(string $fileName): array<string> {
        
        $fileContent = file_get_contents(dirname(__FILE__)."/../libgit2/include/git2/".$fileName);
        $result = array();
        
        // todo create pattern to parse callbacks
        $pattern = "/\nGIT_EXTERN\((.+?)\)\s*([a-zA-Z0-9_-]+)\(([\S\s]+?)\);/";
        $match = array();
        
        if (preg_match_all($pattern, $fileContent, $match)) {
            $cnt = count($match[0]);
        }
        
        return $result;
    }
}