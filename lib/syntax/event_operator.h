/*
 * event_operator.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_EVENT_OPERATOR_H_
#define SYNTAX_EVENT_OPERATOR_H_


/*
 * Event types:
 *  +   Addition of belief to belief base
 *  -   Deletion of belief from belief base
 *  +!  Addition of (sub)goal
 *  -!  Deletion of (sub)goal
 *  +?! Addition of test (sub)goal
 *  +?- Deletion of test (sub)goal
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

#endif /* SYNTAX_EVENT_OPERATOR_H_ */
