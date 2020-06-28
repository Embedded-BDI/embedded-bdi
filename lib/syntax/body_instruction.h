/*
 * body_instruction.h
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_INSTRUCTION_H_
#define SYNTAX_BODY_INSTRUCTION_H_

#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"

class IBodyInstruction {
public:
  enum BodyType { ACTION, GOAL, BELIEF };

  IBodyInstruction();

  virtual ~IBodyInstruction();

  virtual bool run_instruction(BeliefBase belief_base, EventBase event_base) { return true; }

  virtual IBodyInstruction::BodyType get_BodyType() { return  BodyType::ACTION; }
};

#endif /* SYNTAX_BODY_INSTRUCTION_H_ */
