/*
 * plan_base_test.cpp
 *
 *  Created on: Jul 26, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/plan_base.h"

#define PLAN_BASE_SIZE 3

class TPlanBase : public ::testing::Test
{
protected:
  PlanBase * plan_base;

public:

  TPlanBase()
  {
    plan_base = new PlanBase(PLAN_BASE_SIZE);
  }

  ~TPlanBase()
  {
    delete plan_base;
  }
};

TEST_F(TPlanBase, add_plan)
{
  Statement stm('a');
  Plan plan(EventOperator::BELIEF_ADDITION, stm, NULL, NULL);

  for (int i = 0; i < PLAN_BASE_SIZE; i++)
  {
    plan_base->add_plan(plan);
  }

  EXPECT_EQ(PLAN_BASE_SIZE, plan_base->get_size());
}

TEST_F(TPlanBase, revise)
{
  Statement stm_a('a');
  Statement stm_b('b');

  BeliefBase belief_base(2);
  Belief belief_a(stm_a, NULL, false);
  Belief belief_b(stm_b, NULL, false);
  belief_base.add_belief(belief_a);
  belief_base.add_belief(belief_b);

  Event event_valid(EventOperator::BELIEF_ADDITION, stm_a);
  Event event_without_plans(EventOperator::BELIEF_ADDITION, stm_b);

  Context context_valid(0);
  Context context_invalid(1);
  ContextCondition ctx(stm_a, true);
  context_invalid.add_belief(ctx);

  Plan plan_context_invalid(EventOperator::BELIEF_ADDITION,
                            stm_a,
                            &context_invalid,
                            NULL);
  Plan plan_valid(EventOperator::BELIEF_ADDITION,
                  stm_a,
                  &context_valid,
                  NULL);

  plan_base->add_plan(plan_context_invalid);
  plan_base->add_plan(plan_valid);

  EXPECT_TRUE(NULL == plan_base->revise(&event_without_plans, &belief_base));
  EXPECT_TRUE(NULL != plan_base->revise(&event_valid, &belief_base));
}
