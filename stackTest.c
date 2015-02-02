#include "expr_assert.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test_creatStack_initalize_stack_top_with_null_and_list_empty(){
	Stack newStack = createStack();
	assert(newStack.list!=NULL);
	assert(*(newStack.top)==NULL);
}

void test_push_adds_the_data_into_the_stack(){
	int data=1,count;
	Stack s = createStack();
	count = push(s,&data);
	assertEqual(count, 1);
	assert((*(s.top))->data==&data);
}

void test_push_Pushes_an_integer_element_to_a_stack() {
	Stack stack = createStack();
	int data = 24,data1 = 23,res;
	res = push(stack,&data);
	assertEqual(res,1);
	assertEqual(*((int *)(*(stack.top))->data),24);
	res = push(stack,&data1);
	assertEqual(res,2);
	assertEqual(*((int *)(*(stack.top))->data),23);
	stack.top = NULL;
}

void test_pop_retuns_topmost_element_from_stack(){
	int data1=1,data2 =4,count;
	int * poped;
	Stack s = createStack();
	count = push(s,&data1);
	count = push(s,&data2);
	poped =(int *)pop(s);
	assertEqual(*poped, data2);
	assert((*s.top)->data==&data1);
}

void test_creatStack_cretes_a_stack_and_sets_its_top_to_NULL(){
	Stack stack = createStack();
	assertEqual(*(int*)stack.top,0);
}

void test_createStack_creates_an_empty_stack (){
	Stack stack;
	stack = createStack();
	assertEqual(stack.list->count, 0);
	assertEqual(*(int*)stack.top , 0);
	free(stack.list);
}

void test_to_push_int_data_in_a_stack(){
	Stack s1 = createStack();
	int data = 2;
	assertEqual(push(s1,&data),1);
	assertEqual(*(int*)s1.list->tail->data,2);
}

void test_to_push_float_data_in_a_stack(){
	Stack s1 = createStack();
	float data = 2.3;
	assertEqual(push(s1,&data),1);
	assertEqual(*(float*)s1.list->tail->data,(float)2.3);
}

void test_to_push_char_data_in_a_stack(){
	Stack s1 = createStack();
	char data = 'a';
	assertEqual(push(s1,&data),1);
	assertEqual(*(char*)s1.list->tail->data,'a');
}

void test_to_push_string_data_in_a_stack(){
	Stack s1 = createStack();
	char* data= "string";
	assertEqual(push(s1,&data),1);
	assertEqual(strcmp(*((char**)s1.list->tail->data),"string"), 0);
}