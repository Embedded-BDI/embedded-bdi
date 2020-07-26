/*
 * body_instruction_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body_instruction.h"
#include "../data/test_data.h"

class TBodyInstruction : public ::testing::Test
{
protected:
  BodyInstruction * action;
  BodyInstruction * belief_operation;
  BodyInstruction * goal;
  BeliefBase * belief_base;
  EventBase * event_base;
  int bases_size = 2;

public:
  TBodyInstruction()
  {
    belief_base = new BeliefBase(bases_size);
    event_base = new EventBase(bases_size);

    Statement stm_a('a');
    Statement stm_b('b');
    Belief belief_a(stm_a, NULL, false);
    Belief belief_b(stm_b, NULL, false);
    belief_base->add_belief(belief_a);
    belief_base->add_belief(belief_b);

    action = new BodyInstruction(BodyType::ACTION, stm_a, function_action_true);
    belief_operation = new BodyInstruction(BodyType::BELIEF, stm_a, EventOperator::BELIEF_ADDITION);
    goal = new BodyInstruction(BodyType::GOAL, stm_a, EventOperator::GOAL_ADDITION);
  }

  ~TBodyInstruction()
  {
    delete action;
    delete belief_operation;
    delete goal;
  }
};

TEST_F(TBodyInstruction, run_instruction)
{
  BodyReturn action_result = action->run_instruction(belief_base, event_base);
  BodyReturn belief_operation_result = belief_operation->run_instruction(belief_base, event_base);
  BodyReturn goal_result = goal->run_instruction(belief_base, event_base);

  EXPECT_TRUE(action_result.get_value());
  EXPECT_TRUE(belief_operation_result.get_value());
  EXPECT_TRUE(goal_result.get_value());

  EXPECT_EQ(BodyType::ACTION, action_result.get_type());
  EXPECT_EQ(BodyType::BELIEF, belief_operation_result.get_type());
  EXPECT_EQ(BodyType::GOAL, goal_result.get_type());

  EXPECT_TRUE(NULL == action_result.get_event());
  EXPECT_TRUE(NULL != belief_operation_result.get_event());
  EXPECT_TRUE(NULL != goal_result.get_event());

  Statement stm('a');
  EXPECT_TRUE(belief_base->get_belief_state(stm));

  EXPECT_TRUE(event_base->is_full());
}
