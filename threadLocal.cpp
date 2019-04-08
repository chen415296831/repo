/***********************************************

    Filename: threadLocal.cpp
    Author: 
    Description:
    Create Data:    2019-04-08 08:40:45
    Modfiy History: 2019-04-08 08:40:45

***********************************************/
#define __GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <boost/assert.hpp>

__thread  int flag = 0;

void modify_flag()
{
    BOOST_ASSERT_MSG(flag == 0, "local variable abnormal");
    flag = 1;
    printf("thread %ld flag address -- %p\n", syscall(SYS_gettid), &flag);
}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        printf(" usage: program thread count\n");
        exit(-1);
    }
    std::vector<std::thread> threads;
    int threadNum = atoi(argv[1]);
    while(threadNum--)
    {
        threads.emplace_back(
                []{
                modify_flag();
                }
                );
    }
    for(auto& t : threads)
        t.join();
}
