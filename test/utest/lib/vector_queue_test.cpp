/*
 * vector_queue_test.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "lib/vector_queue.h"

class TVectorQueue : public ::testing::Test
{
protected:
  VectorQueue<int> queue;
  int MAX_SIZE = 5;      // 2 or higher

public:
  TVectorQueue()
  {
    queue.init(MAX_SIZE);
  }
};

TEST_F(TVectorQueue, push_front)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_front(i);
    EXPECT_EQ(i, *queue.front());
    EXPECT_EQ(0, *queue.back());
  }
}

TEST_F(TVectorQueue, push_back)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
    EXPECT_EQ(0, *queue.front());
    EXPECT_EQ(i, *queue.back());
  }
}

TEST_F(TVectorQueue, pop_back)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
  }

  for (int i = MAX_SIZE-1; i >= 0; i--)
  {
    EXPECT_EQ(i, *queue.back());
    queue.pop_back();
  }

  EXPECT_TRUE(queue.is_empty());
}

TEST_F(TVectorQueue, item_at)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
    EXPECT_EQ(i, *queue.item_at(i));
  }
}

TEST_F(TVectorQueue, erase)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
  }

  for (int i = MAX_SIZE-1; i >= 0; i--)
  {
    EXPECT_EQ(i, *queue.back());
    queue.erase(i);
  }

  EXPECT_TRUE(queue.is_empty());

  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
  }

  for (int i = 0; i < MAX_SIZE; i++)
  {
    EXPECT_EQ(i, *queue.front());
    queue.erase(0);
  }

  EXPECT_TRUE(queue.is_empty());
}

TEST_F(TVectorQueue, rotate)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
  }

  queue.rotate();

  EXPECT_EQ(MAX_SIZE-1, *queue.front());
  EXPECT_EQ(MAX_SIZE-2, *queue.back());
}

TEST_F(TVectorQueue, size)
{
  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
    EXPECT_EQ(i+1, queue.size());
  }
}

TEST_F(TVectorQueue, is_empty)
{
  EXPECT_TRUE(queue.is_empty());

  for (int i = 0; i < MAX_SIZE; i++)
  {
    queue.push_back(i);
    EXPECT_FALSE(queue.is_empty());
  }

  for (int i = MAX_SIZE-1; i >= 0; i--)
  {
    EXPECT_FALSE(queue.is_empty());
    queue.erase(i);
  }

  EXPECT_TRUE(queue.is_empty());
}

TEST_F(TVectorQueue, is_full)
{
  EXPECT_FALSE(queue.is_full());

  for (int i = 0; i < MAX_SIZE; i++)
  {
    EXPECT_FALSE(queue.is_full());
    queue.push_back(i);
  }

  EXPECT_TRUE(queue.is_full());

  for (int i = MAX_SIZE-1; i >= 0; i--)
  {
    queue.erase(i);
    EXPECT_FALSE(queue.is_full());
  }
}
