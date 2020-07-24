/*
 * body_instruction.h
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_BODY_INSTRUCTION_H_
#define SYNTAX_BODY_BODY_INSTRUCTION_H_

#include "body_type.h"
#include "body_return.h"
#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include <iostream>

/*
 * Body instructions can be belief operations, goal operations (adopt/drop
 * intention) or act in the environment. This class is used as an interface by
 * the Action, BeliefOperation and Goal classes.
 */
class BodyInstruction
{
private:
  bool (*_take_action)(BeliefBase * belief_base);
  Statement _statement;
  EventOperator _operator;
  BodyType _type;

public:
  BodyInstruction();

  BodyInstruction(BodyType type, Statement stm, bool (*take_action)(BeliefBase * belief_base));

  BodyInstruction(BodyType type, Statement stm, EventOperator event_operator);

  virtual ~BodyInstruction() {};

  BodyReturn run_instruction(BeliefBase * belief_base, EventBase * event_base);

  BodyType get_BodyType()
  {
    return _type;
  }
};

#endif /* SYNTAX_BODY_BODY_INSTRUCTION_H_ */
