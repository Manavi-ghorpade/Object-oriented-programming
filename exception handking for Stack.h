#ifndef STACK_H
#define STACK_H
using namespace std;
#include<iostream>

template <typename Generic> 
class Stack
{
  public:
    Stack();
    Stack(const Stack<Generic>&);
    ~Stack();
    Stack& operator=(const Stack<Generic>&);
    int size() const;
    void push(const Generic&);
    void pop();
    const Generic& top() const;
  private:
    static const int chunk_size;
    unsigned maximum_size;
    int current_size;
    Generic* base;
};

template <typename Generic>
const int Stack<Generic>::chunk_size=10;

template <typename Generic> 
Stack<Generic>::Stack()
:current_size(-1),maximum_size(chunk_size),base((Generic*)malloc(sizeof(Generic)*chunk_size))
{
}

template <typename Generic>
Stack<Generic>::Stack(const Stack<Generic>& s)
:maximum_size(s.maximum_size), base((Generic*)malloc(sizeof(Generic)*maximum_size))
{
  if(s.current_size>-1)
  {
    try{
    for(current_size=0; current_size<=s.current_size; current_size++)
    {
      new (base+current_size) Generic(s.base[current_size]);
    }
    current_size--;
    }
    catch(...)
    {
      current_size--;
      for(int i=current_size;i>=0;--i)
      {
        (base+i)->~Generic();
      }
      free(base);
      throw;
    }
  }
}

template <typename Generic>
Stack<Generic>::~Stack()
{
  for(int i=current_size;i>=0;i--)
  {
    (base+i)->~Generic();
  }
  free(base);
}

template <typename Generic>
Stack<Generic>& Stack<Generic>::operator=(const Stack<Generic>& s)
{
  Generic* new_base=(Generic*)malloc(s.maximum_size*sizeof(Generic));
  int successful_obj=0;
  try{ //copy items
    for(;successful_obj<=s.current_size;++successful_obj)
    {
      new (new_base+successful_obj) Generic(s.base[successful_obj]);
    }
    --successful_obj;
  }
  catch(...)
  {
    --successful_obj;
    for(int destruct_obj=successful_obj;destruct_obj>=0;--destruct_obj)
    {
      (new_base+destruct_obj)->~Generic();
    }
    free(new_base);
    throw;
  }
  for(int i=current_size; i>=0; i--)
  {
    (this->base+i)->~Generic();
  }
  free(base);
  this->base=new_base;
  this->maximum_size=s.maximum_size;
  this->current_size=s.current_size;
  return *this;
}

template <typename Generic>
void Stack<Generic>::push(const Generic& element)
{
  current_size++;
  if(current_size==maximum_size)  //current_size=10 means 11th element 
  {
    maximum_size+=chunk_size;
    Generic* new_buffer = (Generic*)malloc(sizeof(Generic)*maximum_size);
    int x=0;
    try{
    for(; x<current_size; ++x)
    {
      new (new_buffer+x) Generic(*(base+x)); //copies values of base to the new pointer
    }
    }
    catch(...)
    {
      for(int destruct=x-1;destruct>=0;--destruct)
      {
        (new_buffer+destruct)->~Generic();
      }
      free(new_buffer);
      current_size--;
      throw;
    }
    for(int i=current_size-1;i>=0;i--)
    {
      (this->base+i)->~Generic();
    }
    free(base);
    base=new_buffer;
  }
  try{
  new (base+current_size) Generic(element); //copy constructor
  }
  catch(...)
  {
    current_size--;
    throw;
  }
}

template <typename Generic>
void Stack<Generic>::pop()
{
  if(current_size>=0) //if stack is not empty
  {
    (base+current_size)->~Generic();
    current_size--;
  }
}

template <typename Generic>
int Stack<Generic>::size() const
{
  return current_size+1;
}

template <typename Generic>
const Generic& Stack<Generic>::top() const
{
  if(current_size>-1)
    return base[current_size];   //if stack is empty it causes undefined behavior.
  else
    exit(0);
}

#endif