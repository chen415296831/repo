#include <vector>
#include <cassert>

//找到返回其索引；否则，返回-1
int binFind(std::vector<int>& nums, int target)
{
    std::size_t left = 0, right = nums.size()-1 , index = -1;
    while(left <= right)
    {
        std::size_t mid = (left + right)/2;
        if(nums[mid] > target) //比target大，要在[left,mid)之间查找
            right = mid - 1 ;
        else if(nums[mid] < target) 
            left = mid + 1; //在(mid, right]中查找
        else
        {
            index = mid;
            break;
        }
            
    }
    return index;
}

int main()
{
	std::vector<int> nums = {1, 3, 5, 7, 9}; //奇数个元素
	assert(binFind(nums, 1) == 0);
	assert(binFind(nums, 3) == 1);
	assert(binFind(nums, 5) == 2);
	assert(binFind(nums, 7) == 3);
	assert(binFind(nums, 9) == 4);

	nums.push_back(10);
	assert(binFind(nums, 1) == 0);
	assert(binFind(nums, 3) == 1);
	assert(binFind(nums, 5) == 2);
	assert(binFind(nums, 7) == 3);
	assert(binFind(nums, 9) == 4);
	assert(binFind(nums, 11) == 5);
}
