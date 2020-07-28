/*
 * stack_test.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "lib/stack.h"

#define STACK_SIZE 4

class TStack : public ::testing::Test
{
protected:
  Stack<int> * stack;

public:
  TStack()
  {
    stack = new Stack<int>(STACK_SIZE);
  }

  ~TStack()
  {
    delete stack;
  }
};

/*
 * Test push elements and confirm that stack is full
 */
TEST_F(TStack, push)
{
  for(int i = 0; i < STACK_SIZE; i++)
  {
    EXPECT_TRUE(stack->push(i));
  }
  EXPECT_FALSE(stack->push(0));
}

/*
 * Test pop elements and confirm that stack is empty
 */
TEST_F(TStack, pop)
{
  for(int i = 0; i < STACK_SIZE; i++)
  {
    EXPECT_TRUE(stack->push(i));
  }
  for(int i = STACK_SIZE-1; i >= 0; i--)
  {
    EXPECT_EQ(i, *stack->pop());
  }
  EXPECT_EQ(NULL, stack->pop());
}

/*
 * Test peeking elements and compare with expected elements
 */
TEST_F(TStack, peek)
{
  for(int i = 0; i < STACK_SIZE; i++)
  {
    EXPECT_TRUE(stack->push(i));
    EXPECT_EQ(i, *stack->peek());
  }
  for(int i = STACK_SIZE-1; i >= 0; i--)
  {
    EXPECT_EQ(i, *stack->peek());
    EXPECT_EQ(i, *stack->pop());
  }
}

/*
 * Test if STACK_SIZE is changed correctly
 */
TEST_F(TStack, STACK_SIZE) {
  for(int i = 1; i <= STACK_SIZE; i++)
  {
    EXPECT_TRUE(stack->push(i));
    EXPECT_EQ(i, stack->size());
  }
}

/*
 * Test if stack is empty on multiple cases
 */
TEST_F(TStack, is_empty) {
  EXPECT_TRUE(stack->is_empty());
  for(int i = 0; i < STACK_SIZE; i++)
  {
    EXPECT_TRUE(stack->push(i));
    EXPECT_FALSE(stack->is_empty());
  }
}

/*
 * Test if stack is full on multiple cases
 */
TEST_F(TStack, is_full) {
  for(int i = 0; i < STACK_SIZE; i++)
  {
    EXPECT_FALSE(stack->is_full());
    EXPECT_TRUE(stack->push(i));
  }
  EXPECT_TRUE(stack->is_full());
}
