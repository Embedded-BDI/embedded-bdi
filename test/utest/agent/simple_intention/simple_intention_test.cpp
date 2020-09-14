/*
 * run_simple_intention_test.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Matuzalem Muller
 */
#include "gtest/gtest.h"
#include "agent/agent.h"
#include "configuration.h"
#include "socket_functions.h"

#include <thread>

class TSimpleIntentionTest : public ::testing::Test
{
protected:
  Agent * agent;
  BeliefBase * beliefs;
  EventBase * events;
  PlanBase * plans;
  IntentionBase * intentions;
  SimpleIntentionTest * empty_event_base_config;

public:
  TSimpleIntentionTest()
  {
    empty_event_base_config = new SimpleIntentionTest();

    beliefs = empty_event_base_config->get_belief_base();
    events = empty_event_base_config->get_event_base();
    plans = empty_event_base_config->get_plan_base();
    intentions = empty_event_base_config->get_intention_base();

    agent = new Agent(beliefs, events, plans, intentions);
  }

  ~TSimpleIntentionTest()
  {
    delete this->empty_event_base_config;
    delete this->agent;
  }
};

TEST_F(TSimpleIntentionTest, test)
{
  bool server_result;

  std::thread th1(server, 12340, 1, &server_result);
  wait_for_server();
  agent->run();
  th1.join();
  EXPECT_TRUE(server_result);

  usleep(400000);

  std::thread th2(server, 12341, 2, &server_result);
  wait_for_server();
  agent->run();
  th2.join();
  EXPECT_TRUE(server_result);

  usleep(400000);

  std::thread th3(server, 12342, 3, &server_result);
  wait_for_server();
  agent->run();
  th3.join();
  EXPECT_TRUE(server_result);

  usleep(400000);

  std::thread th4(server, 12343, 4, &server_result);
  wait_for_server();
  agent->run();
  th4.join();
  EXPECT_TRUE(server_result);

  usleep(400000);

  std::thread th5(server, 12344, 5, &server_result);
  wait_for_server();
  agent->run();
  th5.join();
  EXPECT_TRUE(server_result);
}
