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
    Proposition prop(0);
    this->belief = new Belief(prop, always_opposite, false);
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
 * Test if proposition is stored correctly
 */
TEST_F(TBelief, get_proposition)
{
  Proposition prop(0);
  EXPECT_EQ(0, belief->get_proposition().get_name());
  EXPECT_TRUE(belief->get_proposition().is_equal(prop));
}
