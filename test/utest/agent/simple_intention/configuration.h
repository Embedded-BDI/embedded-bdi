/*
 * configuration.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_SIMPLE_INTENTION_CONFIGURATION_H_
#define UTEST_AGENT_SIMPLE_INTENTION_CONFIGURATION_H_

#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class SimpleIntention
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
  SimpleIntention()
  {
    belief_base = new BeliefBase(1);
    event_base = new EventBase(1);
    plan_base = new PlanBase(2);
    intention_base = new IntentionBase(1, 2);

    //--------------------------------------------------------------------------

    Belief belief_belief_1(0, nullptr, false);
    belief_base->add_belief(belief_belief_1);

    //--------------------------------------------------------------------------

    Event event_1(EventOperator::GOAL_ADDITION, 1);
    event_base->add_event(event_1);

    //--------------------------------------------------------------------------

    Proposition prop_0(1);
    context_0 = new Context(0);
    body_0 = new Body(7);

    Proposition prop_0_body_0(0);
    BodyInstruction inst_0_0(BodyType::BELIEF, prop_0_body_0, EventOperator::BELIEF_ADDITION);
    body_0->add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::ACTION, prop_0_body_1, action_1_simple_intention);
    body_0->add_instruction(inst_1_0);

    Proposition prop_0_body_2(3);
    BodyInstruction inst_2_0(BodyType::ACTION, prop_0_body_2, action_2_simple_intention);
    body_0->add_instruction(inst_2_0);

    Proposition prop_0_body_3(0);
    BodyInstruction inst_3_0(BodyType::BELIEF, prop_0_body_3, EventOperator::BELIEF_DELETION);
    body_0->add_instruction(inst_3_0);

    Proposition prop_0_body_4(4);
    BodyInstruction inst_4_0(BodyType::ACTION, prop_0_body_4, action_3_simple_intention);
    body_0->add_instruction(inst_4_0);

    Proposition prop_0_body_5(5);
    BodyInstruction inst_5_0(BodyType::ACTION, prop_0_body_5, action_4_simple_intention);
    body_0->add_instruction(inst_5_0);

    Proposition prop_0_body_6(6);
    BodyInstruction inst_6_0(BodyType::ACTION, prop_0_body_6, action_5_simple_intention);
    body_0->add_instruction(inst_6_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(0);
    context_1 = new Context(0);
    body_1 = new Body(1);

    Proposition prop_1_body_0(2);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_1_simple_intention);
    body_1->add_instruction(inst_0_1);

    Plan plan_1(EventOperator::BELIEF_DELETION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);
  }

  ~SimpleIntention()
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

#endif /*UTEST_AGENT_SIMPLE_INTENTION_CONFIGURATION_H_ */
