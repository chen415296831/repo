#define BOOST_ERROR_CODE_HEADER_ONLY
#define BOOST_CHRONO_HEADER_ONLY
#define BOOST_CHRONO_EXTENSIONS
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <iostream>

int main()
{
	//duration的认识，duration<class Rep, class Period = ratio>
	//duration 有Rep类型的成员变量，存储时间长度，时间长度是 Rep * ration
	//Rep可以是int,float,double，如果是浮点数，可以表示小数的ration
	//
	boost::chrono::minutes  m(1);
	boost::chrono::seconds  s(5);
	std::cout << m << std::endl;

	//大的ration可以赋值给小的ration,大ration向小ratio转换不会产生小数
	s += m;
	std::cout << s << std::endl;

	//小ratio向大ration赋值就不可以
	//m += s;
	boost::chrono::process_real_cpu_clock cpu_time;

	std::cout << cpu_time.now() << std::endl;
	std::cout << "hello world" << std::endl;
	std::cout << cpu_time.now() << std::endl;


	boost::chrono::system_clock sysclock;
	std::cout << sysclock.now() << std::endl;

	boost::chrono::steady_clock stclock;
	std::cout << stclock.now().time_since_epoch() << std::endl;

}

