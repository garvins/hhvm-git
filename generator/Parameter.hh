<?hh

require_once 'Type.hh';

class Parameter {
    private string $name = "";
    private Type $type;
    private bool $constant = false;
    private int $pointerLvl = 0;
    
    public function __construct(string $name) {
        $this->name = $name;
        $this->type = new Type("void");
    }

    public function getName() : string {
        return $this->name;
    }
    
    public function getType() : Type {
        return $this->type;
    }
    
    public function getPointerLvl() : int {
        return $this->pointerLvl;
    }
    
    public function isConstant() : bool {
        return $this->constant;
    }
    
    public function setName(string $name) : this {
        $this->name = $name;
        return $this;
    }
    
    public function setType(Type $type) : this {
        $this->type = $type;
        return $this;
    }
    
    public function setConstant(bool $constant) :this {
        $this->constant = $constant;
        return $this;
    }
    
    public function setPointerLvl(int $pointerLvl) :this {
        $this->pointerLvl = $pointerLvl;
        return $this;
    }
}
