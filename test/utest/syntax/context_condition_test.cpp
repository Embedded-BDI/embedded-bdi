/*
 * context_condition_test.cpp
 *
 *  Created on: Jul 23, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/context_condition.h"

class TContextCondition : public ::testing::Test
{
protected:
  ContextCondition * context_condition_true;
  ContextCondition * context_condition_false;

public:
  TContextCondition()
  {
    Statement stm_0(0);
    Statement stm_1(1);
    context_condition_true = new ContextCondition(stm_0, true);
    context_condition_false = new ContextCondition(stm_1, false);
  }

  ~TContextCondition()
  {
    delete context_condition_true;
    delete context_condition_false;
  }
};

/*
 * Test return of is_true
 */
TEST_F(TContextCondition, is_true)
{
  EXPECT_TRUE(context_condition_true->is_true());
  EXPECT_FALSE(context_condition_false->is_true());
}

/*
 * Test return of get_statement
 */
TEST_F(TContextCondition, get_statement)
{
  Statement stm_0(0);
  Statement stm_1(1);
  EXPECT_TRUE(context_condition_true->get_statement().is_equal(stm_0));
  EXPECT_TRUE(context_condition_false->get_statement().is_equal(stm_1));
}
