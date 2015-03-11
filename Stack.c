#include "Stack.h"
#include "List.h"
#include <stdlib.h>

struct tStack
{
	List * buffer;
};

Stack * stack_create()
{
	Stack * st = (Stack*)malloc(sizeof(Stack));
	st->buffer = list_create();
	return st;
}

void stack_destroy(Stack * st)
{
	list_destroy(st->buffer);
	free(st);
}

void stack_push(Stack * st, void * data)
{
	list_add_head(st->buffer, data);
}

void * stack_pop(Stack * st)
{
	void * data = list_get_head_data(st->buffer);
	list_remove_head(st->buffer);
	return data;
}