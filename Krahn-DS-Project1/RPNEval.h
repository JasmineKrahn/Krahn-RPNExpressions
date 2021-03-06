#pragma once

#ifndef __RPNEVAL_H
#define __RPNEVAL_H
#include "Stack.h"
#include "Queue.h"

typedef float OperandType;

class RPNEval
{
public:
   //----------------------------------------------------------------
   // RPNEval constructor
   //----------------------------------------------------------------
   RPNEval()
   { 
      valid = true;
      done = false;
      answer = 0;
   }
   //----------------------------------------------------------------
// Reads and processes the next RPN expression from the input.
//----------------------------------------------------------------
   void ProcessExpression();
   //----------------------------------------------------------------
   // Returns true if RPN expression is valid, false otherwise.
   //----------------------------------------------------------------
   bool IsValid() const { return valid; }
   //----------------------------------------------------------------
// Returns the value of the RPN expression if it is valid.
// Returns garbage if RPN expression is not valid.
//----------------------------------------------------------------
   OperandType Value() const { return answer; }
   //----------------------------------------------------------------
   // Print out the intermediate results to the standard
   // output, with one space after each result.
   // Does NOT print any header or any newlines.
   //----------------------------------------------------------------
   void PrintIntermediateResults();

private:
   bool valid; // Is RPN expression valid?
   bool done; //Has the expression fully been read in
   OperandType answer; // Value of RPN expression if it is valid
   Stack stack; // Used to process RPN
   Queue queue; // Used to store intermediate results
   // You can't add any more private member variables but
   // you MUST have some private methods! (at least 2)
   void ProcessOperand(); //completes steps required for operand
   void ProcessOperator(char ch); //completes step for an operator
};
#endif
