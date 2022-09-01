#include <iostream>
using namespace std;

float add(float a, float b)
{
  float c=a+b;
  cout<<"Addition of "<<a<<" and "<<b<<" =";
  return c;
}
float substract(float a, float b)
{
  cout<<"Substraction of "<<a<<" and "<<b<<" =";
  float c=a-b;
  return c;
}
float divide(float a, float b)
{
  cout<<"Division of "<<a<<" and "<<b<<" =";
  float c=a/b;
  return c;
}
float multiply(float a, float b)
{
  cout<<"Multiplication of "<<a<<" and "<<b<<" =";
  float c=a*b;
  return c;
}
int main()
{
  //single pointer
  cout<<endl<<"Using single pointer:"<<endl;
  float (*ptr)(float,float);  //declare
  ptr=add; 
  float a=ptr(4.2,1.5);
  cout<<a<<endl;
  //array of pointers
  cout<<endl<<"Using array of pointers:"<<endl;
  float (*ptr1[4])(float,float);
  ptr1[0]=add;
  ptr1[1]=substract;
  ptr1[2]=divide;
  ptr1[3]=multiply;
  float b;
  for(int i=0;i<=3;i++)
  {
  b=ptr1[i](3.2,1.5);  //invoke
  cout<<b<<endl;
  }
  cout<<endl;
  return 0;
}



//Two-part Hacker's Challenge!
//part 1:
//int a,b,c;
//cout<<"enter three integer values for 3d array"<<endl;
//cin>>a>>b>>c;
//int t=a*b*c;
//float ***array;
//array= new float**[t];  //memory allocation
//assign values to 3d array using loop
//change one value to pi
//print out the values using loop
//then delete the pointer
//part 2: