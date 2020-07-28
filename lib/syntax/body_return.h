/*
 * body_return.h
 *
 *  Created on: Jul 17, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_BODY_BODY_RETURN_H_
#define SYNTAX_BODY_BODY_RETURN_H_

#include "body_type.h"
#include "../bdi/event.h"

class BodyReturn
{
private:
  BodyType _type;
  bool _value;
  EventID * _event;

public:
  BodyReturn();

  /*
   * BodyReturn constructor. For each BodyType:
   *  * Action: type is BodyType::ACTION
   *            _value is true if action is successful, false otherwise
   *            event is NULL
   *  * Belief: type is BodyType::BELIEF
   *            _value is true if event is added to EventBase, false otherwise
   *            event is pointer to EventID of event created for instruction
   *  * Goal: type is BodyType::GOAL
   *          _value is true if event is added to EventBase, false otherwise
   *          event is pointer to EventID of event created for instruction
   */
  BodyReturn(BodyType type, bool value, EventID * event);

  virtual ~BodyReturn();

  EventID * get_event()
  {
    return _event;
  }

  BodyType get_type() const
  {
    return _type;
  }

  bool get_value() const
  {
    return _value;
  }
};

#endif /* SYNTAX_BODY_BODY_RETURN_H_ */
