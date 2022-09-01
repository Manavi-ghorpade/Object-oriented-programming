#ifndef TRACKINGDEQUE_H
#define TRACKINGDEQUE_H
#include <deque>
#include <iostream>
template<typename T>
class TrackingDeque:public std::deque<T>{
    private:
        int max_size;
    public:
        TrackingDeque();
        ~TrackingDeque();
        void push_back(const T& val);
        void push_front(const T& val);  
};    

template<typename T>
TrackingDeque<T>:: TrackingDeque():max_size(0){}

template<typename T>
TrackingDeque<T>:: ~TrackingDeque()
{
    std::cout<<"--> "<<max_size<<" <--\n";
}

template<typename T>
void TrackingDeque<T>::push_back(const T& val)
{
    std::deque<T>::push_back(val);
    if(std::deque<T>::size() > max_size)
    {
     max_size=std::deque<T>::size();
    }
}

template<typename T>
void TrackingDeque<T>::push_front(const T& val)
{
    std::deque<T>::push_front(val);
    if(std::deque<T>::size() > max_size)
    {
    max_size=std::deque<T>::size();
    }
}
#endif