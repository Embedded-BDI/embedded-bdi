/*
 * event_id.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_EVENT_ID_H_
#define LIB_EVENT_ID_H_

/*
 * Represents Event Unique Identifier
 * Class can be modified to use other control and data representation such as
 * UUID for better handling of events
 */
class EventID
{
private:
  int _id;

protected:
  static int id;

public:
  EventID();

  virtual ~EventID();

  /*
   * Compares given ID with _id
   * @return True if event_id is equal to _id, false otherwise
   */
  bool is_equal(EventID * event_id);

  const int get_id() const
  {
    return _id;
  }

  /*
   * Returns EventID's main counter
   * @return id
   */
  int get_control_id()
  {
    return EventID::id;
  }
};

#endif /* LIB_EVENT_ID_H_ */

