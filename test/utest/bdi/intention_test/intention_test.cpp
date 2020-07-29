/*
 * intention_test.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/intention.h"
#include "test_intention_data.h"

#define INTENTION_SIZE 3
#define BODY_SIZE 2
#define BASES_SIZE 3

class TIntention : public ::testing::Test
{
protected:
  Intention * intention_successul;
  Intention * intention_fails;
  Plan * plan_sucessful;
  Plan * plan_fails;
  TestIntentionData * test_data;

public:
  TIntention()
  {
    test_data = new TestIntentionData(BODY_SIZE, BASES_SIZE);

    plan_sucessful = test_data->get_plan_successfull();
    plan_fails = test_data->get_plan_fails();

    intention_successul = new Intention(plan_sucessful, INTENTION_SIZE);
    intention_fails = new Intention(plan_fails, INTENTION_SIZE);
  }

  ~TIntention()
  {
    delete intention_successul;
    delete intention_fails;
    delete test_data;
  }
};

TEST_F(TIntention, stack_plan)
{
  EXPECT_FALSE(intention_successul->stack_plan(NULL));

  for (int i = 0; i < INTENTION_SIZE-1; i++)
  {
    EXPECT_TRUE(intention_successul->stack_plan(plan_sucessful));
  }

  EXPECT_FALSE(intention_successul->stack_plan(plan_sucessful));
}

TEST_F(TIntention, run_intention)
{
  for (int i = 0; i < INTENTION_SIZE-1; i++)
  {
    intention_successul->stack_plan(plan_sucessful);
    intention_fails->stack_plan(plan_fails);
  }

  for (int i = 0; i < (INTENTION_SIZE * BODY_SIZE); i++)
  {
    EXPECT_TRUE(intention_successul->run_intention(NULL, NULL));
    EXPECT_FALSE(intention_fails->run_intention(NULL, NULL));
  }

  EXPECT_FALSE(intention_successul->run_intention(NULL, NULL));
}

TEST_F(TIntention, is_finished)
{
  for (int i = 0; i < INTENTION_SIZE-1; i++)
  {
    EXPECT_FALSE(intention_successul->is_finished());
    EXPECT_FALSE(intention_fails->is_finished());
    intention_successul->stack_plan(plan_sucessful);
    intention_fails->stack_plan(plan_fails);
  }

  for (int i = 0; i < (INTENTION_SIZE * BODY_SIZE); i++)
  {
    EXPECT_FALSE(intention_successul->is_finished());
    intention_successul->run_intention(NULL, NULL);
    intention_fails->run_intention(NULL, NULL);
    EXPECT_TRUE(intention_fails->is_finished());
  }

  EXPECT_TRUE(intention_successul->is_finished());
  EXPECT_FALSE(intention_successul->run_intention(NULL, NULL));
  EXPECT_TRUE(intention_successul->is_finished());
}
