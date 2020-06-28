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
  bool (*_take_action)();
  Statement _statement;
  IBodyInstruction::BodyType _type = IBodyInstruction::ACTION;

public:
  Action();

  Action(Statement statement, bool (*take_action_function)());

  virtual ~Action();

  bool run_instruction(BeliefBase belief_base, EventBase event_base) override;

  IBodyInstruction::BodyType get_BodyType() override;
};

#endif /* SYNTAX_ACTION_H_ */
