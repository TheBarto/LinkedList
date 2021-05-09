#include "LinkedList.h"
#include "SortMethods.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

	LinkedList* l = createLinkedList();

	int i = 30;
	int* value;
	for(; i < 50; i++)
		appendElemDeepCopy(l, &i, deepCopyInt32Value);

	appendElemIndexDeepCopy(l, &i, 5, deepCopyInt32Value);

	printf("Total de elementos: %d\n",getNElems(l));	
	for(i = 0; i < getNElems(l); i++)
		printf("1. Value obtained from list is: %d\n",*(int *)getLinkedListElem(l,i));

	printf("///////////////////////////\n");

	for(i = 0; i < 5; i++)
	{
		value = (int *)popElem(l);
		printf("2. Value obtained from popElem is: %d\n", *value);
		free(value);
	}

	printf("///////////////////////////\n");
	
	for(i = 0; i < getNElems(l); i++)
		printf("3. Value obtained from list is: %d\n",*(int *)getLinkedListElem(l,i));

	printf("///////////////////////////\n");
	
	value = (int *)popElemIndex(l,0);
	printf("4. Value obtained from popElemIndex(l,0) is: %d\n", *value);
	free(value);
	printf("///////////////////////////\n");
	/*//printf("Value pop: %d\n",*p);
	//printf("Value pop: %d\n",*(uint32_t *)popElem(l));
	//printf("Value pop: %d\n",*(uint32_t *)popElem(l));

	//for(i = 0; i < 10; i++)
	//	printf("Value obtained from pop list is: %d\n",*(uint32_t *)popElem(l));
	
	for(i = 0; i < 18; i++)
		printf("Value obtained from list is: %d\n",*(uint32_t *)getLinkedListElem(l,i));*/

	for(i = 0; i < getNElems(l); i++)
		printf("5. Value obtained from list is: %d\n",*(int *)getLinkedListElem(l,i));	

	printf("///////////////////////////\n");

	swapLinkedListValueNodes(l, 0, 10);

	for(i = 0; i < getNElems(l); i++)
		printf("6. Value obtained from list is: %d\n",*(int *)getLinkedListElem(l,i));	

	printf("///////////////////////////\n");

	i=100;
	appendElemDeepCopy(l, &i, deepCopyInt32Value);	

	i = 62;
	appendElemIndexDeepCopy(l, &i, 12, deepCopyInt32Value);

	for(i = 0; i < getNElems(l); i++)
		printf("7. Value obtained from list is: %d\n",*(int *)getLinkedListElem(l,i));	

	printf("///////////////////////////\n");	

	LinkedList* l2 = duplicateDeepCopyLinkedList(l, deepCopyInt32Value);
	LinkedList* l3 = duplicateDeepCopyLinkedList(l, deepCopyInt32Value);

	for(i = 0; i < getNElems(l2); i++)
		printf("8. Value obtained from list2 is: %d\n",*(int *)getLinkedListElem(l2,i));	

	printf("///////////////////////////\n");

	for(i = 0; i < getNElems(l3); i++)
		printf("9. Value obtained from list3 is: %d\n",*(int *)getLinkedListElem(l3,i));	

	printf("///////////////////////////\n");	

	/*
	uint32_t* array = getInt32ArrayFromList(l);		

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from array is: %u\n",*(array+i));	

	free(array);
	printf("///////////////////////////\n");
	*/

	linkedListBubbleSort(l,compareLinkedListIntsNumericValues);

	for(i = 0; i < getNElems(l); i++)
		printf("10. Value obtained from list order by bublesort is: %d\n",*(int *)getLinkedListElem(l,i));		

	printf("///////////////////////////\n");

	linkedListMergeSort(l2,0,getNElems(l2)-1,compareLinkedListIntsNumericValues);

	for(i = 0; i < getNElems(l2); i++)
		printf("11. Value obtained from list2 order by mergesort is: %d\n",*(int *)getLinkedListElem(l2,i));		

	printf("///////////////////////////\n");	

	linkedListQuickSort(l3,0,getNElems(l3)-1, linkedListPivote, compareLinkedListIntNumericValue);

	for(i = 0; i < getNElems(l3); i++)
		printf("12. Value obtained from list3 order by QuickSort is: %d\n",*(int *)getLinkedListElem(l3,i));		

	printf("///////////////////////////\n");		

	deleteDeepCopyLinkedList(l);
	deleteDeepCopyLinkedList(l2);
	deleteDeepCopyLinkedList(l3);
}
