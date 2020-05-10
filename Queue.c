#include "Queue.h"

Queue* createQueue()
{
	return createLinkedList();
}

void insert(Queue* queue, void* data)
{
	appendElem(queue, data);
}

void insertDeepCopy(Queue* queue, void* data, userCopyFunction function)
{
	appendElemDeepCopy(queue, data, function);
}

void* extract(Queue* queue)
{
	return popElemIndex(queue, 0);
}

bool isEmpty(Queue* queue)
{
	return isEmpty(queue);
}

Queue* duplicateQueue(Queue* queue)
{
	return duplicateLinkedList(queue);
}

Queue* duplicateDeepCopyQueue(Queue* queue, userCopyFunction function)
{
	return duplicateDeepCopyLinkedList(queue, function);
}