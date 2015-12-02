<?hh

class Type {
    private string $type = "";
    
    public function __construct(string $type) {
        $this->type = $type;
    }
    
    public function getType() : string {
        return $this->type;
    }
    
    public function setType($type) : this {
        $this->type = $type;
        return $this;
    }
    
    public function getHHVMType() : string {
        return $this->type;
    }
}
