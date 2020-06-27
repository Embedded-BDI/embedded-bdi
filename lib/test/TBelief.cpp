/*
 * TBelief.cpp
 *
 *  Created on: Jun 27, 2020
 *      Author: Matuzalem Muller
 */


#include "gtest/gtest.h"
#include "syntax/statement.h"

class TBelief : public ::testing::Test {
protected:
  Statement stm;
};

TEST_F(TBelief, failingTest) {
  ASSERT_TRUE(false);
}
