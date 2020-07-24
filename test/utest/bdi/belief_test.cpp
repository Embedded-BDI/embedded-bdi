/*
 * belief_test.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "bdi/belief.h"

bool always_opposite(bool var)
{
  return !var;
}

class TBelief : public ::testing::Test
{
protected:
  Belief * belief;

public:
  TBelief()
  {
    Statement stm('a');
    this->belief = new Belief(stm, always_opposite, false);
  }

  ~TBelief()
  {
    delete this->belief;
  }
};

/*
 * Test updating belief
 */
TEST_F(TBelief, update_belief)
{
  EXPECT_TRUE(belief->update_belief());
  EXPECT_TRUE(belief->update_belief());
}

/*
 * Test if state can be modified
 */
TEST_F(TBelief, change_state)
{
  belief->change_state(true);
  EXPECT_TRUE(belief->get_state());
  belief->change_state(false);
  EXPECT_FALSE(belief->get_state());
}

/*
 * Test if statement is stored correctly
 */
TEST_F(TBelief, get_statement)
{
  Statement stm('a');
  EXPECT_EQ('a',belief->get_statement().get_name());
  EXPECT_TRUE(belief->get_statement().is_equal(stm));
}
