/*
 * belief.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_BELIEF_H_
#define BDI_BELIEF_H_
#include "../syntax/statement.h"

class Belief {
private:
  Statement _statement;
  bool _belief_state;
  bool (*_update)(bool var);

public:
  Belief();

  Belief(Statement stm, bool (*update_function)(bool var), bool belief_state = false);

  virtual ~Belief();

  bool update_belief();

  void change_state(bool state);

  const Statement& get_statement() const {
    return this->_statement;
  }

  bool get_state() {
    return this->_belief_state;
  }
};

#endif /* CLASSES_BELIEF_H_ */
