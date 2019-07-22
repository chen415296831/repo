
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <assert.h>
#include <stdint.h>

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

	//问题1： listen之后sleep,客户端可以连接成功吗?
	sleep(UINT32_MAX);
	//anwser:经过测试之后，客户端可以连接成功，read已建立连接的socket会阻塞

}
