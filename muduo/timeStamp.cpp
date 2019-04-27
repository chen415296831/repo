#include <muduo/base/Timestamp.h>
#include <iostream>


int main()
{
	char buf[30] = {0};
	time_t seconds = 142442424;
	time_t mircoseconds = 12345678;
	muduo::Timestamp timestamp = muduo::Timestamp::now();
	std::cout << timestamp.toString() << std::endl;
	snprintf(buf, sizeof(buf) - 1, "%" "l" "d" ".%6" "l""d" "", seconds, mircoseconds);
	std::cout << buf << std::endl;
}
