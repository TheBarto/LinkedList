#include "LinkedList.h"

LinkedList* createLinkedList()
{
	LinkedList* l = (LinkedList *)malloc(sizeof(LinkedList));
	NELEMS(l) = DFT_CERO_U32;
	FIRST(l) = NULL;
	LAST(l) = NULL;

	return l;
}

void appendElem(LinkedList* list, int* data)
{
	if(!LAST(list))
	{
		FIRST(list) = createNode(data);
		LAST(list) = FIRST(list);
	}
	else
	{
		Node* node = createNode(data);
		addNewNodeNext(LAST(list), node);
		LAST(list) = node;
		
	}

	NELEMS(list)++;
	return;
}

void appendElemIndex(LinkedList* list, int* data, uint32_t pos)
{
	uint32_t i = DFT_CERO_U32;
	Node* node = FIRST(list);
	for(; i < (pos-1); i++, node = getNextNode(node));
	
	addNewNode(node, createNode(data));
	NELEMS(list)++;
}

int popElem(LinkedList* list)
{
	NELEMS(list)--;
	LAST(list) = PREVIOUS(LAST(list));
	
	return deleteNode((NEXT(LAST(list))));
}

int popElemIndex(LinkedList* list, uint32_t posElem)
{
	NELEMS(list)--;
	uint32_t i = DFT_CERO_U32;
	Node* node = NULL;
	for(node = FIRST(list); i < (posElem); i++, node = getNextNode(node));

	if(posElem == 0)
		FIRST(list) = NEXT(FIRST(list));
	if(posElem == NELEMS(list))
		LAST(list) = PREVIOUS(LAST(list));
	
	return deleteNode(node);
}

bool isEmpty(LinkedList* list)
{
	if(NELEMS(list) == DFT_CERO_U32)
		return TRUE;

	return FALSE;
}

uint32_t* getInt32ArrayFromList(LinkedList* list)
{
	uint32_t* array = (uint32_t*)malloc(NELEMS(list)*sizeof(array));
	uint32_t i = DFT_CERO_U32;
	Node* node = FIRST(list);

	for(; i < NELEMS(list); i++, node = getNextNode(node))
	{
		*(array + i) = getDataNode(node);
	}

	return array;
}

uint16_t* getInt16ArrayFromList(LinkedList* list)
{
	uint16_t* array = (uint16_t*)malloc(NELEMS(list)*sizeof(array));
	uint32_t i = DFT_CERO_U32;
	Node* node = FIRST(list);

	for(; i < NELEMS(list); i++, node = getNextNode(node))
	{
		*(array + i) = *(uint16_t *)getDataNode(node);
	}

	return array;
}

uint8_t* getInt8ArrayFromList(LinkedList* list)
{
	uint8_t* array = (uint8_t*)malloc(NELEMS(list)*sizeof(array));
	uint32_t i = DFT_CERO_U32;
	Node* node = FIRST(list);

	for(; i < NELEMS(list); i++, node = getNextNode(node))
	{
		*(array + i) = *(uint8_t *)getDataNode(node);
	}

	return array;
}

uint32_t getLinkedListElem(LinkedList* list, uint32_t position)
{
	uint32_t i = DFT_CERO_U32;
	Node* n = FIRST(list);
	for(; i < position; i++, n = getNextNode(n));

	return n->data;
}

void swapLinkedListNodes(LinkedList* list, uint32_t swapPosition1, uint32_t swapPosition2)
{
	uint32_t i = 0;
	Node* n1 = FIRST(list);
	Node* n2 = FIRST(list);

	for(;i<swapPosition1;i++,n1=NEXT(n1));
	for(i=0;i<swapPosition2;i++,n2=NEXT(n2));

	swapValueNodes(&n1->data,&n2->data);
	
	return;
}

LinkedList* duplicateLinkedList(LinkedList* list)
{
	LinkedList* listNew = createLinkedList();
	uint32_t i = 0;	

	for(; i < NELEMS(list); i++){
		int32_t value = getLinkedListElem(list,i);
		appendElem(listNew, &value);
	}
	
	return listNew;
}

void deleteLinkedList(LinkedList* list)
{
	Node* n = FIRST(list);
	Node* n2 = NEXT(FIRST(list));	

	while(n2)
	{
		freeNodeLinkedList(n);
		n = n2;
		n2 = NEXT(n2);
	}	

	freeNodeLinkedList(n);
	free(list);
	list = NULL;
}
