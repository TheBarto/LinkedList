#include "NodeLinkedList.h"

Node* createNode(int* data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->previous = NULL;
	node->next = NULL;
	node->data = *data;
	
	return node;
}

int destroyNode(Node* node)
{
	PREVIOUS(node) = NULL;
	NEXT(node) = NULL;
	int data = DATA(node);
	free(node);
	node = NULL;

	return data;
}

void addNewNodeNext(Node* last, Node* newLast)
{
	PREVIOUS(newLast) = (struct Node*)last;
	NEXT(last) = (struct Node*)newLast;
	NEXT(newLast) = NULL;
	
	return;
}

void addNewNode(Node* node, Node* newNode)
{
	NEXT(newNode) = NEXT(node);
	PREVIOUS(newNode) = (struct Node*)node;
	PREVIOUS(NEXT(newNode)) = (struct Node*)newNode;
	NEXT(node) = (struct Node*)newNode;

	return;
}

int deleteNode(Node* node)
{
	if(NEXT(node) != NULL)
		PREVIOUS(NEXT(node)) = PREVIOUS(node);
	if(PREVIOUS(node) != NULL)
		NEXT(PREVIOUS(node)) = NEXT(node);
	
	return destroyNode(node);
}

void swapValueNodes(int* n1, int* n2)
{
	int p = *n1;
	*n1 = *n2;
	*n2 = p;

	return;
}
	
void freeNodeLinkedList(Node* node)
{
	NEXT(node) = NULL;
	PREVIOUS(node) = NULL;

	free(node);
	node = NULL;	
}
