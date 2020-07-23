/*
 * context_test.cpp
 *
 *  Created on: Jul 23, 2020
 *      Author: Matuzalem Muller
 */

#include "gtest/gtest.h"
#include "syntax/context.h"
#include <vector>

class TContext : public ::testing::Test
{
protected:
  BeliefBase * belief_base;
  Context * context;
  std::vector<ContextCondition> cxt_c;
  int size = 1;                                      // min size = 1
                                                     // max size = 26
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f',
                       'g', 'h', 'i', 'j', 'k', 'l',
                       'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x',
                       'y', 'z'};

public:
  TContext()
  {
    context = new Context(size);
    belief_base = new BeliefBase(size);

    // Adds belief to BeliefBase with true value
    // Adds statement to ContextCondition with expected value as true
    for (int i = 0; i < size-1; i++)
    {
      Statement stm(alphabet[i]);

      ContextCondition ctx(stm, true);
      cxt_c.push_back(ctx);

      Belief belief(stm, NULL, true);
      belief_base->add_belief(belief);
    }

    // Adds belief to BeliefBase with false value
        // Adds statement to ContextCondition with expected value as false
    Statement stm(alphabet[size-1]);

    ContextCondition ctx(stm, false);
    cxt_c.push_back(ctx);

    Belief belief(stm, NULL, false);
    belief_base->add_belief(belief);
  }

  virtual ~TContext()
  {
    delete context;
  }
};

/*
 * Test add_belief method
 */
TEST_F(TContext, add_belief)
{
  for (int i = 0; i < size; i++)
  {
    EXPECT_TRUE(context->add_belief(cxt_c.at(i)));
  }
  EXPECT_FALSE(context->add_belief(cxt_c.at(size-1)));
}

/*
 * Test if context is properly checked/validated
 */
TEST_F(TContext, is_valid)
{
  for (int i = 0; i < size; i++)
  {
    EXPECT_TRUE(context->add_belief(cxt_c.at(i)));
  }
  EXPECT_TRUE(context->is_valid(belief_base));
}
