/***********************************************

    Filename: smart_ptr.cpp
    Author: 
    Description:
    Create Data:    2019-03-22 08:54:10
    Modfiy History: 2019-03-22 08:54:10

***********************************************/
#include <iostream>
#include <vector>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>

class foo
{
public:
    foo(int v = 0)
      :a(v)
    {
    }
private:
    int a;
};

typedef boost::shared_ptr<foo> fooPtr;
typedef boost::weak_ptr<foo>  fooWeakPtr;
typedef std::vector<fooWeakPtr> fooArray;

class container
{
public:
    void remove(foo* f)
    {
        std::size_t i = 0;
        for(;  i < foos_.size(); i++)
        {
            foos_[i].lock().get() == f;
            break;
        }
        foos_.erase(foos_.begin() + i);
        delete f;
    }
    void add(fooPtr f)
    {
        fooWeakPtr wkptr = f;
        foos_.push_back(wkptr);
    }
    void printArraySize()
    {
        std::cout << "foos_.size() = " << foos_.size() << '\n';
    }
private:
    fooArray foos_;
};
int main()
{
    container bucket;
    {
        fooPtr f1(new foo(1), boost::bind(&container::remove, &bucket, _1));
        bucket.add(f1);
        bucket.printArraySize();
    }
    bucket.printArraySize();
}
