/*
 * body_instruction_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body/body_instruction.h"

bool take_action(BeliefBase * belief_base)
{
  return true;
}

class TBodyInstruction : public ::testing::Test
{
protected:
  BodyInstruction * action;
  BodyInstruction * belief_operation;
  BodyInstruction * goal;
  BeliefBase * belief_base;
  EventBase * event_base;
  int size = 2;
  char alphabet[2] = {'a', 'b'};

public:
  TBodyInstruction()
  {
    belief_base = new BeliefBase(size);
    event_base = new EventBase(size);

    for (int i = 0; i < size; i++)
    {
      Statement stm(alphabet[i]);
      Belief belief(stm, NULL, false);
      belief_base->add_belief(belief);
    }

    Statement stm(alphabet[0]);
    action = new BodyInstruction(BodyType::ACTION, stm, take_action);
    belief_operation = new BodyInstruction(BodyType::BELIEF, stm, EventOperator::BELIEF_ADDITION);
    goal = new BodyInstruction(BodyType::GOAL, stm, EventOperator::GOAL_ADDITION);
  }

  virtual ~TBodyInstruction()
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

  Statement stm(alphabet[0]);
  EXPECT_TRUE(belief_base->get_belief_state(stm));

  EXPECT_TRUE(event_base->is_full());
}
