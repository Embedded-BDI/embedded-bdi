/*
 * belief_base.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_BELIEF_BASE_H_
#define BDI_BELIEF_BASE_H_

#include "belief.h"
#include "event.h"
#include "event_base.h"
#include "../lib/circular_buffer.h"

class BeliefBase {
private:
  CircularBuffer<Belief> _belief_base;
  int _size;

public:
//  BeliefBase();

  BeliefBase(int size);

  virtual ~BeliefBase();

  void update(EventBase event_base);

  void change_belief_state(Statement stm, bool state);

  const int& get_size() const {
    return this->_size;
  }};

#endif /* CLASSES_BELIEFBASE_H_ */
