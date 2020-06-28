/*
 * statement.h
 *
 *  Created on: May 25, 2020
 *      Author: Matuzalem Muller
 */

#ifndef SYNTAX_STATEMENT_H_
#define SYNTAX_STATEMENT_H_

class Statement {
private:
   unsigned char _name;

public:
   Statement();

   Statement(unsigned char name);

   virtual ~Statement();

   bool is_equal_to(unsigned char name) const {
     return (this->_name == name);
   }

   const unsigned char & get_name() const {
      return this->_name;
   }
};

#endif /* SYNTAX_STATEMENT_H_ */
