/*
 * configuration.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_NB_SUBGOAL_FULL_INTENTION_BASE_CONFIGURATION_H_
#define UTEST_AGENT_NB_SUBGOAL_FULL_INTENTION_BASE_CONFIGURATION_H_

#include "bdi/belief_base.h"
#include "bdi/event_base.h"
#include "bdi/plan_base.h"
#include "bdi/intention_base.h"
#include "functions.h"

class NBSubgoalFullIntentionBase
{
private:
  Body * body_0;
  Context * context_0;
  Body * body_1;
  Context * context_1;
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  NBSubgoalFullIntentionBase()
  {
    belief_base = new BeliefBase(0);
    event_base = new EventBase(1);
    plan_base = new PlanBase(2);
    intention_base = new IntentionBase(1, 5);

    //--------------------------------------------------------------------------

    Event event_0(EventOperator::GOAL_ADDITION, 0);
    event_base->add_event(event_0);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = new Context(0);
    body_0 = new Body(4);

    Proposition prop_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_action_1);
    body_0->add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ACHIEVE);
    body_0->add_instruction(inst_1_0);

    Proposition prop_0_body_2(3);
    BodyInstruction inst_2_0(BodyType::ACTION, prop_0_body_2, action_action_2);
    body_0->add_instruction(inst_2_0);

    Proposition prop_0_body_3(4);
    BodyInstruction inst_3_0(BodyType::ACTION, prop_0_body_3, action_action_3);
    body_0->add_instruction(inst_3_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    context_1 = new Context(0);
    body_1 = new Body(1);

    Proposition prop_1_body_0(1);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_action_1);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);
  }

  ~NBSubgoalFullIntentionBase()
  {
    delete body_0;
    delete context_0;
    delete body_1;
    delete context_1;
    delete belief_base;
    delete event_base;
    delete plan_base;
    delete intention_base;
}

  BeliefBase *  get_belief_base()
  {
    return belief_base;
  }

  EventBase * get_event_base()
  {
    return event_base;
  }

  PlanBase * get_plan_base()
  {
    return plan_base;
  }

  IntentionBase * get_intention_base()
  {
    return intention_base;
  }
};

#endif /* UTEST_AGENT_NB_SUBGOAL_FULL_INTENTION_BASE_CONFIGURATION_H_ */
