#include <string>
#include <iostream>

using namespace std;
class foobase
{
public:
	foobase () {};
	virtual ~foobase() = 0;
};

//pure virtual dtor也要实现，因为析构要一直析构到最base的类
//如果不实现，就会 undefined reference to foobase::~foobase()
foobase::~foobase() {}; 
class foo : public foobase
{
public:
	foo(string& strArg, int ageArg)
		:name_(strArg),
		 age_(ageArg)
	{};
	std::string& name_;
	const int age_;
};

int main()
{
	string name = {"shuaijun" };
	string psudonym = {"nangua"};
	foo f1(name,25);
	foo f2(psudonym, 26);

	foo f3(f1); //use default copy ctor

	cout <<f1.name_ << std::endl;
	f3.name_ = "junge";
	cout <<f1.name_ << std::endl;

}
