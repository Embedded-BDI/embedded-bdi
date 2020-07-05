/*
 * action_test.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body/action.h"

bool take_action_true(BeliefBase * belief_base)
{
  return true;
}

bool take_action_false(BeliefBase * belief_base)
{
  return false;
}

class TAction : public ::testing::Test
{
protected:
  Action * action_true;
  Action * action_false;
  BeliefBase * bb;
  EventBase * eb;
  int belief_base_size = 2;
  int event_base_size = 2;

public:
  TAction()
  {
    Statement stm_a('a');
    Statement stm_b('b');

    bb = new BeliefBase(belief_base_size);
    eb = new EventBase(event_base_size);

    this->action_true = new Action(stm_a, take_action_true);
    this->action_false = new Action(stm_b, take_action_false);
  }

  virtual ~TAction()
  {
    delete action_true;
    delete action_false;
    delete bb;
    delete eb;
  }
};

/*
 * Test run instruction return
 */
TEST_F(TAction, run_instruction)
{
  EXPECT_TRUE(action_true->run_instruction(bb, eb));
  EXPECT_FALSE(action_false->run_instruction(bb, eb));
}

/*
 * Test body type return
 */
TEST_F(TAction, get_body_type)
{
  EXPECT_EQ(BodyType::ACTION, action_true->get_BodyType());
  EXPECT_EQ(BodyType::ACTION, action_false->get_BodyType());
}
