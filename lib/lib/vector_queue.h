/*
 * vector_queue.h
 *
 *  Created on: Sep 16, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_VECTOR_QUEUE_H_
#define LIB_VECTOR_QUEUE_H_

#include <vector>
#include <cstdint>

// Class for queue
template <class X>
class VectorQueue
{
  std::vector<X> _queue;
  std::uint8_t _capacity;

public:
  void init(std::uint8_t size);
  void remove();
  void add_front(X item);
  void add_back(X item);
  X * front();
  X * back();
  X * item_at(std::uint8_t index);
  void erase(std::uint8_t index);
  void rotate();
  int size();
  bool is_empty();
  bool is_full();
};

template <class X>
void VectorQueue<X>::init(std::uint8_t size)
{
  _capacity = size;
  _queue.reserve(size);
}

// Utility function to remove front element from the queue
template <class X>
void VectorQueue<X>::remove()
{
  _queue.pop_back();
}

// Utility function to add an item to the queue
template <class X>
void VectorQueue<X>::add_front(X item)
{
  if (_queue.size() < _capacity)
  {
    _queue.insert(_queue.begin(), item);
  }
}

template <class X>
void VectorQueue<X>::add_back(X item)
{
  if (_queue.size() < _capacity)
  {
    _queue.push_back(item);
  }
}

template <class X>
X * VectorQueue<X>::front()
{
  return &_queue.front();
}

template <class X>
X * VectorQueue<X>::back()
{
  return &_queue.back();
}

template <class X>
X * VectorQueue<X>::item_at(std::uint8_t index)
{
//  if (_queue.size() > index)
//  {
    return &_queue.at(index);
//  }
//  else
//  {
//    return nullptr;
//  }
}

template <class X>
void VectorQueue<X>::erase(std::uint8_t index)
{
  if (_queue.size() > index)
  {
    _queue.erase(_queue.begin()+index);
  }
}

template <class X>
void VectorQueue<X>::rotate()
{
  if (_queue.size() > 1)
  {
    X item(_queue.back());
    _queue.pop_back();
    _queue.insert(_queue.begin(), item);
  }
}

// Utility function to return the size of the queue
template <class X>
int VectorQueue<X>::size()
{
  return _queue.size();
}

// Utility function to check if the queue is empty or not
template <class X>
bool VectorQueue<X>::is_empty()
{
  return (_queue.size() == 0);
}

// Utility function to check if the queue is full or not
template <class X>
bool VectorQueue<X>::is_full()
{
  return (_queue.size() == _capacity);
}

#endif /* LIB_VECTOR_QUEUE_H_ */
