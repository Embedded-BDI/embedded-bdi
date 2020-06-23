/*
 * event_operator.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_EVENT_OPERATOR_H_
#define SYNTAX_EVENT_OPERATOR_H_

class EventOperator {
public:
   enum EventType {
    BELIEF_ADDITION,      // +
    BELIEF_DELETION,      // -
    GOAL_ADDITION,        // +!
    GOAL_DELETION,        // -!
    TEST_GOAL_ADDITION,   // +?!
    TEST_GOAL_DELETION,   // -?!
   };

   EventOperator();

   virtual ~EventOperator();
};

#endif /* SYNTAX_EVENT_OPERATOR_H_ */
