#include "LinkedList.h"
#include "SortMethods.h"
#include <stdio.h>

int main(int argc, char* arv[])
{

	LinkedList* l = createLinkedList();

	int i = 30;
	for(; i < 50; i++)
		appendElem(l, &i);

	appendElemIndex(l, &i, 5);

	printf("Total de elementos: %d\n",getNElems(l));	
	for(i = 0; i < 21; i++)
		printf("Value obtained from list is: %d\n",getLinkedListElem(l,i));

	printf("///////////////////////////\n");

	for(i = 0; i < 5; i++)
		printf("Value obtained from popElem is: %d\n", popElem(l));

	printf("///////////////////////////\n");
	
	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from list is: %d\n",getLinkedListElem(l,i));

	printf("///////////////////////////\n");
	
	printf("Value obtained from popElemIndex(l,0) is: %d\n", popElemIndex(l,0));
	printf("///////////////////////////\n");
	/*//printf("Value pop: %d\n",*p);
	//printf("Value pop: %d\n",*(uint32_t *)popElem(l));
	//printf("Value pop: %d\n",*(uint32_t *)popElem(l));

	//for(i = 0; i < 10; i++)
	//	printf("Value obtained from pop list is: %d\n",*(uint32_t *)popElem(l));
	
	for(i = 0; i < 18; i++)
		printf("Value obtained from list is: %d\n",*(uint32_t *)getLinkedListElem(l,i));*/

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from list is: %d\n",getLinkedListElem(l,i));	

	printf("///////////////////////////\n");

	swapLinkedListValueNodes(l, 0, 10);

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from list is: %d\n",getLinkedListElem(l,i));	

	printf("///////////////////////////\n");

	i=100;
	appendElem(l, &i);	

	i = 62;
	appendElemIndex(l, &i,12);

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from list is: %d\n",getLinkedListElem(l,i));	

	printf("///////////////////////////\n");	

	LinkedList* l2 = duplicateLinkedList(l);
	LinkedList* l3 = duplicateLinkedList(l);

	for(i = 0; i < getNElems(l2); i++)
		printf("Value obtained from list2 is: %d\n",getLinkedListElem(l2,i));	

	printf("///////////////////////////\n");

	for(i = 0; i < getNElems(l2); i++)
		printf("Value obtained from list3 is: %d\n",getLinkedListElem(l3,i));	

	printf("///////////////////////////\n");	

	uint32_t* array = getInt32ArrayFromList(l);		

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from array is: %u\n",*(array+i));	

	printf("///////////////////////////\n");	
	
	free(array);

	linkedListBubbleSort(l);

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from list order by bublesort is: %d\n",getLinkedListElem(l,i));		

	printf("///////////////////////////\n");

	linkedListMergeSort(l2,0,getNElems(l2)-1);

	for(i = 0; i < getNElems(l2); i++)
		printf("Value obtained from list2 order by mergesort is: %d\n",getLinkedListElem(l2,i));		

	printf("///////////////////////////\n");	

	linkedListQuickSort(l3,0,getNElems(l3)-1);

	for(i = 0; i < getNElems(l3); i++)
		printf("Value obtained from list3 order by QuickSort is: %d\n",getLinkedListElem(l3,i));		

	printf("///////////////////////////\n");		

	deleteLinkedList(l);
	deleteLinkedList(l2);
	deleteLinkedList(l3);
}
