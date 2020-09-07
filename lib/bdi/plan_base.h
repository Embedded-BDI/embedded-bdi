/*
 * plan_base.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef BDI_PLAN_BASE_H_
#define BDI_PLAN_BASE_H_

#include "belief_base.h"
#include "event.h"
#include "../syntax/plan.h"
#include <vector>
#include <cstdint>

class PlanBase
{
private:
  /// Vector of Plans
  std::vector <Plan> _plan_base;
  /// Max size of _plan_base vector
  uint8_t _size;

public:
  /**
   * PlanBase constructor
   * @param size Size of _plan_base buffer
   */
  PlanBase(uint8_t size);

  virtual ~PlanBase();

  /**
   * Adds plan to plan base
   * @param plan Plan to be added
   * @return true is plan is added, false otherwise
   */
  bool add_plan(Plan plan);

  /**
   * Revise and select applicable plan to treat event
   * @param event Event to be processed
   * @param belief_base Agent BeliefBase
   * @result Plan pointer to applicable Plan, nullptr otherwise
   */
  Plan * revise(Event * event, BeliefBase * belief_base);

  /**
   * Returns if Plan is full based on _plan_base size
   * @return True if full, false otherwise
   */
  bool is_full();

  uint8_t get_size()
  {
    return _plan_base.size();
  }
};

#endif /* BDI_PLAN_BASE_H_ */
