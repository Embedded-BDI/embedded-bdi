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

  /*
   * InstantiatedPlan constructor
   * @param plan Pointer to plan
   * @param id IntentionId id
   */
  InstantiatedPlan(Plan * plan, IntentionID * id);

  virtual ~InstantiatedPlan();

  /*
   * Run instruction from position _index from Plan _plan
   * @param beliefs Agent's BeliefBase
   * @param events Agent's EventBase
   * @return BodyReturn that lists BodyType, _value and EventID
   * of generated event (if any)
   */
  BodyReturn run_plan(BeliefBase * beliefs, EventBase * events);

  /*
   * Returns if the entire plan from _plan has been run
   * @return True if all instructions from _plan were run, false otherwise
   */
  bool is_finished();
};

#endif /* BDI_INSTANTIATED_PLAN_H_ */
