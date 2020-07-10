/*
 * goal_test.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body/goal.h"

class TGoal : public ::testing::Test
{
protected:
  Goal * goal;
  Statement * stm;
  BeliefBase * bb;
  EventBase * eb;
  int belief_base_size = 2;
  int event_base_size = 2;

public:
  TGoal()
  {
    stm = new Statement('a');

    bb = new BeliefBase(belief_base_size);
    eb = new EventBase(event_base_size);

    goal = new Goal(*stm, EventOperator::GOAL_ADDITION);
  }

  virtual ~TGoal()
  {
    delete goal;
    delete stm;
    delete bb;
    delete eb;
  }
};

/*
 * Test run instruction return
 */
TEST_F(TGoal, run_instruction)
{
  for (int i = 0; i < event_base_size; i ++)
  {
    EXPECT_TRUE(goal->run_instruction(bb, eb));
  }
  EXPECT_TRUE(eb->is_full());
  EXPECT_FALSE(goal->run_instruction(bb, eb));
  for (int i = 0; i < event_base_size; i++)
  {
    EXPECT_TRUE(stm->is_equal(eb->get_event()->get_statement()));
  }
}

/*
 * Test body type return
 */
TEST_F(TGoal, get_BodyType)
{
  EXPECT_EQ(BodyType::GOAL, goal->get_BodyType());
}

/*
 * Test operator return
 */
TEST_F(TGoal, get_operator)
{
  EXPECT_EQ(EventOperator::GOAL_ADDITION, goal->get_operator());
}

/*
 * Test statement return
 */
TEST_F(TGoal, get_statement)
{
  Statement stm('a');
  EXPECT_TRUE(goal->get_statement().is_equal(stm));
}
