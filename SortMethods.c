#include "LinkedList.h"

void linkedListBubbleSort(LinkedList* l)
{
	uint8_t flag = TRUE_U8;
	uint32_t i = getNElems(l);
	
	while(i > 0 && flag == TRUE_U8)
	{
		flag = FALSE_U8;
		for(uint32_t j = DFT_CERO_U32; j < i -1; j++)
		{
			if(getLinkedListElem(l,j) > getLinkedListElem(l,j+1))
			{
				swapLinkedListNodes(j,j+1);
				flag = TRUE_U8;
			}
		}
		i--;
	}
	return;
}

void linkedListMergeSort(LinkedList* l)
{
	if(P > U)
		return ERR;
	else if(P == U)
		return OK;
	else
	{
		linkedListMergeSort(l,P,(P+U)/2);
		linkedListMergeSort(l,((P+U)/2)+1,U);
	}
	return linkedListCombinar(l,P,M,U);
}

void linkedListCobinar(LinkedList* l, uint32_t P, uint32_t M, uint32_t U)
{
	uint32_t i = P, j = M+1;

	while(i <= M && j<=U)
	{
		if(getLinkedListElem(l,j) > getLinkedListElem(l,j+1))
		{
			swapLinkedListNodes(i,j);
			i++;
		}
		else
		{
			j++;
		}
	}
	return;
}

void linkedListQuickSort(LinkedList* l, uint32_t P, uint32_t U)
{
	if(P > U)
		return ERR;
	else if(P == U)
		return OK;
	else
	{
		uint32_t M = linkedListSplit(l,P,U);
		if(P < (M-1))
			linkedListQuickSort(l,P,M-1);

		if((M+1) < U)
			linkedListQuickSort(l,M+1,U);
	}
	return OK;
}

uint32_t linkedListSplit(LinkedList* l, uint32_t P, uint32_t U)
{
	uint32_t M = linkedListPivote(l,P,U);
	uint32_t k = getLinkedListElem(l,M);
	swapLinkedListNodes(P,M);
	M = P;
	for(uint32_t i = P+1; i < U; i++)
	{
		if(getLinkedListElem(l,i) < k)
		{
			M++;
			swapLinkedListNodes(i,M);
		}
	}
	swapLinkedListNodes(P,M);
	return M;	
}

void linkedListHeapSort(LinkedList* l)
{
	linkedListCreateHeap(l);
	linkedListSortHeap(l);
}

void linkedListCreateHeap(LinkedList* l)
{
	if(NELEMS(l) < 2)
		return;

	for(uint32_t i = (NELEMS(l)-2)/2; i > 0; i--)
	{
		linkedListHeapify(l,NELEMS(l),i);
	}
}
