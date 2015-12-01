<?hh

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
    
    protected function printDefines() {
        
    }
    
    protected function printIncludes() {
        $this->add("#include \"". $this->fileName .".h\"");
    }
    
    protected function printBody() {
        foreach ($functions as $function) {
            
        }
    }
}
