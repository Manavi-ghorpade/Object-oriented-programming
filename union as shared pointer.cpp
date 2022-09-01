//author= Manavi Ghorpade
//date=6/8/2022

#include <iostream>
using namespace std;

struct Triangle;
struct Circle;

struct VT_Tri{
  void (*draw_function) (struct Triangle*);
  double (*area_function) (struct Triangle*);
};

struct VT_Cir{
  void (*draw_function) (struct Circle*);
  double (*area_function) (struct Circle*);
};

struct Triangle{
  char color;
  VT_Tri vttri;
  char shade;
  short base;
  short height;
};

struct Circle{
  char color;
  VT_Cir vtcir;
  char shade;
  double radius;
};

union shape_ptr {
  struct Circle* cir_ptr;
  struct Triangle* tri_ptr;
};

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
  double a= (x->base*x->height)/2.0;
  cout<<"Area of triangle= "<<a<<endl;
  return a;
}

void setTriangle(Triangle* x, char col,char sha, short b, short h)
{
  x->color=col;
  x->shade=sha;
  x->base=b;
  x->height=h;
  x->vttri.draw_function = drawTriangle;
  x->vttri.area_function = areaTriangle;
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
  double a= 3.14*x->radius*x->radius;
  cout<<"Area of Circle= "<<a<<endl;
  return a;
}

void setCircle(Circle* x, char col, char sha, double r)
{
  x->color=col;
  x->shade=sha;
  x->radius=r;
  x->vtcir.draw_function = drawCircle;
  x->vtcir.area_function= areaCircle;
}

void do_poly(union shape_ptr shape)  //shape's member variables either have tri_ptr value or cir_ptr value
{
  //cout<<"address of tri "<<shape.tri_ptr<<endl; -->  //both address will be same because union point to same memory location
  //cout<<"address of cir "<<shape.cir_ptr<<endl; --> // the address value displayed are same because both tri_ptr and cir_ptr are of same type 
  shape.tri_ptr->vttri.draw_function(shape.tri_ptr); //(addresss of struct(either circle or triangle struct adres.) -> draw_function)
  shape.tri_ptr->vttri.area_function(shape.tri_ptr);
  //cout<<&(shape.tri_ptr->vttri.draw_function)<<endl; --> //both vttri.draw_function and vtcri.draw_function points to either drawCircle or drawTriangle function because of union
  //cout<<&(shape.cir_ptr->vtcir.draw_function)<<endl; --> //which we assigned in set function(line 146 to 149).Hence the output address is same 
  //same thing happen with area_function -- it points either to areaCircle or areaTriangle depending upon the type of Structure
  //hence do_poly will work for both triangles and circles
}

int main()
{
  union shape_ptr shapes[4];
  Triangle t;    //object of structure
  Triangle t1;
  Circle c;
  Circle c1;
  setTriangle(&t,'g','d',3,5);    //set values
  setTriangle(&t1,'r','d',7,9);
  setCircle(&c,'b','l',4);
  setCircle(&c1,'g','l',2);
  shapes[0].tri_ptr=&t;           //assign address to pointer of struct
  shapes[1].tri_ptr=&t1;
  shapes[2].cir_ptr=&c;
  shapes[3].cir_ptr=&c1;
  for(int i=0;i<4;i++)
  {
    do_poly(shapes[i]);
  }
}