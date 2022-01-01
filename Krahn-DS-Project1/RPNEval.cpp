#include <iostream>
#include <iomanip>
#include "RPNEval.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

//----------------------------------------------------------------
// Uses the input to decide the next steps in evaluating the RPN
//----------------------------------------------------------------
void RPNEval::ProcessExpression()
{
   char ch;
   while (valid && !done)
   {
      cin >> ch;

      if (ch >= '0' && ch <= '9')
      {
         cin.putback(ch);
         ProcessOperand();
      }
      else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
      {
         cout << ch << " ";
         ProcessOperator(ch);
      }
      else if (ch == '#')
         done = true;
      else
      {
         cout << ch << " ";
         valid = false;
      }
   }
   cin.ignore(256, '\n');
   cout << endl;

   if (stack.IsEmpty())
      valid = false;
   else if (valid)
   {
      answer = stack.Pop();
      if (!stack.IsEmpty())
         valid = false;
   }
}

//----------------------------------------------------------------
// prints the intermediate steps
//----------------------------------------------------------------
void RPNEval::PrintIntermediateResults()
{
   while (!queue.IsEmpty())
   {
       cout << queue.Dequeue() << " ";
   }
   cout << endl;
}

//----------------------------------------------------------------
// proccesses the RPN when an operand is reached by assing it to the stack.
//----------------------------------------------------------------
void RPNEval::ProcessOperand()
{
   float floatOp;
   cin >> floatOp;
   cout << floatOp << " ";
   stack.Push(floatOp);
}

//----------------------------------------------------------------
// Process the RPN when an operator is reached by poping two
//  operandsand completeing the calculation.
//----------------------------------------------------------------
void RPNEval::ProcessOperator(char ch)
{
    if (stack.Size() > 1)
    {
        OperandType operand2 = stack.Pop();
        OperandType operand1 = stack.Pop();

        switch (ch)
        {
        case '+':
            answer = operand1 + operand2;
            queue.Enqueue(answer);
            stack.Push(answer);
            break;
        case '-':
            answer = operand1 - operand2;
            queue.Enqueue(answer);
            stack.Push(answer);
            break;
        case '*':
            answer = operand1 * operand2;
            queue.Enqueue(answer);
            stack.Push(answer);
            break;
        case '/':
            if (operand2 != 0)
            {
                answer = operand1 / operand2;
                queue.Enqueue(answer);
                stack.Push(answer);
            }
            else
                valid = false;
            break;
        default:
            break;
        }
    }
    else
        valid = false;
}

