/*
 * stack.h
 *
 *  Created on: Jun 04, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_Stack_H_
#define LIB_Stack_H_

// Class for Stack
template <class X>
class Stack
{
  X * _arr;
  int _top;
  int _capacity;

public:
  Stack(int size);

  virtual ~Stack();

  bool push(X);
  X * pop();
  X * peek();

  int size();
  bool is_empty();
  bool is_full();
};

template <class X>
Stack<X>::Stack(int size)
{
  _arr = new X[size];
  _capacity = size;
  _top = -1;
}

template <class X>
Stack<X>::~Stack()
{
  delete [] _arr;
}

// function to add an element x in the Stack
template <class X>
bool Stack<X>::push(X item)
{
  if (is_full())
  {
    return false;
  }

  _arr[++_top] = item;
  return true;
}

// function to pop top element from the Stack
template <class X>
X * Stack<X>::pop()
{
  // check for Stack underflow
  if (is_empty())
  {
    return nullptr;
  }

  // decrease Stack size by 1 and (optionally) return the popped element
  return &_arr[_top--];
}

// function to return top element in a Stack
template <class X>
X * Stack<X>::peek()
{
  if (!is_empty())
  {
    return &_arr[_top];
  } else {
    return nullptr;
  }
}

// Utility function to return the size of the Stack
template <class X>
int Stack<X>::size()
{
  return _top + 1;
}

// Utility function to check if the Stack is empty or not
template <class X>
bool Stack<X>::is_empty()
{
  return _top == -1;
}

// Utility function to check if the Stack is full or not
template <class X>
bool Stack<X>::is_full()
{
  return _top == _capacity - 1;
}

#endif /* LIB_Stack_H_ */
