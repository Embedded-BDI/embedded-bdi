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
protected:
  BeliefBase * _belief_base;
  EventBase * _event_base;

public:
  IBodyInstruction() {};

  virtual ~IBodyInstruction() {};

  virtual bool run_instruction() { return true; }

  virtual BodyType get_BodyType() { return  BodyType::ACTION; }
};

#endif /* SYNTAX_BODY_INSTRUCTION_H_ */
