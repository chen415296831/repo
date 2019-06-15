#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <thread>

using namespace boost::asio;
using namespace std;

io_context io;
steady_timer t(io);

void fun(const boost::system::error_code&)
{
	std::cout << "expired" << std::endl;
	t.expires_after(std::chrono::seconds(1));	
	t.async_wait(fun);
}

int main()
{
	t.expires_after(std::chrono::seconds(2));
	t.async_wait(fun);

	auto cb = boost::bind(&io_context::run, &io);
	boost::thread_group threads;
	threads.create_thread([]()->void {
				io.run();
			});
	threads.join_all();
}
