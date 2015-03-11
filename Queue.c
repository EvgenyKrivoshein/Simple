#include "Queue.h"
#include "List.h"

struct tQue
{
	List * buffer;
};

Que * que_create()
{
	Que * q = (Que*)malloc(sizeof(Que));
	q->buffer = list_create();
	return q;
}

void que_destroy(Que * q)
{
	list_destroy(q->buffer);
	free(q);
}

void que_push(Que * q, void * data)
{
	list_add_tail(q->buffer, data);
}

void * que_pop(Que * q)
{
	void * data = list_get_head_data(q->buffer);
	list_remove_head(q->buffer);
	return data;
}