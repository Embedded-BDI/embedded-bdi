/*
 * belief_operation.h
 *
 *  Created on: Jun 9, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_BELIEF_OPERATION_H_
#define SYNTAX_BODY_BELIEF_OPERATION_H_

#include "body_instruction.h"
#include "../statement.h"

class BeliefOperation : IBodyInstruction
{
private:
  EventOperator _operator;
  Statement _statement;
  BodyType _type = BodyType::BELIEF;

public:
  BeliefOperation();

  /*
   * BeliefOperation constructor
   * @param stm Statement
   * @param event_type Type of event
   */
  BeliefOperation(Statement stm, EventOperator event_type);

  virtual ~BeliefOperation();

  /*
   * Add/remove belief from Agent's BeliefBase and create event for operation
   * @param belief_base Agent's BeliefBase
   * @param event_base Agent's EventBase
   * @return Based on return from add_event method. If event is added
   * successfully, return is true. Otherwise, return is false and intention
   * should likely be dropped
   */
  BodyReturn run_instruction(BeliefBase * belief_base, EventBase * event_base) override;

  BodyType get_BodyType() override
  {
    return _type;
  }
};

#endif /* SYNTAX_BODY_BELIEF_OPERATION_H_ */
