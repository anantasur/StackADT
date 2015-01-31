#include "stack.h"
#include <stdlib.h>

Stack createStack(){
	LinkedList *  list= calloc(sizeof(LinkedList),1);
	Stack newStack = {list,&list->tail};
	return newStack;
}