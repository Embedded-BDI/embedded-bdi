/*
 * agent_settings.h
 *
 *  Created on: May 31, 2020
 *      Author: Matuzalem Muller
 */

#ifndef LIB_AGENT_SETTINGS_H_
#define LIB_AGENT_SETTINGS_H_

class AgentSettings {
private:
  int _plan_body_size;
  int _belief_base_size;
  int _event_queue_size;
  int _intention_queue_size;
  int _intention_stack_size;

public:
  AgentSettings(int plan_body_size, int belief_base_size, int event_queue_size,
      int intention_queue_size, int intention_stack_size)
  {
    this->_plan_body_size = plan_body_size;
    this->_belief_base_size = belief_base_size;
    this->_event_queue_size = event_queue_size;
    this->_intention_queue_size = intention_queue_size;
    this->_intention_stack_size = intention_stack_size;
  }

  virtual ~AgentSettings();

  int getBeliefBaseSize() const {
    return _belief_base_size;
  }

  int getEventQueueSize() const {
    return _event_queue_size;
  }

  int getIntentionQueueSize() const {
    return _intention_queue_size;
  }

  int getIntentionStackSize() const {
    return _intention_stack_size;
  }

  int getPlanBodySize() const {
    return _plan_body_size;
  }
};

#endif /* LIB_AGENT_SETTINGS_H_ */
