#include <iostream>
using std::cout;
using std::endl;


class Singleton
{
private:
	Singleton()
	{
		cout << " call constructor" << '\n';
	}
	static Singleton * _instance;
public:
	//should use thread_once 
	static Singleton* GetInstance()
	{
		if( _instance  == nullptr)
		{
			_instance = new Singleton();
		}
		return _instance;
	}	
};

Singleton*  Singleton::_instance = nullptr;

int main()
{
	Singleton* a = Singleton::GetInstance();
	Singleton* b = Singleton::GetInstance();
}

