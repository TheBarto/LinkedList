#include "SortMethods.h"

void linkedListBubbleSort(LinkedList* l, compareFunction function)
{
	uint8_t flag = TRUE;
	uint32_t i = getNElems(l);
	
	while(i > 0 && flag == TRUE)
	{
		flag = FALSE;
		for(uint32_t j = DFT_CERO_U32; j < i-1; j++)
		{
			if(function(l,j,(j+1)) == 1)
			{
				swapLinkedListValueNodes(l,j,(j+1));
				flag = TRUE;
			}
		}
		i--;
	}
	return;
}

uint8_t linkedListMergeSort(LinkedList* l, uint32_t P, uint32_t U, compareFunction cFunction)
{
	if(P > U)
		return ERR;
	else if(P == U)
		return OK;
	else
	{
		linkedListMergeSort(l,P,((P+U)/2), cFunction);
		linkedListMergeSort(l,(((P+U)/2)+1),U, cFunction);
	}
	linkedListCombinar(l,P,((P+U)/2),U,cFunction);
	return OK;
}

void linkedListCombinar(LinkedList* l, uint32_t P, uint32_t M, uint32_t U, compareFunction function)
{
	uint32_t i = P, j = M+1;

	while(i <= M && j<=U)
	{
		if(function(l,i,j) == -1)
		{
			i++;	
		}
		else
		{
			changePositionLinkedListNode(l,i,j);
			j++;
			M++;
		}
	}

	return;
}

uint8_t linkedListQuickSort(LinkedList* l, int32_t P, int32_t U, pivotFunction pFunction, compareFunction cFunction)
{
	if(P > U)
		return ERR;
	else if(P == U)
		return OK;
	else
	{
		uint32_t M = linkedListSplit(l,P,U,pFunction,cFunction);
		if(P < (M-1))
			linkedListQuickSort(l,P,M-1,pFunction,cFunction);

		if((M+1) < U)
			linkedListQuickSort(l,M+1,U,pFunction,cFunction);
	}
	return OK;
}

uint32_t linkedListSplit(LinkedList* l, int32_t P, int32_t U, pivotFunction pFunction, compareFunction cFunction)
{
	uint32_t M = pFunction(l,P,U);
	uint32_t k = getLinkedListElem(l,M);
	swapLinkedListValueNodes(l,P,M);
	M = P;
	for(uint32_t i = P+1; i <= U; i++)
	{
		if(cFunction(l,i,k) == -1)
		{
			M++;
			swapLinkedListValueNodes(l,i,M);
		}
	}
	swapLinkedListValueNodes(l,P,M);
	return M;	
}

uint32_t linkedListPivote(LinkedList* l, int32_t P, int32_t U)
{
	return P;
}

int8_t compareLinkedListIntsNumericValues(LinkedList* l, uint32_t i, uint32_t j)
{
	if(getLinkedListElem(l,i) > getLinkedListElem(l,j))
		return 1;
	else if(getLinkedListElem(l,i) < getLinkedListElem(l,j))
		return -1;
	else
		return 0;
}

int8_t compareLinkedListIntNumericValue(LinkedList* l, uint32_t i, uint32_t value)
{
	if(getLinkedListElem(l,i) > value)
		return 1;
	else if(getLinkedListElem(l,i) < value)
		return -1;
	else
		return 0;
}
