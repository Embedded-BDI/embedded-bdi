/*
 * intention_id.h
 *
 *  Created on: Jul 10, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_INTENTION_ID_H_
#define LIB_INTENTION_ID_H_

/*
 * Represents Intention Unique Identifier
 * Class can be modified to use other control and data representation such as
 * UUID for better handling of events
 */
class IntentionID
{
private:
  int _id;

protected:
  static int id;

public:
  IntentionID();

  virtual ~IntentionID();

  bool is_equal(IntentionID intention_id);

  const int get_id() const
  {
    return _id;
  }

  int get_control_id()
  {
    return IntentionID::id;
  }
};

#endif /* LIB_INTENTION_ID_H_ */

