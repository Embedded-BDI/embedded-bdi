/*
 * intention_test.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/intention.h"
#include "test_intention_data.h"

#define INTENTION_STACK_SIZE 3
#define BODY_SIZE 2
#define BASES_SIZE 3

class TIntention : public ::testing::Test
{
protected:
  Intention * intention_action_successul;
  Intention * intention_action_fails;
  Intention * intention_belief;
  Plan * plan_action_successful;
  Plan * plan_action_fails;
  Plan * plan_belief;
  TestIntentionData * test_data;

public:
  TIntention()
  {
    test_data = new TestIntentionData(BODY_SIZE, BASES_SIZE);

    plan_action_successful = test_data->get_plan_action_successful();
    plan_action_fails = test_data->get_plan_action_fails();
    plan_belief = test_data->get_plan_belief();

    intention_action_successul = new Intention(plan_action_successful,
                                               INTENTION_STACK_SIZE);
    intention_action_fails = new Intention(plan_action_fails,
                                           INTENTION_STACK_SIZE);
    intention_belief = new Intention(plan_belief,
                                     INTENTION_STACK_SIZE);
  }

  ~TIntention()
  {
    delete intention_action_successul;
    delete intention_action_fails;
    delete intention_belief;
    delete test_data;
  }
};

TEST_F(TIntention, stack_plan)
{
  EXPECT_FALSE(intention_action_successul->stack_plan(nullptr));

  for (int i = 0; i < INTENTION_STACK_SIZE-1; i++)
  {
    EXPECT_TRUE(intention_action_successul->stack_plan(plan_action_successful));
  }

  EXPECT_FALSE(intention_action_successul->stack_plan(plan_action_successful));
}

TEST_F(TIntention, run_intention)
{
  for (int i = 0; i < INTENTION_STACK_SIZE-1; i++)
  {
    intention_action_successul->stack_plan(plan_action_successful);
    intention_action_fails->stack_plan(plan_action_fails);
  }

  for (int i = 0; i < (INTENTION_STACK_SIZE * BODY_SIZE); i++)
  {
    EXPECT_TRUE(intention_action_successul->run_intention(nullptr, nullptr));
    EXPECT_FALSE(intention_action_fails->run_intention(nullptr, nullptr));
  }

  EXPECT_FALSE(intention_action_successul->run_intention(nullptr, nullptr));
}

TEST_F(TIntention, is_finished)
{
  for (int i = 0; i < INTENTION_STACK_SIZE-1; i++)
  {
    EXPECT_FALSE(intention_action_successul->is_finished());
    EXPECT_FALSE(intention_action_fails->is_finished());
    intention_action_successul->stack_plan(plan_action_successful);
    intention_action_fails->stack_plan(plan_action_fails);
  }

  for (int i = 0; i < (INTENTION_STACK_SIZE * BODY_SIZE); i++)
  {
    EXPECT_FALSE(intention_action_successul->is_finished());
    intention_action_successul->run_intention(nullptr, nullptr);
    intention_action_fails->run_intention(nullptr, nullptr);
    EXPECT_TRUE(intention_action_fails->is_finished());
  }

  EXPECT_TRUE(intention_action_successul->is_finished());
  EXPECT_FALSE(intention_action_successul->run_intention(nullptr, nullptr));
  EXPECT_TRUE(intention_action_successul->is_finished());
}

TEST_F(TIntention, is_suspended_by)
{
  EventBase * eb = test_data->get_event_base_empty();
  BeliefBase * bb = test_data->get_belief_base();

  intention_belief->run_intention(bb, eb);
  EXPECT_TRUE(intention_belief->is_suspended_by(eb->last_event()));
}

TEST_F(TIntention, terminate)
{
  EventBase * eb = test_data->get_event_base_empty();
  BeliefBase * bb = test_data->get_belief_base();

  EXPECT_NO_FATAL_FAILURE(intention_belief->terminate(bb, eb, nullptr));
}

TEST_F(TIntention, destructor)
{
  Intention * intention = new Intention(plan_action_fails, INTENTION_STACK_SIZE);
  delete intention;
}
