//============================================================================
// Name        : lib.cpp
// Author      : Matuzalem Muller
// Version     :
// Copyright   : License: MIT
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "gtest/gtest.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv []) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
