#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/ref.hpp>
#include <boost/function.hpp>

using namespace boost::asio;

class period_call_func
{
public:
	template<typename F>
	period_call_func(io_service& ioArg, int period_ms, F f):
		//m_t(io, boost::asio::chrono::seconds(period_ms)),
		io(ioArg),
		m_t(io, std::chrono::seconds(period_ms)),
		m_f(f)
		{
		}
	void init()
	{
		m_t.async_wait(m_callback);
	}
	void run()
	{
		io.run();
	}
private:
	boost::asio::io_service& io;
	boost::asio::steady_timer m_t;
	std::function<void()> m_f;

	typedef  void(callback)(const boost::system::error_code&);

	boost::function<callback> m_callback = 
		[&](const boost::system::error_code&) ->void
		{
			m_f();
			//m_t.expires_after(std::chrono::seconds(1));
			//m_t.async_wait(m_callback);
		};
};

void anther_threat_useIO(io_service& io)
{
	std::cout << "another thread ID : " << boost::this_thread::get_id() << std::endl;
	period_call_func pcf(io, 5, []() {
				std::cout << "called in another thread " <<  std::endl;
				std::cout << "exceuted thread ID : " << boost::this_thread::get_id() << std::endl;
			});
	pcf.init();

	//注册的lambda在 io_service线程执行，死循环不退出,保证回调对象不因线程而销毁
	while(1)
	{
		boost::this_thread::sleep_for(boost::chrono::seconds(1));
	}

}

typedef void(sighandler_type)(const boost::system::error_code&, int);
int main()
{
	//io service相当于一个poller，负责事件派发
	io_service io;
	signal_set sig(io);
	sig.add(SIGUSR1);
	sig.add(SIGINT);

	boost::function<sighandler_type> sigUsr1_handler = [&](const boost::system::error_code& ec, int sigNum) ->void {
			if(ec)
			{
				std::cout << ec.message() << std::endl;
				return;
			}

			if(sigNum == SIGUSR1)
			{
				std::cout << "recv SIGUSR1 " << std::endl;
				//lambda是匿名函数，不可以自己调用自己，但是用funtion对象封装一下，就可以啦
				sig.async_wait(sigUsr1_handler);
			}
		};

	boost::function<sighandler_type> sigInt_handler = [&](const boost::system::error_code& ec, int sigNum) ->void {
			if(ec)
			{
				std::cout << ec.message() << std::endl;
				return;
			}
			if(sigNum == SIGINT)
			{
				std::cout << " recv SIGINT " <<  std::endl;
			}
		};
	//每个Handler都有一个编号，编号按照注册顺序往下走
	sig.async_wait(sigUsr1_handler); 
	sig.async_wait(sigInt_handler);

	//io_service noncopyable, 使用boost::ref 传递引用类型
	boost::thread another(anther_threat_useIO,boost::ref(io));

	std::cout << "main thread ID : " << boost::this_thread::get_id() << std::endl;
	io.run();
}


