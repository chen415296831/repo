/***********************************************

    Filename: ../network/sock.c
    Author: 
    Description:
    Create Data:    2019-03-18 08:55:06
    Modfiy History: 2019-03-18 08:55:06

***********************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <assert.h>
#include <thread>
#include <iostream>
#include <memory>
#include <vector>

void printR(const char* ptr, int len)
{
    int i = 0;
    while( i < len)
    {
        printf("%4d", ptr[i++]);
    } 
    printf("\n");
}

void worker(int fd)
{
    char buf[5] = {0};
    auto id  = std::this_thread::get_id();
    while(1)
    {
        int len = read(fd, buf, sizeof(buf));
        if( len == 0)
        {
            printf("remote has close socket\n");
            break;
        }
        else
        {
        std::cout << "Thread : " <<id << "read " << len << " bytes data\n";
        printR(buf, len);
        }
    }
}

typedef std::shared_ptr<std::thread> threadPtr;
typedef std::vector<threadPtr> threadList;
threadList g_list;

int main()
{
    int srvfd = -1;
    int rmtfd = -1;
    struct sockaddr_in srvaddr;
    struct sockaddr_in rmtaddr;
    memset(&srvaddr, 0, sizeof(struct sockaddr_in));
    memset(&rmtaddr, 0, sizeof(struct sockaddr_in));

    srvfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(srvfd != -1);

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_addr.s_addr = INADDR_ANY;
    srvaddr.sin_port = htons(6000);
    int ret  = -1;
    ret = bind(srvfd, (struct sockaddr*)&srvaddr, sizeof(srvaddr));
    assert (ret == 0);

    ret = listen(srvfd, 5);
    assert ( ret == 0);

    int addrlen = sizeof(rmtaddr);
    //rmtfd = accept(srvfd, (struct sockaddr*)&rmtfd,(socklen_t*)&addrlen);
    for(;;)
    {
    rmtfd = accept(srvfd, NULL, NULL);
    printf(" client connection\n");
    g_list.push_back(threadPtr(new std::thread(worker, rmtfd)));
    }

    char buf[5] = {0,0,0,0,0};
    
    while(1)
    {
        int rlen = read(rmtfd, buf, 5);
        if( rlen == 0)
        {
            printf("remote has close socket\n");
            break;
        }
        printf(" read %d bytes data\n", rlen);
        printR(buf, rlen);
    }
    close(rmtfd);
    close(srvfd);

    return 0;
}
