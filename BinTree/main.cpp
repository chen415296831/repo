/***********************************************

    Filename: main.cpp
    Author: 
    Description:
    Create Data:    2019-03-27 14:28:17
    Modfiy History: 2019-03-27 14:28:17

***********************************************/
#include "BinaryTree.h"

int main()
{
    Seed();
    BinaryTree<int> iTree;
    for(int i = 0; i < 10; i++)
        iTree.insert(i);
    return 0;

}
