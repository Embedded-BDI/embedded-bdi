#include "../../lib/bdi/belief_base.h"
#include "../../lib/bdi/event_base.h"
#include "../../lib/bdi/plan_base.h"
#include "../../lib/bdi/intention_base.h"
#include "functions.h"

class AgentSettings
{
private:
  BeliefBase * belief_base;
  EventBase * event_base;
  PlanBase * plan_base;

public:
  AgentSettings()
  {
    belief_base = new BeliefBase(2);
    event_base = new EventBase(2);
    plan_base = new PlanBase(1);

    Belief belief_0(0, update_statement_1 , false);
    belief_base->add_belief(belief_0);

    Belief belief_1(1, nullptr , false);
    belief_base->add_belief(belief_1);

    event_base->add_event(EventOperator::BELIEF_ADDITION, 0);
    event_base->add_event(EventOperator::BELIEF_DELETION, 2);

    Statement stm_0(0);

    Context * context_0 = new Context(2);

    Statement stm_1(0);
    ContextCondition cond_0(stm_0, true);
    context_0->add_context(cond_0);

    Statement stm_2(1);
    ContextCondition cond_1(stm_1, false);
    context_0->add_context(cond_1);

    Body * body_0 = new Body(2);

    Statement stm_3(3);
    BodyInstruction inst_0(BodyType::GOAL, stm_3, EventOperator::GOAL_ADDITION);
    body_0->add_instruction(inst_0);

    Statement stm_4(4);
    BodyInstruction inst_0(BodyType::ACTION, stm_4, action_do_action);
    body_0->add_instruction(inst_0);

    Plan plan_0(EventOperator::BELIEF_ADDITION, stm_0, context_0, body_0);
    plan_base->add_plan(plan_0);
  }

  ~AgentSettings()
  {
    delete belief_base;
    delete event_base;
    delete plan_base;
  }

  BeliefBase * get_belief_base()
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
};