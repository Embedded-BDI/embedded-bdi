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
  Proposition prop(0);

  for (int i = 0; i < EVENT_BASE_SIZE; i++)
  {
    Event event(EventOperator::BELIEF_ADDITION, prop);
    event_base->add_event(event);
  }

  EXPECT_TRUE(event_base->is_full());
}

TEST_F(TEventBase, add_event)
{
  Proposition prop_0(0);
  Proposition prop_1(1);
  Proposition prop_c(2);
  Proposition prop_d(3);
  Proposition prop_e('e');

  Event event_1(EventOperator::BELIEF_ADDITION, prop_0);
  EXPECT_TRUE(event_base->add_event(event_1));
  Event event_2(EventOperator::BELIEF_DELETION, prop_1);
  EXPECT_TRUE(event_base->add_event(event_2));
  Event event_3(EventOperator::GOAL_ADDITION, prop_c);
  EXPECT_TRUE(event_base->add_event(event_3));
  Event event_4(EventOperator::GOAL_DELETION, prop_d);
  EXPECT_TRUE(event_base->add_event(event_4));
  Event event_5(EventOperator::BELIEF_ADDITION, prop_e);
  EXPECT_FALSE(event_base->add_event(event_5));
}

TEST_F(TEventBase, get_event)
{
  Proposition prop_0(0);
  Proposition prop_1(1);
  Proposition prop_2(2);

  Event * event_p = event_base->get_event();

  EXPECT_TRUE(nullptr == event_p);

  Event event_1(EventOperator::BELIEF_ADDITION, prop_0);
  event_base->add_event(event_1);
  Event event_2(EventOperator::BELIEF_DELETION, prop_1);
  event_base->add_event(event_2);
  Event event_3(EventOperator::GOAL_ADDITION, prop_2);
  event_base->add_event(event_3);

  Event * event_a = event_base->get_event();
  Event * event_b = event_base->get_event();
  Event * event_c = event_base->get_event();
  Event * event_null = event_base->get_event();

  EXPECT_TRUE(nullptr != event_a);
  EXPECT_TRUE(nullptr != event_b);
  EXPECT_TRUE(nullptr != event_c);
  EXPECT_TRUE(nullptr == event_null);

  EXPECT_EQ(EventOperator::BELIEF_ADDITION, event_a->get_operator());
  EXPECT_EQ(EventOperator::BELIEF_DELETION, event_b->get_operator());
  EXPECT_EQ(EventOperator::GOAL_ADDITION, event_c->get_operator());

  EXPECT_TRUE(prop_0.is_equal(event_a->get_proposition()));
  EXPECT_TRUE(prop_1.is_equal(event_b->get_proposition()));
  EXPECT_TRUE(prop_2.is_equal(event_c->get_proposition()));

  delete event_p;
  delete event_a;
  delete event_b;
  delete event_c;
  delete event_null;
}

TEST_F(TEventBase, last_event)
{
  Proposition prop_0(0);
  Proposition prop_1(1);

  EXPECT_TRUE(nullptr == event_base->last_event());

  Event event_1(EventOperator::BELIEF_ADDITION, prop_0);
  event_base->add_event(event_1);
  Event event_2(EventOperator::BELIEF_DELETION, prop_1);
  event_base->add_event(event_2);

  Event * event_b = event_base->last_event();

  EXPECT_TRUE(nullptr != event_b);
  EXPECT_EQ(EventOperator::BELIEF_DELETION, event_b->get_operator());
  EXPECT_TRUE(prop_1.is_equal(event_b->get_proposition()));
}

TEST_F(TEventBase, event_exists)
{
  Proposition prop_0(0);
  Proposition prop_1(1);
  Proposition prop_2(2);
  Proposition prop_3(3);

  Event event_1(EventOperator::BELIEF_ADDITION, prop_0);
  event_base->add_event(event_1);
  Event * event_a = event_base->last_event();

  Event event_2(EventOperator::BELIEF_DELETION, prop_1);
  event_base->add_event(event_2);
  Event * event_b = event_base->last_event();

  Event event_3(EventOperator::GOAL_ADDITION, prop_2);
  event_base->add_event(event_3);
  Event * event_c = event_base->last_event();

  Event event_nonexisting(EventOperator::BELIEF_ADDITION, prop_3);

  EXPECT_TRUE(event_base->event_exists(event_a->get_event_id()));
  EXPECT_TRUE(event_base->event_exists(event_b->get_event_id()));
  EXPECT_TRUE(event_base->event_exists(event_c->get_event_id()));
  EXPECT_FALSE(event_base->event_exists(event_nonexisting.get_event_id()));
}
