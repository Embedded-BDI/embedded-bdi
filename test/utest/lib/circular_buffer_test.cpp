/*
 * circular_buffer_test.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "lib/circular_buffer.h"

class TCircularBuffer : public ::testing::Test {
protected:
  CircularBuffer<int> * buffer;
  int size = 4;                                 // size must be 2 or higher

public:
  TCircularBuffer() {
    buffer = new CircularBuffer<int>();
    buffer->init(size);
  }

  virtual ~TCircularBuffer() {
    delete buffer;
  }
};

/*
 * Test enqueue elements until queue is full
 */
TEST_F(TCircularBuffer, enqueue) {
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer->enqueue(i));
  }
  EXPECT_FALSE(buffer->enqueue(size));
}

/*
 * Test enqueue and dequeue elements and confirm that queue is empty
 */
TEST_F(TCircularBuffer, dequeue) {
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer->enqueue(i));
  }
  for(int i = size-1; i >= 0; i--)
  {
    EXPECT_TRUE(buffer->dequeue());
  }
  EXPECT_FALSE(buffer->dequeue());
}

/*
 * Test enqueue some elements and query by index to confirm values
 */
TEST_F(TCircularBuffer, item) {
  for(int i = 0; i < size-1; i++)
  {
    EXPECT_TRUE(buffer->enqueue(i));
  }
  for(int i = 0; i < size-1; i++)
  {
    EXPECT_EQ(i, *buffer->item(i));
  }
  EXPECT_EQ(NULL, buffer->item(size));
  EXPECT_EQ(NULL, buffer->item(size-1));
}

/*
 * Test enqueue some elements and peek to confirm values
 */
TEST_F(TCircularBuffer, peek) {
  EXPECT_TRUE(buffer->enqueue(0));
  EXPECT_EQ(0, *buffer->peek());
  EXPECT_TRUE(buffer->enqueue(1));
  EXPECT_EQ(0, *buffer->peek());
  EXPECT_TRUE(buffer->dequeue());
  EXPECT_EQ(1, *buffer->peek());
  EXPECT_TRUE(buffer->dequeue());
  EXPECT_EQ(NULL, buffer->peek());
}

/*
 * Test if capacity is correct
 */
TEST_F(TCircularBuffer, capacity){
  EXPECT_EQ(size, buffer->capacity());
}

/*
 * Test if size is changed correctly
 */
TEST_F(TCircularBuffer, size){
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer->enqueue(i));
    EXPECT_EQ(i+1, buffer->size());
  }
}

/*
 * Test if queue is empty on multiple cases
 */
TEST_F(TCircularBuffer, is_empty) {
  EXPECT_TRUE(buffer->is_empty());
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer->enqueue(i));
    EXPECT_FALSE(buffer->is_empty());
  }
}

/*
 * Test if queue is full on multiple cases
 */
TEST_F(TCircularBuffer, is_full) {
  for(int i = 0; i < size; i++)
  {
    EXPECT_FALSE(buffer->is_full());
    EXPECT_TRUE(buffer->enqueue(i));
  }
  EXPECT_TRUE(buffer->is_full());
}
