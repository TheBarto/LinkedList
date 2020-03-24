#ifndef SORTMETHODS_H
#define SORTMETHODS_H 

#include "LinkedList.h"
#include "defines.h"

typedef int8_t (compareFunction)(LinkedList*, uint32_t, uint32_t);
typedef uint32_t(pivotFunction)(LinkedList*, int32_t, int32_t);

int8_t compareLinkedListIntsNumericValues(LinkedList* l, uint32_t i, uint32_t j);
int8_t compareLinkedListIntNumericValue(LinkedList* l, uint32_t i, uint32_t value);

uint32_t linkedListPivote(LinkedList* l, int32_t P, int32_t U);

void linkedListBubbleSort(LinkedList* l, compareFunction function);
uint8_t linkedListMergeSort(LinkedList* l, uint32_t P, uint32_t U, compareFunction function);
void linkedListCombinar(LinkedList* l, uint32_t P, uint32_t M, uint32_t U, compareFunction function);
uint8_t linkedListQuickSort(LinkedList* l, int32_t P, int32_t U, pivotFunction pFunction, compareFunction cFunction);
uint32_t linkedListSplit(LinkedList* l, int32_t P, int32_t U, pivotFunction pFunction, compareFunction cFunction);


#endif