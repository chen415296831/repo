/***********************************************

    Filename: BinaryTree.cpp
    Author: 
    Description:
    Create Data:    2019-03-27 13:35:00
    Modfiy History: 2019-03-27 13:35:00

***********************************************/
#include <time.h>
#include <stdlib.h>
#include "BinaryTree.h"

void Seed()
{
    time_t secondSinceEpoch;
    time(&secondSinceEpoch);
    srand(secondSinceEpoch);
}

int Guide()
{
    return rand() % 2;
}



