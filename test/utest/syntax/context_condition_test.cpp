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

public:
  TContextCondition()
  {
    Statement stm_0(0);
    context_condition_true = new ContextCondition(stm_0);
  }

  ~TContextCondition()
  {
    delete context_condition_true;
  }
};

/*
 * Test return of get_statement
 */
TEST_F(TContextCondition, get_statement)
{
  Statement stm_0(0);
  EXPECT_TRUE(context_condition_true->get_statement().is_equal(stm_0));
}
