/*
 * AllTests.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}