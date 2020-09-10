/*
 * statement_test.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/statement.h"

class TStatement : public ::testing::Test
{
protected:
  Statement * stm;

public:
  TStatement()
  {
    this->stm = new Statement(0);
  }

  ~TStatement()
  {
    delete this->stm;
  }
};

/*
 * Test return from get_name
 */
TEST_F(TStatement, get_name)
{
  EXPECT_EQ(0, stm->get_name());
}

/*
 * Test if is_equal_to compares statements correctly
 */
TEST_F(TStatement, is_equal_to)
{
  Statement equal(0);
  EXPECT_TRUE(stm->is_equal(equal));
  EXPECT_TRUE(stm->is_equal(&equal));
}
