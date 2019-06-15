#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
#include <iostream>
#include <chrono>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <thread>
#include <functional>

class fmu
{
public:
	void showElement(int howMuch)
	{
		for(auto i = 0; i <howMuch; i++)
			std::cout << m_iArray[i] << ", ";
		std::cout << std::endl;
	}
	fmu(int n):
		m_iArray(n,0)
	{};
private:
	std::vector<int> m_iArray;
};

class period_call_func
{
public:
	template<typename F>
	period_call_func(int period_ms, F f):
		//m_t(io, boost::asio::chrono::seconds(period_ms)),
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
	boost::asio::io_service io;
	boost::asio::steady_timer m_t;
	std::function<void()> m_f;

	typedef  void(callback)(const boost::system::error_code&);

	std::function<callback> m_callback = 
		[&](const boost::system::error_code&) ->void
		{
			m_f();
			m_t.expires_after(std::chrono::seconds(1));
			m_t.async_wait(m_callback);
		};
};

void fun()
{
	std::cout << "called" << std::endl;
}

int main()
{
	boost::asio::io_context bio;
	fmu f(10);
	period_call_func pcf(3, std::bind(&fmu::showElement, &f, 10));
	pcf.init();

	auto worker = std::thread(std::bind(&period_call_func::run, &pcf));
	worker.join();
}
