/*
 * belief_base.h
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/belief_base.h"
#include "../common_test_functions.h"

#define BELIEF_BASE_SIZE 3

class TBeliefBase : public ::testing::Test
{
protected:
  BeliefBase * belief_base;
  EventBase * event_base;

public:
  TBeliefBase()
  {
    belief_base = new BeliefBase(BELIEF_BASE_SIZE);
    event_base = new EventBase(BELIEF_BASE_SIZE);
  }

  ~TBeliefBase()
  {
    delete belief_base;
    delete event_base;
  }
};

TEST_F(TBeliefBase, add_belief)
{
  Statement stm_0(0);
  Statement stm_1(1);
  Statement stm_2(2);

  Belief belief_0(stm_0, return_true_bool, false);
  Belief belief_1(stm_1, return_false_bool, true);
  Belief belief_2(stm_2, nullptr, false);

  EXPECT_TRUE(belief_base->add_belief(belief_0));
  EXPECT_TRUE(belief_base->add_belief(belief_1));
  EXPECT_TRUE(belief_base->add_belief(belief_2));
  EXPECT_FALSE(belief_base->add_belief(belief_0));
}

TEST_F(TBeliefBase, get_belief_state)
{
  Statement stm_0(0);
  Statement stm_1(1);
  Statement stm_2(2);

  Belief belief_0(stm_0, return_true_bool, false);
  Belief belief_b(stm_1, return_false_bool, true);
  Belief belief_2(stm_2, nullptr, false);

  belief_base->add_belief(belief_0);
  belief_base->add_belief(belief_b);
  belief_base->add_belief(belief_2);

  EXPECT_FALSE(belief_base->get_belief_state(stm_0));
  EXPECT_TRUE(belief_base->get_belief_state(stm_1));
  EXPECT_FALSE(belief_base->get_belief_state(stm_2));
}

TEST_F(TBeliefBase, update)
{
  Statement stm_0(0);
  Statement stm_1(1);
  Statement stm_2(2);

  Belief belief_0(stm_0, return_true_bool, false);
  Belief belief_1(stm_1, return_false_bool, true);
  Belief belief_2(stm_2, nullptr, false);

  belief_base->add_belief(belief_0);
  belief_base->add_belief(belief_1);
  belief_base->add_belief(belief_2);

  EXPECT_NO_FATAL_FAILURE(belief_base->update(event_base));
  EXPECT_FALSE(event_base->is_full());

  EXPECT_TRUE(belief_base->get_belief_state(stm_0));
  EXPECT_FALSE(belief_base->get_belief_state(stm_1));
  EXPECT_FALSE(belief_base->get_belief_state(stm_2));

  EXPECT_NO_FATAL_FAILURE(belief_base->update(event_base));
  EXPECT_NO_FATAL_FAILURE(belief_base->update(event_base));
  EXPECT_NO_FATAL_FAILURE(belief_base->update(event_base));
  EXPECT_FALSE(event_base->is_full());
}

TEST_F(TBeliefBase, change_belief_state)
{
  Statement stm_0(0);
  Statement stm_1(1);
  Statement stm_2(2);

  Belief belief_0(stm_0, return_true_bool, false);
  Belief belief_b(stm_1, nullptr, true);

  belief_base->add_belief(belief_0);
  belief_base->add_belief(belief_b);

  EXPECT_TRUE(belief_base->change_belief_state(stm_0, true));
  EXPECT_TRUE(belief_base->get_belief_state(stm_0));

  EXPECT_TRUE(belief_base->change_belief_state(stm_1, false));
  EXPECT_FALSE(belief_base->get_belief_state(stm_1));

  EXPECT_FALSE(belief_base->change_belief_state(stm_2, false));
}

TEST_F(TBeliefBase, get_size)
{
  Statement stm_0(0);
  Statement stm_1(1);

  Belief belief_0(stm_0, return_true_bool, false);
  Belief belief_1(stm_1, nullptr, true);

  belief_base->add_belief(belief_0);
  EXPECT_EQ(1, belief_base->get_size());

  belief_base->add_belief(belief_1);
  EXPECT_EQ(2, belief_base->get_size());
}
