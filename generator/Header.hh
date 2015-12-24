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
            $body .= "\n";
            $body .= $function->getReturnType()->getHHVMReturnType()." HHVM_FUNCTION(".$function->getName().",";
            
            foreach ($function->getParams() as $k => $param) {
                $body .= "\n\t" . $param->getType()->getHHVMType() . str_repeat("*", $param->getPointerLvl()) . " " .  $param->getName() .",";
            }
            
            $body = rtrim($body, ",");
            $body .= ");\n";
        }
        
        $this->add(rtrim($body, ""));
    }
}
