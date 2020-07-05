/*
 * belief_operation.h
 *
 *  Created on: Jun 9, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_BELIEF_OPERATION_H_
#define SYNTAX_BODY_BELIEF_OPERATION_H_

#include "../body_instruction.h"
#include "../statement.h"

class BeliefOperation : IBodyInstruction
{
private:
  EventOperator _operator;
  Statement _statement;
  BodyType _type = BodyType::BELIEF;

public:
  BeliefOperation();

  BeliefOperation(Statement stm, EventOperator event_type, BeliefBase * belief_base, EventBase * event_base);

  virtual ~BeliefOperation();

  bool run_instruction() override;

  BodyType get_BodyType() override
  {
    return _type;
  }
};

#endif /* SYNTAX_BODY_BELIEF_OPERATION_H_ */
