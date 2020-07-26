/*
 * body_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body.h"
#include "test_body_data.h"

class TBody : public ::testing::Test
{
protected:
  Body * body;
  TestBodyData * test_data;
  int size = 4;                                 // between 4 and 26

public:
  TBody()
  {
    body = new Body(size);
    test_data = new TestBodyData(size);
  }

  ~TBody()
  {
    delete body;
    delete test_data;
  }
};

TEST_F(TBody, add_instruction)
{
  for (int i = 0; i < size; i++)
  {
    EXPECT_TRUE(body->add_instruction(test_data->get_action_false()));
  }
  EXPECT_FALSE(body->add_instruction(test_data->get_action_false()));
}

TEST_F(TBody, run_body)
{
  for (int i = 0; i < size; i++)
  {
    if (i % 4 == 0)
    {
      body->add_instruction(test_data->get_action_false());
    }
    if (i % 4 == 1)
    {
      body->add_instruction(test_data->get_action_true());
    }
    if (i % 4 == 2)
    {
      body->add_instruction(test_data->get_belief_operation());
    }
    if (i % 4 == 3)
    {
      body->add_instruction(test_data->get_goal());
    }
  }

  for (int i = 0; i < size; i++)
  {
    BodyReturn result = body->run_body(i,
                                       test_data->get_belief_base(),
                                       test_data->get_event_base());

    if (i % 4 == 0)
    {
      EXPECT_EQ(BodyType::ACTION, result.get_type());
      EXPECT_TRUE(NULL == result.get_event());
      EXPECT_FALSE(result.get_value());
    }
    else if (i % 4 == 1)
    {
      EXPECT_EQ(BodyType::ACTION, result.get_type());
      EXPECT_TRUE(NULL == result.get_event());
      EXPECT_TRUE(result.get_value());
    }
    else if (i % 4 == 2)
    {
      EXPECT_EQ(BodyType::BELIEF, result.get_type());
      EXPECT_TRUE(NULL != result.get_event());
      EXPECT_TRUE(result.get_value());
    }
    else if (i % 4 == 3)
    {
      EXPECT_EQ(BodyType::GOAL, result.get_type());
      EXPECT_TRUE(NULL != result.get_event());
      EXPECT_TRUE(result.get_value());
    }
  }
}
