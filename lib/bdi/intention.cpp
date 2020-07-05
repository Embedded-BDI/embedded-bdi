/*
 * intention.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "intention.h"

Intention::Intention() {} // @suppress("Class members should be properly initialized")

Intention::Intention(Plan plan, int size)
{
  _size = size;
  _plans = new Stack<Plan>(size);
  _suspended = false;
}

Intention::~Intention()
{
  delete _plans;
}

void Intention::add_plan(Plan * plan) {}

bool Intention::run_intention(BeliefBase beliefs, EventBase events) { return true; }

void Intention::suspend()
{
  _suspended = true;
}

void Intention::unsuspend()
{
  _suspended = false;
}

bool Intention::is_suspended()
{
  return _suspended;
}

bool Intention::is_finished() const
{
  return true;
}
