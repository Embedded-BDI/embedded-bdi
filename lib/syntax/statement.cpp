/*
 * statement.cpp
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#include "statement.h"

Statement::Statement() {
  _name = 0;
}

Statement::Statement(std::uint8_t name)
{
  _name = name;
}

bool Statement::is_equal(Statement * stm) const
{
  return (_name == stm->get_name());
}

bool Statement::is_equal(Statement stm) const
{
  return (_name == stm.get_name());
}
