/*
 * belief_operation_test.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body/belief_operation.h"

class TBeliefOperation : public ::testing::Test {
protected:
  BeliefOperation * belief_operation;
  int belief_base_size = 2;
  int event_base_size = 2;
  BeliefBase * bb;
  EventBase * eb;

public:
  TBeliefOperation() {
    Statement stm('a');
    bb = new BeliefBase(belief_base_size);
    eb = new EventBase(event_base_size);

    belief_operation = new BeliefOperation(stm, EventOperator::EventType::BELIEF_ADDITION, bb, eb);
  }

  virtual ~TBeliefOperation() {
    delete belief_operation;
    delete bb;
    delete eb;
  }
};

/*
 * Test run instruction return
 */
TEST_F(TBeliefOperation, run_instruction) {
  for (int i = 0; i < event_base_size; i++)
  {
    EXPECT_TRUE(belief_operation->run_instruction());
  }
  EXPECT_TRUE(eb->is_full());
  EXPECT_FALSE(belief_operation->run_instruction());
}

/*
 * Test body type return
 */
TEST_F(TBeliefOperation, get_BodyTyoe) {
  EXPECT_EQ(IBodyInstruction::BodyType::BELIEF, belief_operation->get_BodyType());
}
