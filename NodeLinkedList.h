#ifndef NODELINKEDLIST_H
#define NODELINKEDLIST_H 

#include <stdlib.h>
#include <stdio.h>
#include "defines.h"

struct Node
{
	/*void *data;
	Types dataType;*/
	int data;
	struct Node* next;
	struct Node* previous;
};

typedef struct Node Node;

#define NEXT(n) n->next
#define PREVIOUS(n) n->previous
#define DATA(n) n->data

#define getDataNode(node) (DATA(node))
#define getPreviousNode(node) (PREVIOUS(node))
#define getNextNode(node) (NEXT(node))

Node* createNode(int* data);
int destroyNode(Node* node);
/*int getDataNode(Node* node);
Node* getPreviousNode(Node* node);
Node* getNextNode(Node* node);*/
void addNewNodeNext(Node* last, Node* newLast);
void addNewNode(Node* node, Node* newNode);
int deleteNode(Node* node);
void swapValueNodes(int* n1, int* n2);
void freeNodeLinkedList(Node* node);
/*void* copyDataToNode(void* data, Types type);
Types obtainDataType(void* data);*/


#endif 
