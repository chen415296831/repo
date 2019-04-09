#include <set>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <boost/assert.hpp>

std::set<int> source = {1, 2, 3, 4, 5};
std::list<int> target = {};

int main()
{
    BOOST_ASSERT_MSG(source.size() == 5, "Size error __line__");
    std::copy_if(source.begin(), source.end(), std::back_inserter(target),[](int vaule) {return vaule > 3;});
    BOOST_ASSERT_MSG(target.size() == 2, "Size error __line__");
    std::for_each(target.cbegin(), target.cend(), [](int vaule)->void { std::cout << vaule << std::endl;});
    target.clear();
    std::copy_if(source.begin(), source.end(), std::front_inserter(target),[](int vaule) {return vaule > 3;});
    BOOST_ASSERT_MSG(target.size() == 2, "Size error __line__");
    std::for_each(target.cbegin(), target.cend(), [](int vaule)->void { std::cout << vaule << std::endl;});
}
