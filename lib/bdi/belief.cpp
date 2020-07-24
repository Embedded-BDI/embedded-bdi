/*
 * belief.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "belief.h"
#include <iostream>

Belief::Belief() {}

Belief::Belief(Statement stm, bool (*update_function)(bool var), bool belief_state)
{
  _statement = stm;
  _belief_state = belief_state;
  _update = update_function;
}

Belief::~Belief() {}

bool Belief::update_belief()
{
  if (_update)
  {
    bool current_value = _belief_state;
    _belief_state = _update(_belief_state);
    if (_belief_state != current_value)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

void Belief::change_state(bool state)
{
  _belief_state = state;
}
