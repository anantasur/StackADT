#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	return list;
}

Node * create_node(void *data){
	Node * newNode = NULL;

	newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int add_to_list(LinkedList* list,Node* node){
	if(list->head == NULL) list->head=node;
	else list->tail->next = node;
	list->tail = node;
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return list.head->data;	
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}

void traverse(LinkedList list, void (*func)(void* data)) {
	Node* walker = list.head;
	while(walker!=NULL){
		func(walker->data);
		walker = walker->next;
	}
}

void * getElementAt(LinkedList list, int index){
	int i;
	Node* walker =list.head;
	if(index>=list.count) return NULL;
	for(i=0;i<index;i++) walker=walker->next;
	return walker->data;
}

int indexOf(LinkedList list, void* data){
	int index=0;
	Node* walker = list.head;  
	while(walker!=NULL){
		if(walker->data == data) return index;
		index++;
		walker = walker->next;
	}
	return -1;
}

void * deleteElementAt(LinkedList *list, int index){
	Node *walker;
	int count = 0;
	for(walker = list->head;walker!=NULL;walker = walker->next) {
		if(index==0){
			list->head = list->head->next;
			walker->next=NULL;
			return walker->data;
		}
		if(index==list->count-1){
			list->tail = list->tail->next;
			walker->next=NULL;
			return walker->data;
		}
		if(count == index-1) {
			walker->next = walker->next->next;
			break;
		}
		count++;
	}	
	return walker->next->data;
}

int asArray(LinkedList list, void **destination){
	int count;
	for (count=0;count<list.count;count++){
		destination[count]=getElementAt(list,count);
	}
	return count;
}

LinkedList *filter(LinkedList list, int (*func)(void *)) {
	Node *walker,*newNode;
	LinkedList *newList = malloc(sizeof(LinkedList));
	walker = list.head;
	while(walker!=NULL){
		if(func(walker->data)) {
			newNode = create_node(walker->data);
			add_to_list(newList,newNode);
		}
		walker = walker->next; 
	}
	return newList; 
}