/*
 * goal.h
 *
 *  Created on: Jun 3, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_GOAL_H_
#define SYNTAX_GOAL_H_

#include "../body_instruction.h"
#include "../event_operator.h"
#include "../statement.h"

class Goal : IBodyInstruction {
private:
  EventOperator::EventType _operator;
  Statement _statement;
  IBodyInstruction::BodyType _type = IBodyInstruction::GOAL;

public:
  Goal();

  Goal(EventOperator::EventType op, Statement stm);

  virtual ~Goal();

  bool run_instruction(BeliefBase belief_base, EventBase event_base) override;

  IBodyInstruction::BodyType get_BodyType() override;

  const EventOperator::EventType & get_operator() const {
     return this->_operator;
  }

  const Statement & get_statement() const {
     return this->_statement;
  }
};

#endif /* SYNTAX_GOAL_H_ */
