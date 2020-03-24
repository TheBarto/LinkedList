#ifndef SORTMETHODS_H
#define SORTMETHODS_H 

#include "LinkedList.h"
#include "defines.h"

void linkedListBubbleSort(LinkedList* l);
uint8_t linkedListMergeSort(LinkedList* l, uint32_t P, uint32_t U);
void linkedListCombinar(LinkedList* l, uint32_t P, uint32_t M, uint32_t U);
uint8_t linkedListQuickSort(LinkedList* l, int32_t P, int32_t U);
uint32_t linkedListSplit(LinkedList* l, int32_t P, int32_t U);
uint32_t linkedListPivote(LinkedList* l, int32_t P, int32_t U);

#endif