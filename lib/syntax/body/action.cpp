/*
 * action.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: Matuzalem Muller
 */

#include "action.h"

Action::Action() {}

Action::Action(Statement stm, bool (*take_action_function)(BeliefBase * belief_base), BeliefBase * belief_base, EventBase * event_base)
{
  _statement = stm;
  _take_action = take_action_function;
  _belief_base = belief_base;
  _event_base = event_base;
}

Action::~Action() {}

bool Action::run_instruction()
{
  return _take_action(_belief_base);
}
