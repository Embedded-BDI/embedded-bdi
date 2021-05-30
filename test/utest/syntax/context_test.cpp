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

    Proposition prop_0(0);
    Proposition prop_1(1);
    Proposition prop_2(2);

    cond_1 = new ContextCondition(prop_0);
    cond_2 = new ContextCondition(prop_1);
    cond_3 = new ContextCondition(prop_2);

    Belief belief_a(prop_0, nullptr, true);
    Belief belief_b(prop_1, nullptr, true);
    Belief belief_c(prop_2, nullptr, true);

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

  Proposition prop_0(0);
  belief_base->change_belief_state(prop_0, false);
  EXPECT_FALSE(context->is_valid(belief_base));
}
