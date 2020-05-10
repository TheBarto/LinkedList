#include "Stack.h"

Stack* createStack()
{
	return createLinkedList();
}

void push(Stack* stack, void* data)
{
	appendElem(stack, data);
}

void pushDeepCopy(Stack* stack, void* data, userCopyFunction function)
{
	appendElemDeepCopy(stack, data, function);
}

void* pop(Stack* stack)
{
	return popElem(stack);
}

bool isEmpty(Stack* stack)
{
	return isEmpty(stack);
}

Stack* duplicateStack(Stack* stack)
{
	return duplicateLinkedList(stack);
}

Stack* duplicateDeepCopyStack(Stack* stack, userCopyFunction function)
{
	return duplicateDeepCopyLinkedList(stack, function);
}