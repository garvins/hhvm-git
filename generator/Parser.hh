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
    public function parseConstants(string $fileContent): array<string, array<string>> {
        $result = array();
        
        /**
         * @var $pattern string - pattern to parse constants in file like this:
         *   typedef enum {
         *       <content>
         *   } git_blame_flag_t;
         */
        $pattern = "/\n[ \t]*?typedef\s+enum\s*\w*\s*{([\s\S]*?)}\s+(\w+?);/";
        
        /** @var $pattern2 - pattern to parse constant name and value */
        $pattern2 = "/\n\s*(?:\/\*\*[\s\S]\*\/)*\s*([A-Z_][A-Z0-9_]*)\s*(?:=[\s\S]*?)?(?:,|$)/";
        
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
    public function parseStructs(string $fileContent): array<string> {
        $result = array();
        
        $pattern = "/\n?[ \t]*typedef\s+struct\s+(\w*)\s*(?:{(?:[\s\S]*?)})?\s*((?:\w+\s*,\s*)*?\w+)?\s*;/";
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
    public function parseFunctions(string $fileContent): array<Func> {
        $result = array();
        
        $pattern = "/\nGIT_EXTERN\((.+?)\)\s*([a-zA-Z0-9_-]+)\(([\S\s]+?)\);/";
        $match = array();
        
        if (preg_match_all($pattern, $fileContent, $match)) {
            $cnt = count($match[0]);
            
            for ($i = 0; $i < $cnt; $i++) {
                $function = new Func($match[2][$i]);
                $pointerLvl = 0;
                $typeName = $match[1][$i];
                $function->setConstant(strpos($typeName, "const") !== false ? true : false);
                $typeName = preg_replace("/(const|unsigned)/", "", $typeName);
                $typeName = str_replace("*", "", $typeName, $pointerLvl);
                $typeName = str_replace(" ", "", $typeName);
                $function->setReturnType(new Type($typeName));
                $function->setPointerLvl($pointerLvl);
                
                
                $params = array();
                $paramsText =  $match[3][$i];
                $param = "";
                while ($pos = strpos($paramsText, ",")) {
                    $param .= substr($paramsText, 0, $pos + 1);
                    
                    $isOpen = substr_count($param, "(") - substr_count($param, ")");
                    
                    if ($isOpen == 0) {
                        $params[] = rtrim($param, ',');
                        $param = "";
                    }
                    
                    $paramsText = substr($paramsText, $pos + 1);
                }
                
                if(strlen($paramsText)) {
                    $params[] = $paramsText;
                }
                
                foreach ($params as $param) {
                    $param = preg_replace("/(\/\*[\s\S]*?\*\/)*/","",$param);
                    $param = preg_replace("/((?:\([\s\S]*?\))+\s*)$/" , "cb", $param);
                    $param = trim(preg_replace("/((^|\s)struct\s)*/","",$param));
                    
                    $param = trim($param);
                    $pos = strrpos($param, " ");
                    
                    if($pos === false) {
                        $pos = strlen($param);
                    }
                    
                    $pointerLvl = 0;
                    $tmpCount = 0;
                                        
                    $param = str_replace("[]", "", $param); // todo add handling for arrays
                    
                    $parameter = new Parameter(trim(str_replace("*", "" , substr($param, $pos), $pointerLvl)));
                    $typeName = str_replace("*", "", substr($param, 0, $pos), $tmpCount);
                    
                    $pointerLvl += $tmpCount;
                    $typeName = preg_replace("/const /", "", $typeName);
                    $parameter->setType(new Type($typeName));
                    $parameter->setPointerLvl($pointerLvl);
					$parameter->setOption((preg_match("/\w+_opt\w*/", $typeName)) ? true : false);
                    $parameter->setConstant(strpos($param, "const") !== false ? true : false);
                    
                    if (strlen($parameter->getName())) {
                        $function->add2Params($parameter);
                    }
                }
                
                $result[] = $function;
            }
        }
        
        return $result;
    }
    
    
    public function parseCallbacks(string $fileContent): array<string> {
        $result = array();
        
        // todo create pattern to parse callbacks
        $pattern = "/\n?[ \t]*typedef\s+((?:[^e]|e[^n]|[^s]|s[^t]|st[^r]|str[^u])\w*)\s+(\(\*?\w+\)|\*?\w+)\(([\s\S]+?)\);/";
        $match = array();
        
        if (preg_match_all($pattern, $fileContent, $match)) {
            $cnt = count($match[0]);
            
            for ($i = 0; $i < $cnt; $i++) {
                $callbackName = $match[2][$i];
                $callbackName = str_replace(array("*", "(", ")", " "), "", $callbackName);
                
                $params = explode(",", $match[3][$i]);
                
                $returnType = $match[1][$i];
                $returnType = preg_replace("/const /", "", $returnType);
                $returnType = str_replace(array("*", " "), "", $returnType);
                
                $result[] = $callbackName;
            }
        }
        
        return $result;
    }
}