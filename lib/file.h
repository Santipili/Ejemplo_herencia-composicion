#pragma once
#include "./listable-composable.h"
#include <iostream>

class iFile : public iListable {
    private:
    std::string name;
    std::vector<iListable*> content;

    public:
    void list(int deph);
    iFile(std::string nodeName);
    ~iFile();
};

iFile::iFile(std::string nodeName){
    name = nodeName;
}
iFile::~iFile(){

}

void iFile::list(int depth){
    std::string newStr(depth, '-');
    std::cout << newStr << name << " depth: " << depth << std::endl;
    for(std::vector<iListable*>::const_iterator it = content.begin(); it != content.end(); ++it)
    {
        if(*it != 0)
        {
            (*it)->list(depth + 1);
        }
    }
}