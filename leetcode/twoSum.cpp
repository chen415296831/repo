#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <boost/assert.hpp>

using namespace std;

vector<int> nums = {2, 7, 11, 15};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> patern; 
        int idx = 0;
        for(int v : nums)
            patern.insert(make_pair(v, idx++));
        idx = nums.size(); 
        for(int i = 0; i< idx; i++)
        {
            auto it = patern.find(target-nums[i]);
            if( it != patern.end() && it->second != i)
                return {i, it->second};
        }
         
        return {};
    }
};

 int target = 9;
int main()
{
	vector<int> result = {0,1};
	vector<int> a = Solution().twoSum(nums, target);
	BOOST_ASSERT(result == a);
}
