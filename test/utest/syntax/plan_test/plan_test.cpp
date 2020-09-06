/*
 * plan_test.cpp
 *
 *  Created on: Jul 25, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/plan.h"
#include "test_plan_data.h"

#define CONTEXT_SIZE 1
#define BELIEF_BASE_SIZE 1
#define EVENT_BASE_SIZE 2
#define BODY_SIZE 2

class TPlan : public ::testing::Test
{
protected:
  TestPlanData * test_data;

  EventOperator event_operator;
  Statement stm;
  Context * context_valid;

  Plan * plan_valid;
  Plan * plan_action;
  Plan * plan_belief;
  Plan * plan_goal;

public:
  TPlan()
  {
    test_data = new TestPlanData(BODY_SIZE,
                                 BELIEF_BASE_SIZE,
                                 EVENT_BASE_SIZE);
    stm = test_data->get_stm();

    event_operator = EventOperator::GOAL_ADDITION;
    context_valid = new Context(CONTEXT_SIZE);

    // Valid plan
    plan_valid = new Plan(event_operator,
                          stm,
                          context_valid,
                          test_data->get_body_valid());

    // Plan that fails due to failure in action
    plan_action = new Plan(event_operator,
                           stm,
                           context_valid,
                           test_data->get_body_action_fails());

    // Plan that fails due to full EventBase and belief event cannot be created
    plan_belief = new Plan(event_operator,
                           stm,
                           context_valid,
                           test_data->get_body_belief_fails());

    // Plan that fails due to full EventBase and goal event cannot be created
    plan_goal = new Plan(event_operator,
                         stm,
                         context_valid,
                         test_data->get_body_goal_fails());
  }

  ~TPlan()
  {
    delete test_data;
    delete plan_valid;
    delete plan_action;
    delete plan_belief;
    delete plan_goal;
  }
};

TEST_F(TPlan, get_operator) {
  EXPECT_EQ(EventOperator::GOAL_ADDITION, plan_valid->get_operator());
}

TEST_F(TPlan, get_statement) {
  EXPECT_TRUE(plan_valid->get_statement()->is_equal(stm));
}

TEST_F(TPlan, get_context) {
  EXPECT_EQ(context_valid, plan_valid->get_context());
}

TEST_F(TPlan, get_body)
{
  EXPECT_EQ(test_data->get_body_valid(), plan_valid->get_body());
}

TEST_F(TPlan, run_body)
{
  BodyReturn result;

  for (int i = 0; i < plan_valid->get_body()->get_size(); i++)
  {
    result = plan_valid->run_body(i,
                                  test_data->get_belief_base_empty(),
                                  test_data->get_event_base_empty());
    EXPECT_TRUE(result.get_value());
  }

  for (int i = 0; i < plan_valid->get_body()->get_size(); i++)
  {
    result = plan_action->run_body(i,
                                   test_data->get_belief_base_empty(),
                                   test_data->get_event_base_empty());
    EXPECT_FALSE(result.get_value());
  }

  for (int i = 0; i < plan_valid->get_body()->get_size(); i++)
  {
    result = plan_belief->run_body(i,
                                   test_data->get_belief_base_empty(),
                                   test_data->get_event_base_empty());
    EXPECT_TRUE(result.get_value());
  }

  for (int i = 0; i < plan_valid->get_body()->get_size(); i++)
  {
    result = plan_belief->run_body(i,
                                   test_data->get_belief_base_empty(),
                                   test_data->get_event_base_full());
    EXPECT_FALSE(result.get_value());
  }

  for (int i = 0; i < plan_valid->get_body()->get_size(); i++)
  {
    result = plan_goal->run_body(i,
                                 test_data->get_belief_base_empty(),
                                 test_data->get_event_base_empty());
    EXPECT_TRUE(result.get_value());
  }

  for (int i = 0; i < plan_valid->get_body()->get_size(); i++)
  {
    result = plan_goal->run_body(i,
                                 test_data->get_belief_base_empty(),
                                 test_data->get_event_base_full());
    EXPECT_FALSE(result.get_value());
  }

  EXPECT_TRUE(test_data->get_event_base_empty()->is_full());
}
