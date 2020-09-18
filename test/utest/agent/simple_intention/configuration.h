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
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;
  IntentionBase * intention_base;

public:
  SimpleIntention()
  {
    belief_base = new BeliefBase(0);
    event_base = new EventBase(1);
    plan_base = new PlanBase(1);
    intention_base = new IntentionBase(1, 4);

    //--------------------------------------------------------------------------

    event_base->add_event(EventOperator::GOAL_ADDITION, 0);

    //--------------------------------------------------------------------------

    Statement stm_0(0);
    Context * context_0 = new Context(0);
    Body * body_0 = new Body(5);

    Statement stm_0_body_0(1);
    BodyInstruction inst_0_0(BodyType::ACTION, stm_0_body_0, action_1_simple_intention);
    body_0->add_instruction(inst_0_0);

    Statement stm_0_body_1(2);
    BodyInstruction inst_1_0(BodyType::ACTION, stm_0_body_1, action_2_simple_intention);
    body_0->add_instruction(inst_1_0);

    Statement stm_0_body_2(3);
    BodyInstruction inst_2_0(BodyType::ACTION, stm_0_body_2, action_3_simple_intention);
    body_0->add_instruction(inst_2_0);

    Statement stm_0_body_3(4);
    BodyInstruction inst_3_0(BodyType::ACTION, stm_0_body_3, action_4_simple_intention);
    body_0->add_instruction(inst_3_0);

    Statement stm_0_body_4(5);
    BodyInstruction inst_4_0(BodyType::ACTION, stm_0_body_4, action_5_simple_intention);
    body_0->add_instruction(inst_4_0);

    Plan plan_0(EventOperator::GOAL_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);
  }

  ~SimpleIntention()
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

#endif /*UTEST_AGENT_SIMPLE_INTENTION_CONFIGURATION_H_ */
