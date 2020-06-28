/*
 * TStatement.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/statement.h"

class TStatement : public ::testing::Test {};

TEST_F(TStatement, failingTest) {
	Statement stm2('c');
	EXPECT_EQ('c', stm2.get_name());
}
