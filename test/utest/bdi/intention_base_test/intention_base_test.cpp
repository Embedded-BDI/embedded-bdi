/*
 * intention_base_test.cpp
 *
 *  Created on: Aug 4, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/intention_base.h"
#include "test_intention_base_data.h"

#define PLAN_BODY_SIZE 2
#define BASES_SIZE 3
#define INTENTION_STACK_SIZE 3

class TIntentionBase : public ::testing::Test
{
protected:
  IntentionBase * intention_base;
  Plan * plan_action_successful;
  Plan * plan_action_fails;
  Plan * plan_belief;
  TestIntentionBaseData * test_data;

public:
  TIntentionBase()
  {
    intention_base = new IntentionBase(BASES_SIZE, INTENTION_STACK_SIZE);
    test_data = new TestIntentionBaseData(PLAN_BODY_SIZE, BASES_SIZE);
    plan_action_successful = test_data->get_plan_action_successful();
    plan_action_fails = test_data->get_plan_action_fails();
    plan_belief = test_data->get_plan_belief();
  }

  ~TIntentionBase()
  {
    delete intention_base;
    delete test_data;
  }
};

TEST_F(TIntentionBase, run_intention_base)
{
  EXPECT_NO_FATAL_FAILURE(intention_base->run_intention_base(NULL, NULL));

  for (int i = 0; i < BASES_SIZE; i++)
  {
    intention_base->add_intention(plan_action_successful, NULL);
  }

  for (int i = 0; i < (BASES_SIZE * PLAN_BODY_SIZE * 2); i++)
  {
    EXPECT_NO_FATAL_FAILURE(intention_base->run_intention_base(NULL, NULL));
  }
}

TEST_F(TIntentionBase, is_empty)
{
  EXPECT_TRUE(intention_base->is_empty());

  for (int i = 0; i < BASES_SIZE; i++)
  {
    intention_base->add_intention(plan_action_successful, NULL);
    EXPECT_FALSE(intention_base->is_empty());
  }

  for (int i = 0; i < (BASES_SIZE * PLAN_BODY_SIZE); i++)
  {
    EXPECT_FALSE(intention_base->is_empty());
    intention_base->run_intention_base(nullptr, nullptr);
  }

  EXPECT_TRUE(intention_base->is_empty());
}
