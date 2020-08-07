/*
 * circular_buffer.h
 *
 *  Created on: Jun 02, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_CIRCULAR_BUFFER_H_
#define LIB_CIRCULAR_BUFFER_H_

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
  CircularBuffer(int size);    // constructor
  virtual ~CircularBuffer();

  void init(int size);
  bool enqueue(X x);
  bool dequeue();
  X * item(int index);
  X * peek();
  void rotate();
  int capacity();
  int size();
  bool is_empty();
  bool is_full();
};

template <class X>
CircularBuffer<X>::CircularBuffer(int size)
{
  _arr = new X[size];
  _capacity = size;
  _front = 0;
  _rear = -1;
  _count = 0;
}

template <class X>
CircularBuffer<X>::~CircularBuffer()
{
   delete [] _arr;
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

template <class X>
X * CircularBuffer<X>::item(int index){
  if (index < 0 || index >= _count)
  {
    return nullptr;
  } else {
    return &_arr[index];
  }
}

// Utility function to return _front element in the queue
template <class X>
X * CircularBuffer<X>::peek()
{
  if (is_empty())
  {
    return nullptr;
  }
  return &_arr[_front];
}

// Utility function to return the size of the queue
template <class X>
int CircularBuffer<X>::capacity()
{
  return _capacity;
}

// Utility function to return the size of the queue
template <class X>
int CircularBuffer<X>::size()
{
  return _count;
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
