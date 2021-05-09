#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include "defines.h"

typedef struct Node Stack;

Stack* createStack();
void push(Stack* stack, void* data);
void pushDeepCopy(Stack* stack, void* data, userCopyFunction function);
void* pop(Stack* stack);
bool isEmpty(Stack* stack);

Stack* duplicateStack(Stack* stack);
Stack* duplicateDeepCopyStack(Stack* stack, userCopyFunction function);

void deleteStack(Stack* stack);
void deleteDeepCopyStack(Stack* stack);

uint32_t getUInt32ArrayWithStackElements(LinkedList* list, uint32_t* array);

#endif