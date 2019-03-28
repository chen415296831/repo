/***********************************************

    Filename: main.cpp
    Author: 
    Description:
    Create Data:    2019-03-27 14:28:17
    Modfiy History: 2019-03-27 14:28:17

***********************************************/
#include "BinaryTree.h"

void printValue(int a)
{
	std::cout << a << '\t';
}
int main()
{
    Seed();
    BinaryTree<int> iTree;
    for(int i = 0; i < 10; i++)
        iTree.insert(i);
	auto vistFunc = [](int a) { std::cout << a << '\t'; };
	iTree.RecrPreTrav(printValue);
	iTree.PreTrav();
	iTree.RecrMidTrav(printValue);
	iTree.MidTrav();
	iTree.RecrNxtTrav(printValue);
	iTree.NxtTrav();
    return 0;

}
