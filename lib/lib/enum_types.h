/*
 * EnumTypes.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: Matuzalem Muller
 */


enum class EventOperator : unsigned char
{
  BELIEF_ADDITION,      // +
  BELIEF_DELETION,      // -
  GOAL_ADDITION,        // +!
  GOAL_DELETION,        // -!
  TEST_GOAL_ADDITION,   // +?!
  TEST_GOAL_DELETION,   // -?!
};

enum class BodyType : unsigned char
{
  ACTION,
  GOAL,
  BELIEF
};
