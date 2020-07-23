/*
 * event_test.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/event.h"

class TEvent : public ::testing::Test
{
protected:
  Event * event;

public:
  TEvent()
  {
    Statement stm('a');
    event = new Event(EventOperator::BELIEF_ADDITION, stm);
  }

  virtual ~TEvent()
  {
    delete this->event;
  }
};

/*
 * Test if operator is stored correctly
 */
TEST_F(TEvent, get_operator)
{
  EXPECT_EQ(EventOperator::BELIEF_ADDITION, event->get_operator());
}

/*
 * Test if statement is stored correctly
 */
TEST_F(TEvent, get_statement)
{
  Statement stm('a');
  EXPECT_EQ('a', event->get_statement().get_name());
  EXPECT_TRUE(event->get_statement().is_equal(stm));
}

/*
 * Confirm that EventID is not null and its value
 */
TEST_F(TEvent, get_event_id)
{
  EXPECT_TRUE(NULL != event->get_event_id());
  EXPECT_EQ(event->get_event_id()->get_control_id()-1, event->get_event_id()->get_id());
}
