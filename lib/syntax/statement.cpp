/*
 * statement.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "statement.h"

Statement::Statement() {} // @suppress("Class members should be properly initialized")

Statement::Statement(unsigned char name)
{
  _name = name;
}

Statement::~Statement() {}

bool Statement::is_equal(Statement * stm) const
{
  return (_name == stm->get_name());
}

bool Statement::is_equal(Statement stm) const
{
  return (_name == stm.get_name());
}
