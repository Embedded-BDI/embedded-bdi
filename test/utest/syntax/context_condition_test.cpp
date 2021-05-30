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
    Proposition prop_0(0);
    context_condition_true = new ContextCondition(prop_0);
  }

  ~TContextCondition()
  {
    delete context_condition_true;
  }
};

/*
 * Test return of get_proposition
 */
TEST_F(TContextCondition, get_proposition)
{
  Proposition prop_0(0);
  EXPECT_TRUE(context_condition_true->get_proposition().is_equal(prop_0));
}
