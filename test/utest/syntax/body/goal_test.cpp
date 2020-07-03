/*
 * goal_test.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body/goal.h"

class TGoal : public ::testing::Test {
protected:
  Goal * goal;
  int belief_base_size = 2;
  int event_base_size = 2;
  BeliefBase * bb;
  EventBase * eb;

public:
  TGoal() {
    Statement stm('a');
    bb = new BeliefBase(belief_base_size);
    eb = new EventBase(event_base_size);

    goal = new Goal(stm, EventOperator::EventType::GOAL_ADDITION, bb, eb);
  }

  virtual ~TGoal() {
    delete goal;
    delete bb;
    delete eb;
  }
};

/*
 * Test run instruction return
 */
TEST_F(TGoal, run_instruction) {
  for (int i = 0; i < event_base_size; i ++)
  {
    EXPECT_TRUE(goal->run_instruction());
  }
  EXPECT_TRUE(eb->is_full());
  EXPECT_FALSE(goal->run_instruction());
}

/*
 * Test body type return
 */
TEST_F(TGoal, get_BodyType) {
  EXPECT_EQ(IBodyInstruction::BodyType::GOAL, goal->get_BodyType());
}

/*
 * Test operator return
 */
TEST_F(TGoal, get_operator) {
  EXPECT_EQ(EventOperator::EventType::GOAL_ADDITION, goal->get_operator());
}

/*
 * Test statement return
 */
TEST_F(TGoal, get_statement) {
  Statement stm('a');
  EXPECT_TRUE(goal->get_statement().is_equal_to(stm));
}
