/*
 * goal.h
 *
 *  Created on: Jun 3, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_GOAL_H_
#define SYNTAX_GOAL_H_

#include "../body_instruction.h"
#include "../statement.h"

class Goal : IBodyInstruction {
private:
  EventOperator _operator;
  Statement _statement;
  BodyType _type = BodyType::GOAL;

public:
  Goal();

  Goal(Statement stm, EventOperator event_type, BeliefBase * belief_base, EventBase * event_base);

  virtual ~Goal();

  bool run_instruction() override;

  BodyType get_BodyType() {
    return _type;
  }

  const EventOperator & get_operator() const {
     return _operator;
  }

  const Statement & get_statement() const {
     return _statement;
  }
};

#endif /* SYNTAX_GOAL_H_ */
