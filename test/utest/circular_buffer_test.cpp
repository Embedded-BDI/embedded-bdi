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
  CircularBuffer<int> buffer;
  int size = 4;                                 // size must be 2 or higher

public:
  TCircularBuffer() {
    buffer.init(this->size);
  }

  virtual ~TCircularBuffer() {}
};

/*
 * Test enqueue elements until queue is full
 */
TEST_F(TCircularBuffer, enqueue_until_full) {
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer.enqueue(i));
  }
  EXPECT_TRUE(buffer.is_full());
  EXPECT_EQ(buffer.size(), size);
  EXPECT_FALSE(buffer.enqueue(size));
}

/*
 * Test enqueue and dequeue elements and confirm that queue is empty
 */
TEST_F(TCircularBuffer, dequeue_until_empty) {
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer.enqueue(i));
  }
  for(int i = size-1; i >= 0; i--)
  {
    EXPECT_TRUE(buffer.dequeue());
    EXPECT_EQ(i, buffer.size());
  }
  EXPECT_TRUE(buffer.is_empty());
  EXPECT_FALSE(buffer.dequeue());
}

/*
 * Test enqueue some elements and peek to confirm values
 */
TEST_F(TCircularBuffer, peek) {
  EXPECT_TRUE(buffer.enqueue(0));
  EXPECT_EQ(0, *buffer.peek());
  EXPECT_TRUE(buffer.enqueue(1));
  EXPECT_EQ(0, *buffer.peek());
  EXPECT_TRUE(buffer.dequeue());
  EXPECT_EQ(1, *buffer.peek());
  EXPECT_TRUE(buffer.dequeue());
  EXPECT_EQ(NULL, buffer.peek());
}

/*
 * Test enqueue some elements and query by index to confirm values
 */
TEST_F(TCircularBuffer, query_item) {
  for(int i = 0; i < size-1; i++)
  {
    EXPECT_TRUE(buffer.enqueue(i));
  }
  for(int i = 0; i < size-1; i++)
  {
    EXPECT_EQ(i, *buffer.item(i));
  }
  EXPECT_EQ(NULL, buffer.item(size-1));
}

TEST_F(TCircularBuffer, size){
  for(int i = 0; i < size; i++)
  {
    EXPECT_TRUE(buffer.enqueue(i));
    EXPECT_EQ(i+1, buffer.size());
  }
}

TEST_F(TCircularBuffer, capacity){
  EXPECT_EQ(size, buffer.capacity());
}
