/*
 * agent.h
 *
 *  Created on: Sep 10, 2020
 *      Author: Matuzalem Muller
 */

#ifndef AGENT_AGENT_H_
#define AGENT_AGENT_H_

#include "../bdi/belief_base.h"
#include "../bdi/event_base.h"
#include "../bdi/intention_base.h"
#include "../bdi/plan_base.h"

/**
 * Implements the agent reasoning cycle.
 */
class Agent
{
private:
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  Plan * plan_to_act;
  Event event_to_process;

public:
  Agent(BeliefBase * beliefs,
        EventBase * events,
        PlanBase * plans,
        IntentionBase * intentions);

  /**
   * Runs an iteration of the agent reasoning cycle
   */
  void run();
};

#endif /* AGENT_AGENT_H_ */
