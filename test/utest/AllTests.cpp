/*
 * AllTests.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"

int main(int argc, char* argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  /*
   * To run specific test, uncomment the code below and add the class name to
   * the class_name variable
   */
//  std::string class_name = "TOverflowIntentionBase";
//  class_name += ".*";
//  ::testing::GTEST_FLAG(filter) = class_name;

  return RUN_ALL_TESTS();
}
