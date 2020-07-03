/*
 * statement.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "statement.h"

Statement::Statement() {} // @suppress("Class members should be properly initialized")

Statement::Statement(unsigned char name) { // @suppress("Class members should be properly initialized")
   _name = name;
}

Statement::~Statement() {}

//bool Statement::is_equal_to(unsigned char name) {
//  return (_name == name);
//}
