#ifndef _STACK_H
#define _STACK_H

typedef float StackType;

//----------------------------------------------------------------
// controls the stack and items in stack
//----------------------------------------------------------------
class Stack
{
private:
	static const int MAX_SIZE = 100;
	int top, size;
	StackType theStack[MAX_SIZE];

public:
	Stack();
	void Push(StackType value);
	StackType Pop();
	StackType Top();
	bool IsEmpty();
	bool IsFull();
	int Size();
	~Stack();
};

#endif

