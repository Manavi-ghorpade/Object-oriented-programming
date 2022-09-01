using namespace std;
#include<iostream>
template <typename Generic> 
class Stack
{
  public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    int size();
    void push(Generic);
    Generic pop();
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
:current_size(-1),maximum_size(chunk_size),base(new Generic[chunk_size])
{
}

template <typename Generic>
Stack<Generic>::Stack(const Stack& s)
:maximum_size(s.maximum_size), base(new Generic[s.maximum_size])
{
  if(s.current_size>-1)
  {
    for(current_size=0; current_size<=s.current_size; current_size++)
      base[current_size]=s.base[current_size];
    current_size--;
  }
}

template <typename Generic>
Stack<Generic>::~Stack()
{
  delete [] base;
}

template <typename Generic>
Stack<Generic>& Stack<Generic>::operator=(const Stack& s)
{
  delete [] base;
  maximum_size=s.maximum_size;
  base=new Generic[maximum_size];
  current_size=s.current_size;
  if(current_size>-1)
  {
    for(int x=0; x<=current_size; x++)
      base[x]=s.base[x];
  }
  return *this;
}

template <typename Generic>
void Stack<Generic>::push(Generic element)
{
  current_size++;
  if(current_size==maximum_size-1)
  {
    maximum_size+=chunk_size;
    Generic* new_buffer = new Generic[maximum_size];
    for(int x=0; x<current_size; x++)
      new_buffer[x]=base[x];
    delete [] base;
    base=new_buffer;
  }
  base[current_size]=element;
}

template <typename Generic>
Generic Stack<Generic>::pop()
{
  if(current_size<0)
    throw "Nothing to pop!";
  return base[current_size--];
}

template <typename Generic>
int Stack<Generic>::size()
{
  return current_size+1;
}