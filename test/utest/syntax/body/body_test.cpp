/*
 * body_test.cpp
 *
 *  Created on: Jul 24, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body.h"
#include "instructions.h"


class TBody : public ::testing::Test
{
protected:
  Body * body;
  InstructionExample * instructions;
  int size = 4;                                 // recommended is 4 or higher

public:
  TBody()
  {
    body = new Body(size);
    instructions = new InstructionExample(size);
  }

  virtual ~TBody()
  {
    delete body;
    delete instructions;
  }
};

TEST_F(TBody, add_instruction)
{
  for (int i = 0; i < size; i++)
  {
    EXPECT_TRUE(body->add_instruction(instructions->get_action_false()));
  }
  EXPECT_FALSE(body->add_instruction(instructions->get_action_false()));
}

TEST_F(TBody, run_body)
{
  for (int i = 0; i < size; i++)
  {
    if (i % 4 == 0)
    {
      body->add_instruction(instructions->get_action_false());
    }
    if (i % 4 == 1)
    {
      body->add_instruction(instructions->get_action_true());
    }
    if (i % 4 == 2)
    {
      body->add_instruction(instructions->get_belief_operation());
    }
    if (i % 4 == 3)
    {
      body->add_instruction(instructions->get_goal());
    }
  }

  for (int i = 0; i < size; i++)
  {
    BodyReturn result = body->run_body(i, instructions->get_belief_base(), instructions->get_event_base());

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
