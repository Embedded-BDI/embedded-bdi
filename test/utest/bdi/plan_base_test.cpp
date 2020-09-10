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
  Statement stm(0);
  Plan plan(EventOperator::BELIEF_ADDITION, stm, nullptr, nullptr);

  for (int i = 0; i < PLAN_BASE_SIZE; i++)
  {
    EXPECT_TRUE(plan_base->add_plan(plan));
  }

  EXPECT_FALSE(plan_base->add_plan(plan));
  EXPECT_EQ(PLAN_BASE_SIZE, plan_base->get_size());
}

TEST_F(TPlanBase, revise)
{
  Statement stm_0(0);
  Statement stm_1(1);

  BeliefBase belief_base(2);
  Belief belief_a(stm_0, nullptr, false);
  Belief belief_b(stm_1, nullptr, false);
  belief_base.add_belief(belief_a);
  belief_base.add_belief(belief_b);

  Event event_valid(EventOperator::BELIEF_ADDITION, stm_0);
  Event event_without_plans(EventOperator::BELIEF_ADDITION, stm_1);

  Context context_valid(0);
  Context context_invalid(1);
  ContextCondition ctx(stm_0, true);
  context_invalid.add_context(ctx);

  Plan plan_context_invalid(EventOperator::BELIEF_ADDITION,
                            stm_0,
                            &context_invalid,
                            nullptr);
  Plan plan_valid(EventOperator::BELIEF_ADDITION,
                  stm_0,
                  &context_valid,
                  nullptr);

  plan_base->add_plan(plan_context_invalid);
  plan_base->add_plan(plan_valid);

  Plan * p_null;
  Plan * p_plan;

  p_null = plan_base->revise(&event_without_plans, &belief_base);
  p_plan = plan_base->revise(&event_valid, &belief_base);

  EXPECT_TRUE(nullptr == p_null);
  EXPECT_TRUE(nullptr != p_plan);

  EXPECT_EQ(plan_valid.get_operator(), p_plan->get_operator());
  EXPECT_TRUE(plan_valid.get_statement()->is_equal(p_plan->get_statement()));
  EXPECT_EQ(plan_valid.get_context(), p_plan->get_context());
  EXPECT_EQ(plan_valid.get_body(), p_plan->get_body());
}
