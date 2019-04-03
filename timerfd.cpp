/***********************************************

    Filename: timerfd.cpp
    Author: 
    Description:
    Create Data:    2019-04-03 11:43:20
    Modfiy History: 2019-04-03 11:43:20

***********************************************/


#include <unistd.h>
#include <sys/timerfd.h>
#include <assert.h>
#include <stdint.h>
#include <boost/shared_ptr.hpp>
#include <boost/assert.hpp>
#include <iostream>

/*
 * timers that notify via file descriptotr
 * 通过文件描述符，可以像操作不同文件描述符一样，
 * 可以使用selet,pool来检测定时器
 * 时间到达时，文件描述符产生POLLIN
 */
#if 0
	//参数类型
	struct timespec {                                                       
		time_t tv_sec;                /* Seconds */                         
		long   tv_nsec;               /* Nanoseconds */                     
	};                                                                      
	struct itimerspec {                                                     
		struct timespec it_interval;  /* Interval for periodic timer */     
		struct timespec it_value;     /* Initial expiration */              
	};                                                                      
#endif
int main()
{
    struct itimerspec newtmrval,oldtmrval;
    int fd = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC);
    int fd1 = timerfd_create(CLOCK_REALTIME, TFD_CLOEXEC);
    uint64_t elapse_cnt;
    BOOST_ASSERT_MSG(fd != -1, "create timerfd failed");

	//if both fields of newtmrval.it_value to zero disarms the timer
	newtmrval.it_value.tv_nsec = 0;
    newtmrval.it_value.tv_sec  = 2;
    //if bost fields of newtmrval.it_interval to zero, timer expires just once
    //otherwizse, for repeated timier expirations after the initial experition
    newtmrval.it_interval.tv_nsec = 0;
    newtmrval.it_interval.tv_sec = 2;
    //exprition is 2s
    int ret = timerfd_settime(fd, 0,  &newtmrval, &oldtmrval);

    //exprition is 1s
    newtmrval.it_value.tv_sec = 1;
    newtmrval.it_interval.tv_sec = 1;
    ret = timerfd_settime(fd1, 0,  &newtmrval, &oldtmrval);

    BOOST_ASSERT_MSG(ret != -1, "set timerfd failed");

    while(true)
    {
        //if the tiemrs has already expired one or more times,
        //elapse_cnt containing the number of expiations that occurred
        int rlen = read(fd1, &elapse_cnt, sizeof elapse_cnt);
        BOOST_ASSERT_MSG(rlen == sizeof elapse_cnt, "read length error");

        timerfd_gettime(fd, &oldtmrval); 
        std::cout  << "Pass 1s, gettime of 2s's timer" << std::endl;
        std::cout  << "timespec.it_value.tv_sec: " << oldtmrval.it_value.tv_sec << std::endl;
        std::cout  << "timespec.it_value.tv_nsec: " << oldtmrval.it_value.tv_nsec << std::endl;
        {
            //read(fd, &elapse_cnt, sizeof elapse_cnt  );
            //std::cout << "fd expried  " << elapse_cnt << " exprition" << std::endl;
            //if(elapse_cnt == 0) {
            //    std::cout << "fd has disarmed" << std::endl;
            //} else {
            //    std::cout << "fd not disarmed" << std::endl;
            //}
        }
        std::cout  << "timespec.it_interval.tv_sec: " << oldtmrval.it_interval.tv_sec << std::endl;
        std::cout  << "timespec.it_interval.tv_nsec: " << oldtmrval.it_interval.tv_nsec << std::endl;
    }
}
