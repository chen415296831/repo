#include <string>
#include <iostream>

using namespace std;

class base
{
public:
	base(int v)
		:value_(v)
	{
		print();
	};
	virtual void print()
	{
		std::cout << "base" << std::endl;
	}
	int value_;
};

class derived :public base
{
public:
	derived()
		:base(1)
	{
		print();
	};
	virtual void print()
	{
		cout << "derive" << std::endl;
	}
};

int main()
{
	base b(1);
	cout << " base ctor finished "<<endl;
	derived d;
	cout << " derived ctor finished "<<endl;

}
