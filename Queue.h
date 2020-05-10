#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include "defines.h"

typedef struct Node Queue;

Queue* createQueue();
void insert(Queue* queue, void* data);
void insertDeepCopy(Queue* queue, void* data, userCopyFunction function);
void* extract(Queue* queue);
bool isEmpty(Queue* queue);

Queue* duplicateQueue(Queue* queue);
Queue* duplicateDeepCopyQueue(Queue* queue, userCopyFunction function);

#endif