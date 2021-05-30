/*
 * proposition_test.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/proposition.h"

class TProposition : public ::testing::Test
{
protected:
  Proposition * prop;

public:
  TProposition()
  {
    this->prop = new Proposition(0);
  }

  ~TProposition()
  {
    delete this->prop;
  }
};

/*
 * Test return from get_name
 */
TEST_F(TProposition, get_name)
{
  EXPECT_EQ(0, prop->get_name());
}

/*
 * Test if is_equal_to compares propositions correctly
 */
TEST_F(TProposition, is_equal_to)
{
  Proposition equal(0);
  EXPECT_TRUE(prop->is_equal(equal));
  EXPECT_TRUE(prop->is_equal(&equal));
}
