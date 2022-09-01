#ifndef STIPPLE_H
#define STIPPLE_H
using namespace std;
#include <ostream>
#include <iostream>
using std::ostream;
class stipple
{
    private:
        int count;
        char stipple_print;
    public:
        stipple(char s,int c);
        friend ostream& operator<<(ostream& os,const stipple& st);
};
#endif