#include<iostream>
using namespace std;
union manavi  //create union 
{
  int roll_number;  //define data members
  char initial;     
  int * number;
  float weight; 
};
int main()
{
  cout<<"size of my union: "<<sizeof(manavi)<<endl;  //union will assign the size of biggest data member to memory e.g int= 4byte, char=1byte, int pointer=8 byte
  int value=5;
  union manavi m;   //object of the union
  m.number=&value;  //first union will hold this value(address)
  *(m.number)=20;   //assign 20 to that memory location
  m.initial='M';    //as memory location is shared, the the first value get overwrite by the second value
  m.weight=45.5;    // again overwrite 
  m.roll_number=21; //last value which will not get overwrite so union will hold this value
  //union can hold only one of its data memebers at a time  
  
  cout<<"address of pointer: "<<m.number<<endl; //corrupted output because the value of pointer(8 byte)is overwritten by the integer of 4 byte
  cout<<"initial: "<<m.initial<<endl; //corrupted output -- similar to casting  --- character corresponding to the integer
  cout<<"weight: "<<m.weight<<endl;  //corrupted output
  cout<<"roll no: "<<m.roll_number<<endl;     //the output will remain same(correct) because it initialized at last
 
 ////how casting and unions are related///
 //Ans:
 //So in my union the RAM(memory location) is used as either int or float or char or by integer pointer.
 // In last I have set that memory to "21"(bit pattern) as a integer.
 //after that if I try to print out the data as character then it will print out whatever character corresponding to that integer-bit pattern value
 //----------casting-------------------------print the character as integer//
 cout<<"the type casting - char output(initials) as integer : "<<(int)m.initial<<endl; //it will give "21" i.e m.roll_number
}
