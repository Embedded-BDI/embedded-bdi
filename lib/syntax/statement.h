/*
 * statement.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_STATEMENT_H_
#define SYNTAX_STATEMENT_H_

#include <cstdint>

/**
 * Represents statement.
 */
class Statement
{
private:
  /// Statement name
  std::uint8_t _name;

public:
  Statement();

  Statement(std::uint8_t name);

  /**
   * Compares value of current statement with given statement.
   * @param stm Statement to be compared
   * @return true if equal, false otherwise
   */
  bool is_equal(Statement stm) const;

  /**
   * Compares value of current statement with given statement.
   * @param stm Pointer to statement to be compared
   * @return true if equal, false otherwise
   */
  bool is_equal(Statement * stm) const;

  const std::uint8_t & get_name() const
  {
    return _name;
  }
};

#endif /* SYNTAX_STATEMENT_H_ */
