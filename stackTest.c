#include "expr_assert.h"
#include "stack.h"
#include <stdio.h>

void test_creatStack_initalize_stack_top_with_null_and_list_empty(){
	Stack newStack = createStack();
	assert(newStack.list!=NULL);
	assert(*(newStack.top)==NULL);
}