/*
 * action.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: Matuzalem Muller
 */

#include "action.h"

Action::Action() {}

Action::Action(Statement stm, bool (*take_action_function)(BeliefBase * belief_base))
{
  _statement = stm;
  _take_action = take_action_function;
}

Action::~Action() {}

bool Action::run_instruction(BeliefBase * belief_base, EventBase * event_base)
{
  return _take_action(belief_base);
}
