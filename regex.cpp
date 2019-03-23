#include <iostream>
#include <string>
#include <regex>
#include <assert.h>
int main()
{
	std::string input;
	std::string pattern("[^c]ei");
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"; 
	pattern = "([[:alpha:]]*)([^c]ei)([[:alpha:]]*)"; 
	// ',' 也是一个特殊子符
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*" +"\\,*" + "[[:alnum:]]";
	std::regex re;
	try
	{
		re.assign(pattern);
	}
	catch(std::regex_error e)
	{
		std::cout<< e.what() << "\ncode" << e.code() << '\n';
	}
	std::smatch m;
	std::string testStr = {"friend, abcei, kieid, seceieiei, killeid, aafa  "};
	
	//单词匹配
	if(std::regex_search(testStr, m, re ))
		std::cout << m.str() << '\n';
	
	//连续匹配
	for(std::sregex_iterator it(testStr.begin(), testStr.end(), re), end_it; it != end_it; it++)
	{
		std::cout<< it->str()<<'\n';
	}

	//当匹配完成之后，匹配类型有两个prefix,suffix的成员，表示匹配序列之前和之后的位置，类型是ssub_match类型的
	//从输出可以看到，如果前面有子符串已经匹配成功，后续的匹配从剩余的字符串开始匹配
	for(std::sregex_iterator it(testStr.begin(), testStr.end(), re), end_it; it != end_it; it++)
	{
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		std::cout<< it->prefix().str().substr(pos) <<'\n'
				 << ">>" << it->str() << "<<\n"
				 << it->suffix().str().substr(0,40) <<'\n';
	}

	//it指向smatch， 正则表达式有多个子表达式组成
	//例如([[:alpha:]]*)([^c]ei)([[:alpha:]]*)有三个表达式
	//it->size()等于4，第0个是所有子表达式的匹配结果,1是第一个子表达式的配置结果，n是第n个子表达匹配结果
	for(std::sregex_iterator it(testStr.begin(), testStr.end(), re), end_it; it != end_it; it++)
	{
		std::cout<< it->str()<<'\n';
		std::cout<< "regex has " <<  it->size() << "sub expression" << '\n';
		auto subExprCnt = it->size();	//regex中子表达式的数量，等于实际子表达式+1
		assert(subExprCnt == 4);
		for(decltype(subExprCnt) i = 0; i< subExprCnt; i++)
		{
			//从打印输出可以看到，子表达式匹配，如果在前面的子表达式匹配已经匹配，之后的子表示式从剩余的字符串开始匹配
			std::ssub_match const& m =  (*it)[i];
			if(m.matched) //matched : public boolean member
			{
				std::cout << "sub experssion " << i << " matched " << "match context is : " << m.str() << '\n';
			}
			else
			{
				std::cout << "sub experssion " << i << "not matched\n";
			}
		}

	}

	//同样，既然正则表达式可以帮我们找到各个匹配的字表达式，重新格式化这些子字符串也是可以的
	//c++ regex_replace就提供了这样的功能
}
