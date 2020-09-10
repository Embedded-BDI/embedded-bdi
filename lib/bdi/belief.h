/*
 * belief.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_BELIEF_H_
#define BDI_BELIEF_H_

#include "../syntax/statement.h"
#include <cstdint>

class Belief
{
private:
  Statement _statement;
  /// State of Belief
  bool _belief_state;
  ///@{ Function to update _belief_state.
  /// var receives the current value of _belief_state
  ///@}
  bool (*_update)(bool var);

public:
  /**
   * Belief constructor
   * @param stm Belief Statement
   * @param update_function Function to update _belief_state
   * @param belief_state Belief state. Default is false
   */
  Belief(Statement stm,
         bool (*update_function)(bool var),
         bool belief_state = false);

  virtual ~Belief();

  /**
   * Update _belief_state based on _update function
   * @return true if _belief_state is changed, false otherwise
   */
  bool update_belief();

  /**
   * Update _belief_state
   * @param state Value to be assigned to _belief_state
   */
  void change_state(bool state);

  const Statement & get_statement() const
  {
    return _statement;
  }

  bool & get_state()
  {
    return _belief_state;
  }
};

#endif /* CLASSES_BELIEF_H_ */
