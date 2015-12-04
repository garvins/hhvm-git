<?hh

abstract class Printer {
    protected string $fileName = "";
    protected string $fileType = "";
    private string $content = "";
    
    private function printLicense() {
        $this->add("/*");
        $this->add(" * Copyright (C) the hhvm-git contributors. All rights reserved.");
        $this->add(" *");
        $this->add(" * This file is part of hhvm-git, distributed under the GNU GPL v2 with");
        $this->add(" * a Linking Exception. For full terms see the included LICENSE file.");
        $this->add(" */\n");
    }
    
    private function printStartIfDef() {
        $this->add("#ifndef HHVM_GIT2_". strtoupper($this->fileName) ."_H");
        $this->add("#define HHVM_GIT2_". strtoupper($this->fileName) ."_H\n");
    }
    
    private function printEndIfDef() {
        $this->add("#endif\n");
    }
    
    private function writeToFile() {
        file_put_contents(dirname(__FILE__)."/../".$this->fileName.".".$this->fileType, $this->content);
    }
    
    public function add(string $text) {
        $this->content .= $text . "\n";
    }
    
    public function print(bool $printIfDef = false) {
        $this->printLicense();
        
        if ($printIfDef) {
            $this->printStartIfDef();
        }
        
        $this->printDefines();
        $this->printIncludes();
        $this->printBody();
        
        if ($printIfDef) {
            $this->printEndIfDef();
        }
        
        $this->writeToFile();
    }
    
    abstract protected function printDefines();
    
    abstract protected function printIncludes();
    
    abstract protected function printBody();
}