#include "NodeLinkedList.h"
/*
void* copyDataToNode(void* data, Types type)
{
	switch(type)
	{
		case UINT8:
		case CHAR:
			uint8_t* p = (uint8_t* )malloc(sizeof(uint8_t));
			*p = *(uint8_t *)data;
			break;
		case UINT16:
			uint16_t *p = (uint16_t* )malloc(sizeof(uint16_t));
			*p = *(uint16_t *)data;
			break;
		case UINT32:
			uint32_t *p = (uint32_t* )malloc(sizeof(uint32_t));
			*p = *(uint32_t *)data;
			break;
		case UINT64:
			uint64_t *p = (uint64_t* )malloc(sizeof(uint64_t));
			*p = *(uint16_t *)data;
			break;
		case INT8:
			int8_t *p = (int8_t* )malloc(sizeof(int8_t));
			*p = *(int8_t *)data; 
			break;
		case INT16:
			int16_t *p = (int16_t* )malloc(sizeof(int16_t));
			*p = *(int16_t *)data;
			break;
		case INT32:
			int32_t *p = (int32_t* )malloc(sizeof(int32_t));
			*p = *(uint32_t *)data;
			break;
		case INT64:
			int64_t *p = (int64_t* )malloc(sizeof(int64_t));
			*p = *(uint64_t *)data;
			break;
		case FLOAT:
			float *p = (float* )malloc(sizeof(float));
			*p = *(float *)data;
			break;
		case DOUBLE:
			double* p = (double* )malloc(sizeof(double));
			*p = *(double *)data;
			break;
		case LONGDOUBLE:
			long double* p = (double* )malloc(sizeof(long double));
			*p = *(long double *)data;
			break;		
	}

	return p;
}

Types obtainDataType(void* data)
{
	int64_t intValue = *(int64_t* )data;
	double doubleValue = *(double *)data;
	Type t = UINT8_T;

	if(intValue == doubleValue)
	{
		if(intValue < DFT_MAX_U8)
			return UINT8;
		else if(intValue < DFT_MAX_U16)
			return UINT16;
		else if(intValue < DFT_MAX_U32)
			return UINT32;
		else if(intValue < DFT_MAX_U64)
			return UINT64;
	}
	else
	{
		if(doubleValue < DFT_MAX_FLOAT)
			return FLOAT;
		else if(doubleValue < DFT_MAX_DOUBLE)
			return DOUBLE;
		else
			return LONGDOUBLE;
	}
}
*/
Node* createNode(int* data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->previous = NULL;
	node->next = NULL;
	//node->dataType = obtainDataType(void* data);
	node->data = *data;//copyDataToNode(data,node->dataType);	
	
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

/*
int getDataNode(Node* node)
{
	return node->data;
}

Node* getPreviousNode(Node* node)
{
	return (Node*)PREVIOUS(node);
}

Node* getNextNode(Node* node)
{
	return (Node*)NEXT(node);
}
*/

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

void swapNodes(Node* n1, Node* n2)
{
	PREVIOUS(NEXT(n2)) = n1;
	NEXT(PREVIOUS(n2)) = n1;
	PREVIOUS(NEXT(n1)) = n2;
	NEXT(PREVIOUS(n1)) = n2;

	Node* n = PREVIOUS(n2);
	PREVIOUS(n2) = PREVIOUS(n1);
	PREVIOUS(n1) = n;

	n = NEXT(n2);
	NEXT(n2) = NEXT(n1);
	NEXT(n1) = n;	

	return;
}
	
void freeNodeLinkedList(Node* node)
{
	//DATA(node) = NULL;
	NEXT(node) = NULL;
	PREVIOUS(node) = NULL;

	free(node);
	node = NULL;	
}

void moveNode(Node* n1, Node* n2)
{    
    
    if(NEXT(n2) != NULL)
        PREVIOUS(NEXT(n2)) = PREVIOUS(n2);
    
    if(PREVIOUS(n2) != NULL)
        NEXT(PREVIOUS(n2)) = NEXT(n2);
    
     if(PREVIOUS(n1) != NULL)
        NEXT(PREVIOUS(n1)) = n2;
    
    PREVIOUS(n2) = PREVIOUS(n1);
    PREVIOUS(n1) = n2;
    
    NEXT(n2) = n1;

    return;
}