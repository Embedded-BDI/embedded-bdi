/*
 * instantiated_plan_test.cpp
 *
 *  Created on: Jul 28, 2020
 *      Author: Matuzalem Muller
 */

#include "common_lib.h"
#include "gtest/gtest.h"
#include "bdi/instantiated_plan.h"

#define BODY_SIZE 3
#define BASES_SIZE 3

class TInstantiatedPlan : public ::testing::Test
{
protected:
  BeliefBase * belief_base;
  EventBase * event_base_empty;
  EventBase * event_base_full;
  InstantiatedPlan * inst_plan;

public:
  TInstantiatedPlan()
  {
    belief_base = new BeliefBase(BASES_SIZE);
    event_base_empty = new EventBase(BASES_SIZE);
    event_base_full = new EventBase(BASES_SIZE);

    Statement event('e');
    for (int i = 0; i < BASES_SIZE; i++)
    {
      Event event_e(EventOperator::BELIEF_ADDITION, event);
      event_base_full->add_event(event_e);
    }

    Statement stm_0(0);
    Statement stm_1(1);
    Statement stm_2(2);
    Statement stm_3(3);

    Context * ctx = new Context(0);

    BodyInstruction body_a(BodyType::ACTION,
                           stm_1,
                           return_true_beliefbase);
    BodyInstruction body_b(BodyType::BELIEF,
                           stm_2,
                           EventOperator::BELIEF_ADDITION);
    BodyInstruction body_g(BodyType::GOAL,
                           stm_3,
                           EventOperator::GOAL_ADDITION);

    Body * body = new Body(BODY_SIZE);
    body->add_instruction(body_a);
    body->add_instruction(body_b);
    body->add_instruction(body_g);

    Plan * plan = new Plan(EventOperator::BELIEF_ADDITION, stm_0, ctx, body);

    inst_plan = new InstantiatedPlan(plan);
  }

  ~TInstantiatedPlan()
  {
    delete belief_base;
    delete event_base_empty;
    delete event_base_full;
    delete inst_plan;
  }
};

TEST_F(TInstantiatedPlan, run_plan_empty_event_base)
{
  BodyReturn action = inst_plan->run_plan(belief_base, event_base_empty);
  BodyReturn belief = inst_plan->run_plan(belief_base, event_base_empty);
  BodyReturn goal = inst_plan->run_plan(belief_base, event_base_empty);
  BodyReturn invalid = inst_plan->run_plan(belief_base, event_base_empty);

  EXPECT_EQ(BodyType::ACTION, action.get_type());
  EXPECT_TRUE(action.get_value());
  EXPECT_TRUE(nullptr == action.get_event());

  EXPECT_EQ(BodyType::BELIEF, belief.get_type());
  EXPECT_TRUE(belief.get_value());
  EXPECT_TRUE(nullptr != belief.get_event());

  EXPECT_EQ(BodyType::GOAL, goal.get_type());
  EXPECT_TRUE(goal.get_value());
  EXPECT_TRUE(nullptr != goal.get_event());

  EXPECT_EQ(BodyType::ACTION, invalid.get_type());
  EXPECT_FALSE(invalid.get_value());
  EXPECT_TRUE(nullptr == invalid.get_event());
}

TEST_F(TInstantiatedPlan, run_plan_full_event_base)
{
  BodyReturn action = inst_plan->run_plan(belief_base, event_base_full);
  BodyReturn belief = inst_plan->run_plan(belief_base, event_base_full);
  BodyReturn goal = inst_plan->run_plan(belief_base, event_base_full);
  BodyReturn invalid = inst_plan->run_plan(belief_base, event_base_full);

  EXPECT_EQ(BodyType::ACTION, action.get_type());
  EXPECT_TRUE(action.get_value());
  EXPECT_TRUE(nullptr == action.get_event());

  EXPECT_EQ(BodyType::BELIEF, belief.get_type());
  EXPECT_FALSE(belief.get_value());
  EXPECT_TRUE(nullptr == belief.get_event());

  EXPECT_EQ(BodyType::GOAL, goal.get_type());
  EXPECT_FALSE(goal.get_value());
  EXPECT_TRUE(nullptr == goal.get_event());

  EXPECT_EQ(BodyType::ACTION, invalid.get_type());
  EXPECT_FALSE(invalid.get_value());
  EXPECT_TRUE(nullptr == invalid.get_event());
}

TEST_F(TInstantiatedPlan, is_finished)
{
  EXPECT_FALSE(inst_plan->is_finished());
  inst_plan->run_plan(belief_base, event_base_empty);
  EXPECT_FALSE(inst_plan->is_finished());
  inst_plan->run_plan(belief_base, event_base_empty);
  EXPECT_FALSE(inst_plan->is_finished());
  inst_plan->run_plan(belief_base, event_base_empty);
  EXPECT_TRUE(inst_plan->is_finished());
  inst_plan->run_plan(belief_base, event_base_empty);
  EXPECT_TRUE(inst_plan->is_finished());
}
