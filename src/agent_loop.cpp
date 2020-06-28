/*
 * agent_loop.cpp
 *
 *  Created on: Jun 28, 2020
 *      Author: Matuzalem Muller
 */

#include <iostream>
#include "syntax/statement.h"

int main() {
  Statement stm('c');
  std::cout << "Statement name: " << stm.get_name() << std::endl;
}
