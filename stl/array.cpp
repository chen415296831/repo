#include <iostream>
#include <array>
#include <memory>

/*
 *array的存在是为了解决new 出来的数组忘记释放的内存泄露问题
 *
 */
int main()
{
	//array模板类构造函数,既然是个数字，必须制定其大小
	//template< 
	//    class T, 
	//    std::size_t N 
	//> struct array;	

	std::array<int, 10> nums = { 1, 2, 4};
	nums[3] = 3;
	for(int& ele : nums)
		std::cout << ele << " " ; 
	std::cout << std::endl;

	int* rawPtr = new int[10];
	rawPtr[0] = 10;
	//g++ use -fsanitize=leak check memroy leak
	delete[] rawPtr;

	//使用智能指针也可以自动释放内存，但没有array看着那么直接
	std::shared_ptr<int[10]> smartPtr = std::make_shared<int[10]>();
	smartPtr[0] = 11;
	std::cout << smartPtr[0] << std::endl;

	
}
