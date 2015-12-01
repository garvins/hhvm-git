<?hh

class Type {
    private string $type = "";
    
    public function getType() : string {
        return $this->type;
    }
    
    public function setType($type) : this {
        $this->type = $type;
        return $this;
    }
}
