/***********************************************

    Filename: getXid.cpp
    Author: 
    Description:
    Create Data:    2019-03-22 14:56:08
    Modfiy History: 2019-03-22 14:56:08

***********************************************/
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <thread>
#include <iostream>

/*glibc not warp this system call*/
#define gettid() syscall(SYS_gettid)
void outXid ()
{
    /**
     * sys_getpid - return the thread group id of the current process
     *
     * Note, despite the name, this returns the tgid not the pid.  The tgid and
     * the pid are identical unless CLONE_THREAD was specified on clone() in
     * which case the tgid is the same in all threads of the same group.
     */
    std::cout << "getpid()  : " << getpid() << '\n';
    /*Parent id, general euqal BASH pid*/
    std::cout << "getppid() : " << getppid() << '\n';
    std::cout << "getuid()  : " << getuid() << '\n';
    std::cout << "geteuid() : " << geteuid() << '\n';
    std::cout << "getgid()  : " << getgid() << '\n';
    std::cout << "getegid() : " << getegid() << '\n';
    /*thread ID, - thr internal kernel "Pid"*/
    std::cout << "gettid()  : " << gettid() << '\n';
}
int main()
{
    std::cout << "main  thread output\n";
    outXid();
    std::cout << "child thread output\n";
    std::thread child(outXid);
    child.join();
}

