#include <iostream>
using namespace std;

struct Triangle{
  char color;
  char shade;
  short base;
  short height;
};

struct Circle{
  char color;
  char shade;
  double radius;
};

struct VT_Cir{
  void (*draw_function) (struct Circle*);
  double (*area_function) (struct Circle*);
};

struct VT_Tri{
  void (*draw_function) (struct Triangle*);
  double (*area_function) (struct Triangle*);
};

void setTriangle(Triangle* x, char col,char sha, short b, short h)
{
  x->color=col;
  x->shade=sha;
  x->base=b;
  x->height=h;
}
void drawTriangle(Triangle* x)
{
  if(x->shade=='l')
  {
    cout<<"Light ";
  }
  else if(x->shade=='d')
  {
    cout<<"Dark ";
  }
  if(x->color=='r')
  {
    cout<<"red ";
  }
  else if(x->color=='g')
  {
    cout<<"green ";
  }
  else if(x->color=='b')
  {
    cout<<"blue ";
  }
  cout<<"triangle, base="<<x->base<<" height="<<x->height<<endl;
}
double areaTriangle(Triangle* x)
{
  return (x->base*x->height)/2.0;
}

void setCircle(Circle* x, char col, char sha, double r)
{
  x->color=col;
  x->shade=sha;
  x->radius=r;
}
void drawCircle(Circle *x)
{
  if(x->shade=='l')
  {
    cout<<"Light ";
  }
  else if(x->shade=='d')
  {
    cout<<"Dark ";
  }
  if(x->color=='r')
  {
    cout<<"red ";
  }
  else if(x->color=='g')
  {
    cout<<"green ";
  }
  else if(x->color=='b')
  {
    cout<<"blue ";
  }
  cout<<"circle, radius="<<x->radius<<endl;
}

double areaCircle(Circle* x)
{
  return 3.14*x->radius*x->radius;
}

int main()
{
  Triangle t;
  Circle c;
  setTriangle(&t,'g','d',3,5);
  setCircle(&c,'r','l',2);
  VT_Cir vtcir;
  vtcir.draw_function = drawCircle;
  vtcir.area_function= areaCircle;
  VT_Tri vttri;
  vttri.draw_function = drawTriangle;
  vttri.area_function = areaTriangle;
  vtcir.draw_function(&c);
  cout<<"Area of Circle= "<< vtcir.area_function(&c) <<endl;
  vttri.draw_function(&t);
  cout<<"Area of triangle= "<< vttri.area_function(&t) <<endl;
}