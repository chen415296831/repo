#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int> > v2;
	for(size_t c = 0; c < nums.size() -2; c++)
	{
		for(size_t b = c + 1; b < nums.size() - 1; b ++ )
		{
			for(size_t a = c + 2; c < nums.size(); c++)
			{
				if(nums[a] + nums[b] + nums[c] == 0)
					v2.push_back({nums[a], nums[b], nums[c]});
			}
		}
	}

	return v2;
}

int main()
{
}
