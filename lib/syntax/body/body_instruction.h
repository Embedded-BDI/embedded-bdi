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
#include "../../bdi/belief_base.h"
#include "../../bdi/event_base.h"

/*
 * Body instructions can be belief operations, goal operations (adopt/drop
 * intention) or act in the environment. This class is used as an interface by
 * the Action, BeliefOperation and Goal classes.
 */
class IBodyInstruction
{
public:
  IBodyInstruction() {};

  virtual ~IBodyInstruction() {};

  virtual BodyReturn run_instruction(BeliefBase * belief_base, EventBase * event_base) {}; // @suppress("No return")

  virtual BodyType get_BodyType() {}; // @suppress("No return")
};

#endif /* SYNTAX_BODY_BODY_INSTRUCTION_H_ */
