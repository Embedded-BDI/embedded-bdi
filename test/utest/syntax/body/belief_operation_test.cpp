/*
 * belief_operation_test.cpp
 *
 *  Created on: Jul 3, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/body/belief_operation.h"

class TBeliefOperation : public ::testing::Test
{
protected:
  BeliefOperation * belief_operation;
  Statement * stm;
  BeliefBase * bb;
  EventBase * eb;
  int belief_base_size = 2;
  int event_base_size = 2;

public:
  TBeliefOperation()
  {
    stm = new Statement('a');

    bb = new BeliefBase(belief_base_size);
    eb = new EventBase(event_base_size);

    belief_operation = new BeliefOperation(*stm, EventOperator::BELIEF_ADDITION);
  }

  virtual ~TBeliefOperation()
  {
    delete belief_operation;
    delete stm;
    delete bb;
    delete eb;
  }
};

/*
 * Test run instruction return
 */
TEST_F(TBeliefOperation, run_instruction)
{
  for (int i = 0; i < event_base_size; i++)
  {
    EXPECT_TRUE(belief_operation->run_instruction(bb, eb));
  }
  EXPECT_TRUE(eb->is_full());
  EXPECT_FALSE(belief_operation->run_instruction(bb, eb));
  for (int i = 0; i < event_base_size; i++)
  {
    EXPECT_TRUE(stm->is_equal(eb->get_event()->get_statement()));
  }
}

/*
 * Test body type return
 */
TEST_F(TBeliefOperation, get_BodyType)
{
  EXPECT_EQ(BodyType::BELIEF, belief_operation->get_BodyType());
}
