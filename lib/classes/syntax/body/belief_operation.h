/*
 * belief_operation.h
 *
 *  Created on: Jun 9, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_BELIEF_OPERATION_H_
#define SYNTAX_BODY_BELIEF_OPERATION_H_

#include "../event_operator.h"
#include "../body_instruction.h"
#include "../statement.h"

class BeliefOperation : IBodyInstruction {
private:
  EventOperator::EventType _operator;
  Statement _statement;
  IBodyInstruction::BodyType _type = IBodyInstruction::BodyType::BELIEF;

public:
  BeliefOperation();

  BeliefOperation(Statement statement, EventOperator::EventType event_type);

  virtual ~BeliefOperation();

  bool run_instruction(BeliefBase belief_base, EventBase event_base) override;

  IBodyInstruction::BodyType get_BodyType() override;
};

#endif /* SYNTAX_BODY_BELIEF_OPERATION_H_ */
