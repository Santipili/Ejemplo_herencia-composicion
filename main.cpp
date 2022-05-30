#include <iostream>
#include "./lib/folder.h"
#include "./lib/file.h"
#include "./lib/listable-composable.h"

int main()
{
    iComposable* folder_01 = new iFolder("folder_01");
    iComposable* folder_02 = new iFolder("folder_02");
    folder_01->add(folder_02);

    iComposable* folder_03 = new iFolder("folder_03");
    iListable* fileA = new iFile("fileA");
    folder_03->add(fileA);
    folder_03->add(new iFile("fileB"));

    folder_02->add(folder_03);

    
    folder_01->list(1);

    delete folder_03;
    delete folder_02;
    delete folder_01;
    return 0;
}