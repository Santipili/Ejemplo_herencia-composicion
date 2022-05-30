#pragma once
#include <iostream>

class iListable {
    public:
    void virtual list(int depth)=0;
};

class iComposable : public iListable
{
    public:
    void virtual add(iListable* component)=0;
    void virtual remove(iListable* component)=0;
};