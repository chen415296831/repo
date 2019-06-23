#include <cassert>
#include <set>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
//template<
//    class Key,	//元素类型
//    class Compare = std::less<Key>,	//std::less，元素值较小的在前，我们可以替换成greater
//    class Allocator = std::allocator<Key>
//> class set;
int main()
{
	set<int> values_;
	values_.insert(3);
	values_.insert(5);
	values_.insert(2);
	values_.insert(-1);

	//红黑树，中序遍历，begin就是最小的，越往后越大
	for(auto& v : values_)
		std::cout << v << " ";
	std::cout << std::endl;
	
	//顺序反过来
	set<int, greater<int>>  rvalues_(values_.begin(), values_.end());
	for(auto& v : rvalues_)
		std::cout << v << " ";
	std::cout << std::endl;

	set<pair<int, string>> pairs;

	//pair的operators
	//当且仅当两个pair的first,second都相等，两个pair才相等
	//比较大小，先比较first, 能从first判决出孰大孰小，比较结束
	//如果first相等，继续比较second的大小
	pairs.insert(make_pair<int,string>(1, "a"));
	pairs.insert(make_pair<int,string>(2, "a"));
	pairs.insert(make_pair<int,string>(1, "c"));
	std::cout << "pairs.size() " << pairs.size() << endl;

	//
	values_.erase(values_.begin(), values_.end());	//等价于vaules_.clear;
	values_.insert(1);
	values_.insert(2);
	values_.insert(3);
	values_.insert(4);
	values_.insert(5);
	//lower_bound 返回首个不小于(x)的元素,也就是说返回的迭代器等于(x)
	set<int>::const_iterator lower = values_.lower_bound(2);
	assert(*lower == 2);
	//upper_bound 返回首个大于(x)的元素
	//!!! 通过我们上下界lower, upper的值，我们可以获得一个左闭右开[lower, upper)的空间
	//这也是stl世界用两个迭代器表示范围的管用手法
	set<int>::const_iterator upper = values_.upper_bound(4);
	assert(*upper == 5);

	vector<int> array;
	std::copy(lower, upper, back_inserter(array));
	assert(array.size() == 3);


}
