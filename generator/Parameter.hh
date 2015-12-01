<?hh

require_once 'Type.hh';

class Parameter {
    private string $name = "";
    private ?Type $type;

    public function getName() : string {
        return $this->name;
    }
    
    public function getType() : ?Type {
        return $this->type;
    }
    
    public function setName(string $name) : this {
        $this->name = $name;
        return $this;
    }
    
    public function setType(Type $type) : this {
        $this->type = $type;
        return $this;
    }
}
