/*
 * configuration.h
 *
 *  Created on: Jan 7, 2020
 *      Author: Matuzalem Muller
 */

#ifndef UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_CONFIGURATION_H_
#define UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_CONFIGURATION_H_

#include "bdi/belief_base.h"
#include "bdi/event_base.h"
#include "bdi/plan_base.h"
#include "bdi/intention_base.h"
#include "functions.h"

class NBSubgoalFailedPlan
{
private:
  Body * body_0;
  Context * context_0;
  Body * body_1;
  Context * context_1;
  Body * body_2;
  Context * context_2;
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  NBSubgoalFailedPlan()
  {
    belief_base = new BeliefBase(0);
    event_base = new EventBase(1);
    plan_base = new PlanBase(3);
    intention_base = new IntentionBase(2, 4);

    //--------------------------------------------------------------------------

    Event event_0(EventOperator::GOAL_ADDITION, 0);
    event_base->add_event(event_0);

    //--------------------------------------------------------------------------

    Proposition prop_0(0);
    context_0 = new Context(0);
    body_0 = new Body(6);

    Proposition prop_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, prop_0_body_0, action_update_1);
    body_0->add_instruction(inst_0_0);

    Proposition prop_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::GOAL, prop_0_body_1, EventOperator::GOAL_ACHIEVE);
    body_0->add_instruction(inst_1_0);

    Proposition prop_0_body_2(3);
    BodyInstruction inst_2_0(BodyType::ACTION, prop_0_body_2, action_update_2);
    body_0->add_instruction(inst_2_0);

    Proposition prop_0_body_3(4);
    BodyInstruction inst_3_0(BodyType::ACTION, prop_0_body_3, action_update_4);
    body_0->add_instruction(inst_3_0);

    Proposition prop_0_body_4(5);
    BodyInstruction inst_4_0(BodyType::ACTION, prop_0_body_4, action_update_5);
    body_0->add_instruction(inst_4_0);

    Proposition prop_0_body_5(6);
    BodyInstruction inst_5_0(BodyType::ACTION, prop_0_body_5, action_update_7);
    body_0->add_instruction(inst_5_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, prop_0, context_0, body_0);
    plan_base->add_plan(plan_0);

    //--------------------------------------------------------------------------

    Proposition prop_1(2);
    context_1 = new Context(0);
    body_1 = new Body(2);

    Proposition prop_1_body_0(7);
    BodyInstruction inst_0_1(BodyType::ACTION, prop_1_body_0, action_update_3);
    body_1->add_instruction(inst_0_1);

    Proposition prop_1_body_1(8);
    BodyInstruction inst_1_1(BodyType::ACTION, prop_1_body_1, action_return_false_bool);
    body_1->add_instruction(inst_1_1);

    Plan plan_1(EventOperator::GOAL_ADDITION, prop_1, context_1, body_1);
    plan_base->add_plan(plan_1);

    //--------------------------------------------------------------------------

    Proposition prop_2(2);
    context_2 = new Context(0);
    body_2 = new Body(1);

    Proposition prop_2_body_0(9);
    BodyInstruction inst_0_2(BodyType::ACTION, prop_2_body_0, action_update_6);
    body_2->add_instruction(inst_0_2);

    Plan plan_2(EventOperator::GOAL_DELETION, prop_2, context_2, body_2);
    plan_base->add_plan(plan_2);
  }

  ~NBSubgoalFailedPlan()
  {
    delete body_0;
    delete context_0;
    delete body_1;
    delete context_1;
    delete body_2;
    delete context_2;
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

#endif /* UTEST_AGENT_NB_SUBGOAL_FAILED_PLAN_CONFIGURATION_H_ */
