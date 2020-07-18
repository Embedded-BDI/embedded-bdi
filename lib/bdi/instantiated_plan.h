/*
 * instantiated_plan.h
 *
 *  Created on: Jul 12, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_INSTANTIATED_PLAN_H_
#define BDI_INSTANTIATED_PLAN_H_

#include "../lib/intention_id.h"
#include "../syntax/plan.h"

class InstantiatedPlan
{
private:
  Plan * _plan;
  int _index = 0;
  IntentionID * _id;

public:
  InstantiatedPlan();

  InstantiatedPlan(Plan * plan, IntentionID id);

  virtual ~InstantiatedPlan();

  BodyReturn run_plan(BeliefBase * beliefs, EventBase * events);

  bool is_finished();
};

#endif /* BDI_INSTANTIATED_PLAN_H_ */
