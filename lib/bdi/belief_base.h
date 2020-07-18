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

class BeliefBase
{
private:
  CircularBuffer<Belief> * _belief_base;

public:
  /*
   * BeliefBase's constructor
   * @param size Size of BeliefBase buffer
   */
  BeliefBase(int size);

  virtual ~BeliefBase();

  /*
   * Adds belief to belief base
   * @param belief Belief to be added
   * @return true is belief is added, false otherwise
   */
  bool add_belief(Belief belief);

  /*
   * Updates belief based on Belief's _update function
   * @param event_base Agent's event_base. An event is added to the event_base
   * if case the Belief's _belief_state changes (true->false, false->true)
   */
  void update(EventBase * event_base);

  /*
   * Change the state of a Belief
   * @param stm Belief's statement
   * @param state Value to be assigned to Belief's _state
   * @return false if Belief does not exist, true otherwise
   */
  bool change_belief_state(Statement stm, bool state);

  /*
   * Get state of belief that matches the given statement
   * @param stm Statement to match belief's statement
   * @return belief's value. False if belief does not exist in BeliefBase
   */
  bool get_belief_state(Statement stm);

  const int get_size()
  {
    return _belief_base->capacity();
  }};

#endif /* CLASSES_BELIEFBASE_H_ */
