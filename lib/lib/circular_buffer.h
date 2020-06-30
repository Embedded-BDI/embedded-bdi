/*
 * circular_buffer.h
 *
 *  Created on: Jun 02, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_CIRCULAR_BUFFER_H_
#define LIB_CIRCULAR_BUFFER_H_

#include <iostream>
#include <stdlib.h>

// Class for queue
template <class X>
class CircularBuffer
{
  X *_arr;     // _array to store queue elements
  int _capacity;   // maximum _capacity of the queue
  int _front;    // _front points to _front element in the queue (if any)
  int _rear;     // _rear points to last element in the queue
  int _count;    // current size of the queue

public:
  CircularBuffer();    // constructor
  virtual ~CircularBuffer();

  void init(int size);
  bool dequeue();
  bool enqueue(X x);
  X * peek();
  X * item(int index);
  int size();
  int capacity();
  bool is_empty();
  bool is_full();
};

template <class X>
CircularBuffer<X>::CircularBuffer(){} // @suppress("Class members should be properly initialized")

template <class X>
CircularBuffer<X>::~CircularBuffer()
{
   delete _arr;
}

template <class X>
void CircularBuffer<X>::init(int size)
{
  _arr = new X[size];
  _capacity = size;
  _front = 0;
  _rear = -1;
  _count = 0;
}

// Utility function to remove _front element from the queue
template <class X>
bool CircularBuffer<X>::dequeue()
{
  // check for queue underflow
  if (is_empty())
  {
    return false;
  }

  _front = (_front + 1) % _capacity;
  _count--;
  return true;
}

// Utility function to add an item to the end of the queue
template <class X>
bool CircularBuffer<X>::enqueue(X item)
{
  // check for queue overflow
  if (is_full())
  {
    return false;
  }

  _rear = (_rear + 1) % _capacity;
  _arr[_rear] = item;
  _count++;
  return true;
}

// Utility function to return _front element in the queue
template <class X>
X * CircularBuffer<X>::peek()
{
  if (is_empty())
  {
    return NULL;
  }
  return &_arr[_front];
}

template <class X>
X * CircularBuffer<X>::item(int index){
  if (index < 0 || index >= _count)
  {
    return NULL;
  } else {
    return &_arr[index];
  }
}

// Utility function to return the size of the queue
template <class X>
int CircularBuffer<X>::size()
{
  return _count;
}

// Utility function to return the size of the queue
template <class X>
int CircularBuffer<X>::capacity()
{
  return _capacity;
}

// Utility function to check if the queue is empty or not
template <class X>
bool CircularBuffer<X>::is_empty()
{
  return (size() == 0);
}

// Utility function to check if the queue is full or not
template <class X>
bool CircularBuffer<X>::is_full()
{
  return (size() == _capacity);
}

#endif /* CLASSES_CIRCULAR_QUEUE_H_ */
