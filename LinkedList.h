#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "NodeLinkedList.h"

struct LinkedList
{
	uint32_t nElems;
	Node* first;
	Node* last;
};

typedef struct LinkedList LinkedList;

#define FIRST(l) l->first
#define LAST(l) l->last
#define NELEMS(l) l->nElems

#define getNElems(l) (NELEMS(l))

LinkedList* createLinkedList();
void appendElem(LinkedList* list, int* data);
void appendElemIndex(LinkedList* list, int* data, uint32_t pos);
int popElem(LinkedList* list);
int popElemIndex(LinkedList* list, uint32_t posElem);
bool isEmpty(LinkedList* l);
uint32_t* getInt32ArrayFromList(LinkedList* l);
uint16_t* getInt16ArrayFromList(LinkedList* l);
uint8_t* getInt8ArrayFromList(LinkedList* l);
//uint32_t getNElems(LinkedList* l);
LinkedList* duplicateLinkedList(LinkedList* l);
void swapLinkedListNodes(LinkedList* l, uint32_t swapPosition1, uint32_t swapPosition2);
uint32_t getLinkedListElem(LinkedList* l,uint32_t position);
void deleteLinkedList(LinkedList* l);

#endif

