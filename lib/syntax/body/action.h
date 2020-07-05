/*
 * action.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_ACTION_H_
#define SYNTAX_ACTION_H_

#include "../body_instruction.h"
#include "../statement.h"

class Action : public Statement, IBodyInstruction
{
private:
  bool (*_take_action)(BeliefBase * belief_base);
  Statement _statement;
  BodyType _type = BodyType::ACTION;

public:
  Action();

  /*
   * Constructor for external action
   * @param stm Statement
   * @param take_action_function Pointer to function that will act in the environment
   */
  Action(Statement stm, bool (*take_action_function)(BeliefBase * belief_base));

  virtual ~Action();

  /*
   * Perform action in the environment
   * @param belief_base Agent's BeliefBase
   * @param event_base Agent's EventBase
   * @return based on _take_action function logic. Recommended is true for
   * action successful, false otherwise
   */
  bool run_instruction(BeliefBase * belief_base, EventBase * event_base) override;

  BodyType get_BodyType() override
  {
    return _type;
  }
};

#endif /* SYNTAX_ACTION_H_ */
