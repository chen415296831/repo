/***********************************************

    Filename: operators.cpp
    Author: 
    Description:
    Create Data:    2019-04-11 16:41:30
    Modfiy History: 2019-04-11 16:41:30

***********************************************/
#include <cstdint>
#include <boost/operators.hpp>
#include <boost/assert.hpp>

class TimeStamp : public boost::equality_comparable<TimeStamp>,
                  public boost::less_than_comparable<TimeStamp>
{
public:
    TimeStamp(int s, int ms)
        :seconds_(s),
         milliseconds_(ms)
    {}
    int32_t seconds_;
    int32_t milliseconds_;

};

inline bool operator== (const TimeStamp& lhs, const TimeStamp& rhs)
{
    return lhs.seconds_ * 1000 + lhs.milliseconds_ == rhs.seconds_ * 1000 + rhs.milliseconds_;
}
//inline bool operator< (TimeStamp lhs, TimeStamp rhs)
inline bool operator< (const TimeStamp& lhs, const TimeStamp& rhs)
{
    return lhs.seconds_ * 1000 + lhs.milliseconds_ <  rhs.seconds_ * 1000 + rhs.milliseconds_;
}
int main()
{
    TimeStamp ts1(1, 2);
    TimeStamp ts2(1, 3);
    BOOST_ASSERT(!(ts1 == ts2));
    BOOST_ASSERT((ts1 != ts2));
    BOOST_ASSERT((ts1 < ts2));
    BOOST_ASSERT(!(ts1 > ts2));
    BOOST_ASSERT(!(ts1 >= ts2));
    BOOST_ASSERT((ts1 <= ts2));
}
