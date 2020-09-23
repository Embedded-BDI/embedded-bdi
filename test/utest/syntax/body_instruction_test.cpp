/*
 * body_instruction_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "common_lib.h"
#include "gtest/gtest.h"
#include "syntax/body_instruction.h"

#define BASES_SIZE 2

class TBodyInstruction : public ::testing::Test
{
protected:
  BodyInstruction * action_true;
  BodyInstruction * action_false;
  BodyInstruction * belief_operation;
  BodyInstruction * goal;
  BeliefBase * bb;
  EventBase * eb;

public:
  TBodyInstruction()
  {
    bb = new BeliefBase(BASES_SIZE);
    eb = new EventBase(BASES_SIZE);

    Statement stm_0(0);
    Statement stm_1(1);
    Belief belief_a(stm_0, nullptr, false);
    Belief belief_b(stm_1, nullptr, false);
    bb->add_belief(belief_a);
    bb->add_belief(belief_b);

    action_true = new BodyInstruction(BodyType::ACTION,
                                 stm_0,
                                 return_true_beliefbase);

    action_false = new BodyInstruction(BodyType::ACTION,
                                       stm_0,
                                       return_false_beliefbase);

    belief_operation = new BodyInstruction(BodyType::BELIEF,
                                           stm_0,
                                           EventOperator::BELIEF_ADDITION);

    goal = new BodyInstruction(BodyType::GOAL,
                               stm_0,
                               EventOperator::GOAL_ADDITION);
  }

  ~TBodyInstruction()
  {
    delete action_true;
    delete action_false;
    delete belief_operation;
    delete goal;
  }
};

/*
 * Test running instruction for all intructions types
 */
TEST_F(TBodyInstruction, run_instruction)
{
  BodyReturn action_true_result = action_true->run_instruction(bb, eb);
  BodyReturn action_false_result = action_false->run_instruction(bb, eb);
  BodyReturn belief_op_result = belief_operation->run_instruction(bb, eb);
  BodyReturn goal_result = goal->run_instruction(bb, eb);

  EXPECT_TRUE(action_true_result.get_value());
  EXPECT_FALSE(action_false_result.get_value());
  EXPECT_TRUE(belief_op_result.get_value());
  EXPECT_TRUE(goal_result.get_value());

  EXPECT_EQ(BodyType::ACTION, action_true_result.get_type());
  EXPECT_EQ(BodyType::ACTION, action_false_result.get_type());
  EXPECT_EQ(BodyType::BELIEF, belief_op_result.get_type());
  EXPECT_EQ(BodyType::GOAL, goal_result.get_type());

  EXPECT_TRUE(nullptr == action_true_result.get_event());
  EXPECT_TRUE(nullptr == action_false_result.get_event());
  EXPECT_TRUE(nullptr != belief_op_result.get_event());
  EXPECT_TRUE(nullptr != goal_result.get_event());

  Statement stm(0);
  EXPECT_TRUE(bb->get_belief_state(stm));

  EXPECT_TRUE(eb->is_full());
}
