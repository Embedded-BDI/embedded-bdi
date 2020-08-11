/*
 * plan_base.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "plan_base.h"

PlanBase::PlanBase(int size)
{
  _plan_base.reserve(size);
}

PlanBase::~PlanBase() {}

bool PlanBase::add_plan(Plan plan)
{
  if (_plan_base.size() == _plan_base.capacity())
  {
    return false;
  }

  _plan_base.push_back(plan);
  return true;
}

Plan * PlanBase::revise(Event * event, BeliefBase * belief_base)
{
  if (event)
  {
    if ((event->get_operator() == EventOperator::BELIEF_ADDITION)     ||
        (event->get_operator() == EventOperator::BELIEF_DELETION)     ||
        (event->get_operator() == EventOperator::GOAL_ADDITION)       ||
        (event->get_operator() == EventOperator::GOAL_DELETION)       ||
        (event->get_operator() == EventOperator::TEST_GOAL_ADDITION)  ||
        (event->get_operator() == EventOperator::TEST_GOAL_DELETION))
    {
      for(std::vector<Plan>::iterator it = _plan_base.begin(); it != _plan_base.end(); ++it)
      {
        if (event->get_operator() == it->get_operator())
        {
          if (event->get_statement().is_equal(it->get_statement()))
          {
            if (it->get_context()->is_valid(belief_base))
            {
              return &*it;
            }
          }
        }
      }
    }
  }

  return nullptr;
}
