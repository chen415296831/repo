#include <stdint.h>
#include <assert.h>


class Solution
{
public:
	int reverse(int x)
	{
		int result = 0;
		bool nagative = x < 0 ? 1 : 0;
		x = nagative ? -x : x;

		if(x & 0x80) return 0;
		while(x>0)
		{
			int mod =  x & 0xf;
			result = (result << 4) + mod;
			//说的是运算过程中
			x = x /10;
		}
		return nagative ? -result : result;
	}
};

int main()
{
	Solution s;
	assert(s.reverse(123) == 321);
	assert(s.reverse(-123) == -321);
	assert(s.reverse(120) == 21);
	assert(s.reverse(INT32_MAX) == 0);
	assert(s.reverse(INT32_MIN) == 0);
}
