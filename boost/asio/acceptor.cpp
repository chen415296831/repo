#include <boost/asio.hpp>
#include <iostream>
#include <assert.h>

using namespace boost;

int main()
{
	asio::io_service io;
	asio::ip::address localAddress = asio::ip::address::from_string("127.0.0.1");
	assert(localAddress.is_v4());
	asio::ip::tcp::endpoint localEnd(asio::ip::tcp::v4(), 8899);
	asio::ip::tcp::acceptor server(io, localEnd, true);

	for(;;)
	{
		asio::ip::tcp::socket sock(io);
		server.accept(sock);
		std::cout << "remote address : " << sock.remote_endpoint().address() << " remote port : " << sock.remote_endpoint().port() << std::endl;

		sock.send(asio::buffer("hello world"));
		sock.close();

	}

	server.async_wait();
}
