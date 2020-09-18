/*
 * context_test.cpp
 *
 *  Created on: Jul 23, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/context.h"

#define SIZES 3

class TContext : public ::testing::Test
{
protected:
  BeliefBase * belief_base;
  Context * context;
  Context * context_empty;
  ContextCondition * cond_1;
  ContextCondition * cond_2;
  ContextCondition * cond_3;

public:
  TContext()
  {
    context = new Context(SIZES);
    context_empty = new Context(SIZES);
    belief_base = new BeliefBase(SIZES);

    Statement stm_0(0);
    Statement stm_1(1);
    Statement stm_2(2);

    cond_1 = new ContextCondition(stm_0, true);
    cond_2 = new ContextCondition(stm_1, true);
    cond_3 = new ContextCondition(stm_2, false);

    Belief belief_a(stm_0, nullptr, true);
    Belief belief_b(stm_1, nullptr, true);
    Belief belief_c(stm_2, nullptr, false);

    belief_base->add_belief(belief_a);
    belief_base->add_belief(belief_b);
    belief_base->add_belief(belief_c);
  }

  ~TContext()
  {
    delete context;
    delete context_empty;
  }
};

/*
 * Test add_belief method
 */
TEST_F(TContext, add_belief)
{
  EXPECT_TRUE(context->add_context(*cond_1));
  EXPECT_TRUE(context->add_context(*cond_2));
  EXPECT_TRUE(context->add_context(*cond_3));
  EXPECT_FALSE(context->add_context(*cond_1));
}

/*
 * Test if context is properly checked/validated
 */
TEST_F(TContext, is_valid)
{
  context->add_context(*cond_1);
  context->add_context(*cond_2);
  context->add_context(*cond_3);

  EXPECT_TRUE(context->is_valid(belief_base));
}
