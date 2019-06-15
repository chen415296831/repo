#include <chrono>
#include <thread>
#include <ctime>
#include <ratio>
#include <iostream>

typedef std::chrono::duration<float,std::ratio<1> > fsecond;

int main()
{

	//std::this_thread::sleep_for(fsecond(2.12));
	//
	
	std::chrono::system_clock::time_point now  = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point after = now + std::chrono::seconds(2);

	std::this_thread::sleep_until(after);

	auto hres = std::chrono::high_resolution_clock::now();

	std::cout << hres.time_since_epoch().count() << std::endl;

	auto sysclock = std::chrono::steady_clock::now();

	std::cout << sysclock.time_since_epoch().count() << std::endl;

}
