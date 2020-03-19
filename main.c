#include "LinkedList.h"
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

	swapLinkedListNodes(l, 0, 10);

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

	for(i = 0; i < getNElems(l2); i++)
		printf("Value obtained from list2 is: %d\n",getLinkedListElem(l2,i));	

	printf("///////////////////////////\n");

	uint32_t* array = getInt32ArrayFromList(l);		

	for(i = 0; i < getNElems(l); i++)
		printf("Value obtained from array is: %u\n",*(array+i));	

	printf("///////////////////////////\n");	
	
	free(array);
	deleteLinkedList(l);
	deleteLinkedList(l2);
}
