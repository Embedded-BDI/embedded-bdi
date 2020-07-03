/*
 * action.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_ACTION_H_
#define SYNTAX_ACTION_H_

#include "../body_instruction.h"
#include "../../bdi/event_base.h"
#include "../statement.h"

class Action : public Statement, IBodyInstruction {
private:
  bool (*_take_action)(BeliefBase * belief_base);
  Statement _statement;
  IBodyInstruction::BodyType _type = IBodyInstruction::ACTION;

public:
  Action();

  Action(Statement stm, bool (*take_action_function)(BeliefBase * belief_base), BeliefBase * belief_base, EventBase * event_base);

  virtual ~Action();

  bool run_instruction() override;

  IBodyInstruction::BodyType get_BodyType() {
    return _type;
  }
};

#endif /* SYNTAX_ACTION_H_ */
