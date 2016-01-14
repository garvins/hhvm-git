<?hh //strict

require_once 'Printer.hh';
require_once 'Func.hh';

class Header extends Printer {
    private array<Func> $functions = array();
    
    public function __construct(string $filename) {
        $this->fileName = $filename;
        $this->fileType = "h";
    }
    
    public function getFunctions() : array<Func> {
        return $this->functions;
    }
    
    public function setFunctions(array<Func> $functions) : this {
        $this->functions = $functions;
        return $this;
    }
    
    protected function printDefines() : void { }
    
    protected function printIncludes() : void {
        $this->add("#include \"../ext_git2.h\"");
    }
    
    protected function printBody() : void {
        $body = "\nusing namespace HPHP;\n";
        
        foreach ($this->functions as $function) {
            $hasOutValue = false;
            
            if(count($function->getParams()) &&
               (preg_match("/out/" ,$function->getParams()[0]->getName()) ||
                (preg_match("/_((dup|lookup|open|peel|gen_ancestor|create|next|load|rename|add_setup)($|_)|diff_[\w]*?_to_)/", $function->getName()) && count($function->getParams()) > 1))) {
                $hasOutValue = true;
                $returnType = $function->getParams()[0]->getType()->getHHVMReturnType();
            } else {
                $returnType = $function->getReturnType()->getHHVMReturnType();
            }
            
            $body .= "\n";
            $body .= $returnType . " HHVM_FUNCTION(" . $function->getName() . ",";
            
            foreach ($function->getParams() as $k => $param) {
                if ($k == 0 && $hasOutValue) {
                    continue;
                }
                
                if ($param->getPointerLvl() > 1) {
                    $body .= "\n\tconst Array& " . $param->getName() . ",";
                } else {
                    $body .= "\n\t" . $param->getType()->getHHVMType() . " " . $param->getName() . ",";
                }
            }
            
            $body = rtrim($body, ",");
            $body .= ");\n";
        }
        
        $this->add(rtrim($body, ""));
    }
}
