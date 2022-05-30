#pragma once
#include "./listable-composable.h"
#include <iostream>
#include <vector>
#include <algorithm>

class iFolder : public iComposable {
    private:
    std::string name;
    std::vector<iListable*> content;

    public:
    void list(int deph);
    void add(iListable* component);
    void remove(iListable* component);
    iFolder(std::string nodeName);
    ~iFolder();
};

//-------Esto iria en la otra carpeta src

iFolder::iFolder(std::string nodeName){
    name = nodeName;
}
iFolder::~iFolder(){

}

void iFolder::list(int depth){
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

void iFolder::add(iListable* component){
    content.push_back(component);
}

void iFolder::remove(iListable* component){
    content.erase(std::remove(content.begin(), content.end(), component), content.end());
    
    //aca use la biblioteca algorithm
}



