/*
 * belief.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_BELIEF_H_
#define BDI_BELIEF_H_

#include "../syntax/statement.h"

class Belief
{
private:
  Statement _statement;
  bool _belief_state;
  // Function to update Agent's belief
  // @param var Parameter to be passed to update function. Usually
  // _belief_state
  bool (*_update)(bool var);

public:
  Belief();

  /*
   * Belief constructor
   * @param stm Agent's statement
   * @param update_function Function to update Agent's belief
   * @param belief_state Agent's belief state. Default is false
   */
  Belief(Statement stm, bool (*update_function)(bool var), bool belief_state = false);

  virtual ~Belief();

  /*
   * Update Belief's state based on _update function
   * @return true if _belief_state is changed, false otherwise
   */
  bool update_belief();

  /*
   * Change Belief's _belief_state
   * @param state State to be assigned to _belief_state
   */
  void change_state(bool state);

  const Statement & get_statement() const
  {
    return _statement;
  }

  const bool & get_state()
  {
    return _belief_state;
  }
};

#endif /* CLASSES_BELIEF_H_ */
