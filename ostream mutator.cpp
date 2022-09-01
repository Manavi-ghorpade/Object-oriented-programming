#include "stipple.h"

stipple::stipple(char s,int c):stipple_print(s),count(c)
{
}

ostream& operator<<(ostream& os,const stipple& st)
{
    int num=st.count;
    if(num%2 == 0)
    {
        num=num/2;
        for(int i=0;i<num;i++)
        {
            os<<st.stipple_print<<".";
        }
        
    }
    else
    {
        if(num==1)
        {
            os<<st.stipple_print;
        }
        else
        {
            num=(num/2)+1;
            for(int i=0;i<num;i++)
            {
                if(i==num-1)
                {
                    os<<st.stipple_print;
                }
                else
                {
                    os<<st.stipple_print<<".";
                }
            }
        }
        
    }
    return os;
}