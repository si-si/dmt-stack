#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define T Stack_T

struct T{
	int count;
	struct elem{
		void *x;
		struct elem *link;
	}*head;
};

T Stack_new(void){
	T stk;
	
	stk = (T)malloc(sizeof(T));
	if (!stk){
		return NULL;
	}
	stk->count = 0;
	stk->head = NULL;
	return stk;
}

int Stack_empty(T stk){
	if (!stk)
		return -1;
	return stk->count == 0;
}

int Stack_push(T stk, void *x){
	struct elem *e = NULL;
	e = (struct elem *)malloc(sizeof(struct elem));
	if (!e)
		return -1;
	e->x = x;
	e->link = stk->head;
	stk->head = e;
	stk->count++;
	return 1;
}

void *Stack_pop(T stk){
	struct elem *e = NULL;

	if (Stack_empty(stk) != 0)
		return NULL;
	e = stk->head;
	stk->head = stk->head->link;
	stk->count--;
	void *p = e->x;
	free(e);
	return p;
}


