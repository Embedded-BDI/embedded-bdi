/*
 * intention_id.cpp
 *
 *  Created on: Jul 13, 2020
 *      Author: Matuzalem Muller
 */

#include "intention_id.h"

int IntentionID::id = 0;

IntentionID::IntentionID()
{
  _id = id++;
}

IntentionID::~IntentionID() {}

bool IntentionID::is_equal(IntentionID intention_id)
{
  return (_id == intention_id._id);
}
