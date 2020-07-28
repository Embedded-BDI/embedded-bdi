/*
 * body_return_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body_return.h"

class TBodyReturn : public ::testing::Test
{
protected:
  BodyReturn * body_return_action;
  BodyReturn * body_return_belief;
  BodyReturn * body_return_goal;
  EventID * event_id;

public:
  TBodyReturn()
  {
    event_id = new EventID();
    body_return_action = new BodyReturn(BodyType::ACTION, true, event_id);
    body_return_belief = new BodyReturn(BodyType::BELIEF, true, event_id);
    body_return_goal = new BodyReturn(BodyType::GOAL, false, event_id);
  }

  ~TBodyReturn()
  {
    delete body_return_action;
    delete body_return_belief;
    delete body_return_goal;
    delete event_id;
  }
};

TEST_F(TBodyReturn, get_event)
{
  EXPECT_EQ(event_id, body_return_action->get_event());
  EXPECT_EQ(event_id, body_return_belief->get_event());
  EXPECT_EQ(event_id, body_return_goal->get_event());
}

TEST_F(TBodyReturn, get_type)
{
  EXPECT_EQ(BodyType::ACTION, body_return_action->get_type());
  EXPECT_EQ(BodyType::BELIEF, body_return_belief->get_type());
  EXPECT_EQ(BodyType::GOAL, body_return_goal->get_type());
}

TEST_F(TBodyReturn, get_value)
{
  EXPECT_EQ(true, body_return_action->get_value());
  EXPECT_EQ(true, body_return_belief->get_value());
  EXPECT_EQ(false, body_return_goal->get_value());
}
