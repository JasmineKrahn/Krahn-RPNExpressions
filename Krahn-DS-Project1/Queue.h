#ifndef _QUEUE_H
#define _QUEUE_H

typedef float QueueType;
//----------------------------------------------------------------
// controls the queue and items in queue
//----------------------------------------------------------------
class Queue
{
private:
	static const int MAX_SIZE = 100;
	QueueType theQueue[MAX_SIZE];
	int front, rear, size;

public:
	Queue();
	void Enqueue(QueueType Value);
	QueueType Dequeue();
	bool IsEmpty();
	bool IsFull();
	void MakeEmpty();
	int Size();
	~Queue();
};

#endif
