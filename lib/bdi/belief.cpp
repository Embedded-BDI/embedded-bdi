/*
 * belief.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "belief.h"

Belief::Belief() {}

Belief::Belief(Statement stm, bool (*update_function)(), bool belief_state) {
  this->_statement = stm;
  this->_belief_state = belief_state;
  this->_update = update_function;
}

Belief::~Belief() {}

bool Belief::update_belief() {
  if (this->_belief_state != 0)
  {
    this->_belief_state = this->_update();
    return this->_belief_state;
  } else {
    return false;
  }
}

void Belief::change_state(bool state) {
  this->_belief_state = state;
}
