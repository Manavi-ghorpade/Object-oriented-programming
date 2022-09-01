//author= Manavi Ghorpade
//date=6/22/2022

#include <iostream>
#include<streambuf>
#include<cstdlib>
#include <cstdio>
#include<cmath>
using namespace std;

class figbuf : public streambuf
{
  private:
    char* buffer=new char[10]; 
    FILE* figlet_pipe;
  public:
    int overflow(int c= EOF);
    figbuf();
    ~figbuf();
    int sync();
};

int figbuf::overflow(int c)
{
  //phase-I
  // cerr<<"overflowing\n";
  //phase-II
  // string the_figlet_string="figlet \"";
  // the_figlet_string+= c;
  // the_figlet_string+="\"";
  // system(the_figlet_string.c_str());
  //phase-III
  *pptr()=(char)c;
  pbump(1);
  sync();
  return c;
}

figbuf::figbuf()
{
  setp(buffer,buffer+9);
  figlet_pipe=popen("figlet -W -w 1000 -f standard", "w");
}

figbuf::~figbuf()
{
  sync();
  pclose(figlet_pipe);
}

int figbuf::sync()
{
  try
  {
  for(char* i=pbase();i<pptr();++i)
  {
    fputc(*i,figlet_pipe);
  }
  setp(pbase(),epptr());
  return 0;
  }
  catch(...)
  {
    return -1;
  }
}


int main() 
{
  //It is fine to create a figbuf object as a local variable.  It ensures the
  //destructor will run when main() ends.
  figbuf fb;
  //Save the normal streambuf object cout uses
  auto couts_original_streambuf=cout.rdbuf();
  //Change it to use figbuf instead.
  cout.rdbuf(&fb);

  cout << "sin(3.14/4)=" << sin(3.141592/4) << ". That's not rational.\n";
  cout << "One\nword\nper\nline\nends with endl"<< endl;
  cout << "This line concludes the demonstration.";

  //Restore the original streambuf to cout
  cout.rdbuf(couts_original_streambuf);

  return 0;
}
