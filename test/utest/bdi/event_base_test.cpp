/*
 * event_base_test.cpp
 *
 *  Created on: Jul 27, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/event_base.h"

#define EVENT_BASE_SIZE 4

class TEventBase : public ::testing::Test
{
protected:
  EventBase * event_base;

public:
  TEventBase()
  {
    event_base = new EventBase(EVENT_BASE_SIZE);
  }

  ~TEventBase()
  {
    delete event_base;
  }
};

TEST_F(TEventBase, is_empty)
{
  EXPECT_TRUE(event_base->is_empty());
}

TEST_F(TEventBase, is_full)
{
  Statement stm('a');

  for (int i = 0; i < EVENT_BASE_SIZE; i++)
  {
    event_base->add_event(EventOperator::BELIEF_ADDITION, stm);
  }

  EXPECT_TRUE(event_base->is_full());
}

TEST_F(TEventBase, add_event)
{
  Statement stm_a('a');
  Statement stm_b('b');
  Statement stm_c('c');
  Statement stm_d('d');
  Statement stm_e('e');

  EXPECT_TRUE(event_base->add_event(EventOperator::BELIEF_ADDITION, stm_a));
  EXPECT_TRUE(event_base->add_event(EventOperator::BELIEF_DELETION, stm_b));
  EXPECT_TRUE(event_base->add_event(EventOperator::GOAL_ADDITION, stm_c));
  EXPECT_TRUE(event_base->add_event(EventOperator::GOAL_DELETION, stm_d));
  EXPECT_FALSE(event_base->add_event(EventOperator::BELIEF_ADDITION, stm_e));
}

TEST_F(TEventBase, get_event)
{
  Statement stm_a('a');
  Statement stm_b('b');
  Statement stm_c('c');

  Event * event = event_base->get_event();

  EXPECT_TRUE(NULL == event);

  event_base->add_event(EventOperator::BELIEF_ADDITION, stm_a);
  event_base->add_event(EventOperator::BELIEF_DELETION, stm_b);
  event_base->add_event(EventOperator::GOAL_ADDITION, stm_c);

  Event * event_a = event_base->get_event();
  Event * event_b = event_base->get_event();
  Event * event_c = event_base->get_event();
  Event * event_null = event_base->get_event();

  EXPECT_TRUE(NULL != event_a);
  EXPECT_TRUE(NULL != event_b);
  EXPECT_TRUE(NULL != event_c);
  EXPECT_TRUE(NULL == event_null);

  EXPECT_EQ(EventOperator::BELIEF_ADDITION, event_a->get_operator());
  EXPECT_EQ(EventOperator::BELIEF_DELETION, event_b->get_operator());
  EXPECT_EQ(EventOperator::GOAL_ADDITION, event_c->get_operator());

  EXPECT_TRUE(stm_a.is_equal(event_a->get_statement()));
  EXPECT_TRUE(stm_b.is_equal(event_b->get_statement()));
  EXPECT_TRUE(stm_c.is_equal(event_c->get_statement()));

  delete event;
  delete event_a;
  delete event_b;
  delete event_c;
  delete event_null;
}

TEST_F(TEventBase, last_event)
{
  Statement stm_a('a');
  Statement stm_b('b');

  EXPECT_TRUE(NULL == event_base->last_event());

  event_base->add_event(EventOperator::BELIEF_ADDITION, stm_a);
  event_base->add_event(EventOperator::BELIEF_DELETION, stm_b);

  Event * event_b = event_base->last_event();

  EXPECT_TRUE(NULL != event_b);
  EXPECT_EQ(EventOperator::BELIEF_DELETION, event_b->get_operator());
  EXPECT_TRUE(stm_b.is_equal(event_b->get_statement()));
}

TEST_F(TEventBase, event_exists)
{
  Statement stm_a('a');
  Statement stm_b('b');
  Statement stm_c('c');
  Statement stm_d('d');

  event_base->add_event(EventOperator::BELIEF_ADDITION, stm_a);
  Event * event_a = event_base->last_event();

  event_base->add_event(EventOperator::BELIEF_DELETION, stm_b);
  Event * event_b = event_base->last_event();

  event_base->add_event(EventOperator::GOAL_ADDITION, stm_c);
  Event * event_c = event_base->last_event();

  Event event_nonexisting(EventOperator::BELIEF_ADDITION, stm_d);

  EXPECT_TRUE(event_base->event_exists(event_a->get_event_id()));
  EXPECT_TRUE(event_base->event_exists(event_b->get_event_id()));
  EXPECT_TRUE(event_base->event_exists(event_c->get_event_id()));
  EXPECT_FALSE(event_base->event_exists(event_nonexisting.get_event_id()));
}
