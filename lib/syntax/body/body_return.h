/*
 * body_return.h
 *
 *  Created on: Jul 17, 2020
 *      Author: matuzalem
 */

#ifndef SYNTAX_BODY_BODY_RETURN_H_
#define SYNTAX_BODY_BODY_RETURN_H_

#include "body_type.h"
#include "../../bdi/event.h"

class BodyReturn
{
private:
  BodyType _type;
  bool _value;
  EventID * _event;

public:
  BodyReturn();

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
