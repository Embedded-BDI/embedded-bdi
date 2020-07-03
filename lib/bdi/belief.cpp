/*
 * belief.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "belief.h"

Belief::Belief() {}

Belief::Belief(Statement stm, bool (*update_function)(bool var), bool belief_state) {
  _statement = stm;
  _belief_state = belief_state;
  _update = update_function;
}

Belief::~Belief() {}

bool Belief::update_belief() {
  bool var = _update(_belief_state);
  if (var)
  {
    _belief_state = !_belief_state;
    return true;
  } else {
    return false;
  }
//  if (_belief_state != 0)
//  {
//    _belief_state = _update();
//    return _belief_state;
//  } else {
//    return false;
//  }
}

void Belief::change_state(bool state) {
  _belief_state = state;
}
