#include<iostream>
#include "Queue.h"
#include "RPNEval.h"
#include "Stack.h"
using namespace std;

//----------------------------------------------------------------
// beings RPN evaluator
//----------------------------------------------------------------
int main()
{
   int num_expressions = 0;
   cin >> num_expressions;

   for (int i = 1; i <= num_expressions; i++)
   {
      cout << "Expression " << i << ":" << endl;
      RPNEval rpn;
      rpn.ProcessExpression();
      if (rpn.IsValid())
      {
         cout << "The value is: " << rpn.Value() << endl;
      }
      else
      {
         cout << "Invalid Expression" << endl;
      }
      cout << "The Intermediate Results are: ";
      rpn.PrintIntermediateResults();
      cout << endl;
   }

   cout << "Normal Termination of Program 1!" << endl;
   return 0;
}

