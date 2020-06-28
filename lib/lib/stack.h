/*
 * stack.h
 *
 *  Created on: Jun 04, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_Stack_H_
#define LIB_Stack_H_

#include <iostream>
#include <stdlib.h>

// Class for Stack
template <class X>
class Stack
{
  X *arr;
  int top;
  int capacity;

public:
  Stack();

  void init(int size); // constructor

  virtual ~Stack();

  void push(X);
  X pop();
  X peek();

  int size();
  bool isEmpty();
  bool isFull();
};

template <class X>
Stack<X>::Stack(){}

template <class X>
Stack<X>::~Stack(){
  delete[] arr;
}

template <class X>
void Stack<X>::init(int size)
{
  arr = new X[size];
  capacity = size;
  top = -1;
}

// function to add an element x in the Stack
template <class X>
void Stack<X>::push(X item)
{
  if (isFull())
  {
    std::cout << "Stack ERROR: cannot push to full Stack" << std::endl;
    exit(EXIT_FAILURE);
  }

  arr[++top] = item;
}

// function to pop top element from the Stack
template <class X>
X Stack<X>::pop()
{
  // check for Stack underflow
  if (isEmpty())
  {
    std::cout << "Stack ERROR: cannot pop from empty Stack" << std::endl;
    exit(EXIT_FAILURE);
  }

  // decrease Stack size by 1 and (optionally) return the popped element
  return arr[top--];
}

// function to return top element in a Stack
template <class X>
X Stack<X>::peek()
{
  if (!isEmpty())
  {
    return arr[top];
  } else {
    std::cout << "Stack ERROR: cannot peek empty Stack" << std::endl;
    exit(EXIT_FAILURE);
  }
}

// Utility function to return the size of the Stack
template <class X>
int Stack<X>::size()
{
  return top + 1;
}

// Utility function to check if the Stack is empty or not
template <class X>
bool Stack<X>::isEmpty()
{
  return top == -1;
}

// Utility function to check if the Stack is full or not
template <class X>
bool Stack<X>::isFull()
{
  return top == capacity - 1;
}

#endif /* LIB_Stack_H_ */
