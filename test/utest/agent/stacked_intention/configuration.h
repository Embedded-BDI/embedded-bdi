/*
 * configuration.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_STACKED_INTENTION_CONFIGURATION_H_
#define UTEST_AGENT_STACKED_INTENTION_CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class StackedIntention
{
private:
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  StackedIntention()
  {
    belief_base = new BeliefBase(0);
    event_base = new EventBase(1);
    plan_base = new PlanBase(3);
    intention_base = new IntentionBase(1, 3);

    //--------------------------------------------------------------------------

    Event event(EventOperator::GOAL_ADDITION, 0);
    event_base->add_event(event);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(2);

    Proposition prop_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_1_stacked_intention);
    body_0->add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ADDITION);
    body_0->add_instruction(inst_1_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    Context * context_1 = new Context(0);
    Body * body_1 = new Body(2);

    Proposition prop_1_body_0(3);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_2_stacked_intention);
    body_1->add_instruction(inst_0_1);

    Proposition prop_1_body_1(4);
    BodyInstruction inst_1_1(BodyType::GOAL, prop_1_body_1, EventOperator::GOAL_ADDITION);
    body_1->add_instruction(inst_1_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(4);
    Context * context_2 = new Context(0);
    Body * body_2 = new Body(1);

    Proposition prop_2_body_0(5);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_3_stacked_intention);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::GOAL_ADDITION, prop_2, context_2, body_2);
    plan_base->add_plan(plan_2);
  }

  ~StackedIntention()
  {
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

#endif /* UTEST_AGENT_STACKED_INTENTION_CONFIGURATION_H_ */
