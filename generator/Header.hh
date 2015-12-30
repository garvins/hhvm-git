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
    
    public function add2Functions(Func $function) : this {
        if (is_array($this->functions)) {
            $this->functions[] = $function;
        } else {
            $this->functions = array($function);
        }
        
        return $this;
    }
    
    protected function printDefines() : void { }
    
    protected function printIncludes() : void { }
    
    protected function printBody() : void {
        $body = "";
        
        foreach ($this->functions as $function) {
            if (count($function->getParams()) && preg_match("/out/" ,$function->getParams()[0]->getName())) {
                $returnType = $function->getParams()[0]->getType()->getHHVMReturnType();
            } else {
                $returnType = $function->getReturnType()->getHHVMReturnType();
            }
            
            $body .= "\n";
            $body .= $returnType." HHVM_FUNCTION(".$function->getName().",";
            
            foreach ($function->getParams() as $k => $param) {
                if($k == 0 && preg_match("/out/" ,$param->getName())) {
                    continue;
                }
                
                $body .= "\n\t" . $param->getType()->getHHVMType() . str_repeat("*", $param->getPointerLvl()) . " " .  $param->getName() .",";
            }
            
            $body = rtrim($body, ",");
            $body .= ");\n";
        }
        
        $this->add(rtrim($body, ""));
    }
}
