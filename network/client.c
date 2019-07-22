
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
	int connection = socket(AF_INET, SOCK_STREAM, 0);
	assert(connection != -1);

	struct sockaddr_in srvaddr;
	memset(&srvaddr, 0, sizeof srvaddr);
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(6000);
	srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int ret = connect(connection, (struct sockaddr*)&srvaddr, sizeof srvaddr);
	if(ret == 0)
	{
		printf("connect to server success\n");
	}

	char buf[10] = {0};
	//即使客户端listen之后，没有accept，read会阻塞。那写呢？
	//ret = read(connection, buf, sizeof buf);
	snprintf(buf, 10, "hello server");
	ret = write(connection, buf, 10);
	//写也是可以的
	printf ("ret = %d\n", ret);
	if(ret  == -1)
	{
		perror("on write: ");
	}
	ret = read(connection, buf, sizeof buf);


}
