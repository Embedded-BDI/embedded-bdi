/*
 * context_test.cpp
 *
 *  Created on: Jul 23, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/context.h"
#include <vector>

class TContext : public ::testing::Test
{
protected:
  BeliefBase * belief_base;
  Context * context;
  std::vector<ContextCondition> cxt_c;
  ContextCondition * cond_1;
  ContextCondition * cond_2;
  ContextCondition * cond_3;
  int size = 3;

public:
  TContext()
  {
    context = new Context(size);
    belief_base = new BeliefBase(size);

    Statement stm_a('a');
    Statement stm_b('b');
    Statement stm_c('c');

    cond_1 = new ContextCondition(stm_a, true);
    cond_2 = new ContextCondition(stm_b, true);
    cond_3 = new ContextCondition(stm_c, false);

    Belief belief_a(stm_a, NULL, true);
    Belief belief_b(stm_b, NULL, true);
    Belief belief_c(stm_c, NULL, false);

    belief_base->add_belief(belief_a);
    belief_base->add_belief(belief_b);
    belief_base->add_belief(belief_c);
  }

  ~TContext()
  {
    delete context;
  }
};

/*
 * Test add_belief method
 */
TEST_F(TContext, add_belief)
{
  EXPECT_TRUE(context->add_belief(*cond_1));
  EXPECT_TRUE(context->add_belief(*cond_2));
  EXPECT_TRUE(context->add_belief(*cond_3));
  EXPECT_FALSE(context->add_belief(*cond_1));
}

/*
 * Test if context is properly checked/validated
 */
TEST_F(TContext, is_valid)
{
  context->add_belief(*cond_1);
  context->add_belief(*cond_2);
  context->add_belief(*cond_3);

  EXPECT_TRUE(context->is_valid(belief_base));
}
