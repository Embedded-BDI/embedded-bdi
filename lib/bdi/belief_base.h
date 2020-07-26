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
   * Adds belief to BeliefBase. Does NOT protect/check for duplicates
   * @param belief Belief to be added
   * @return true is belief is added, false otherwise
   */
  bool add_belief(Belief belief);

  /*
   * Updates belief based on belief's _update function
   * @param event_base Agent's EventBase. An event is added to the EventBase
   * in case the belief's _belief_state changes (true->false, false->true)
   */
  void update(EventBase * event_base);

  /*
   * Change the state of a belief
   * @param stm Belief's statement
   * @param state Value to be assigned to Belief's _state
   * @return false if Belief does not exist, true otherwise
   */
  bool change_belief_state(Statement stm, bool state);

  /*
   * Get _belief_state of belief that matches given statement
   * @param stm Statement to match belief's statement
   * @return belief's value. False if belief does not exist in BeliefBase
   */
  bool get_belief_state(Statement stm);

  /*
   * Size of BeliefBase
   * @return Size of _belief_base
   */
  const int get_size();
};

#endif /* CLASSES_BELIEFBASE_H_ */
