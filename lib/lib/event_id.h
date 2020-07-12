/*
 * event_id.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_EVENT_ID_CPP_
#define LIB_EVENT_ID_CPP_


/*
 * Represents Event Unique Identifier
 * Class can be modified to use other control and data representation such as
 * UUID for better handling of events
 */
class EventID
{
protected:
  int _id;
  static int id;

public:
  EventID();

  virtual ~EventID();

  bool is_equal(EventID event_id);
};

#endif /* LIB_EVENT_ID_CPP_ */

