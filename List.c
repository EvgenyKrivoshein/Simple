#include "List.h"
#include <stdlib.h>

typedef struct tListNode ListNode;

struct tList
{
	ListNode * head;
	ListNode * tail;
};

struct tListNode
{
	void * data;
	ListNode * next;
};

List * list_create()
{
	List * list = (List *)malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void list_destroy(List * pList)
{
	while (pList->head)
		list_remove_head(pList);

	free(pList);
}

void list_add_head(List * pList, void * data)
{
	ListNode * node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->next = pList->head;
	
	pList->head = node;

	if (!pList->tail)
		pList->tail = node;
}

void list_add_tail(List * pList, void * data)
{
	ListNode * node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->next = NULL;

	if (pList->tail)
		pList->tail->next = node;
	else
		pList->head = node;

	pList->tail = node;
}

void list_remove_head(List * pList)
{
	if (!pList->head)
		return;

	ListNode * oldHead = pList->head;

	pList->head = oldHead->next;

	if (!pList->head)
		pList->tail = NULL;

	free(oldHead);
}

void * list_get_head_data(List * pList)
{
	if (!pList->head)
		return NULL;

	return pList->head->data;
}

void * list_get_tail_data(List * pList)
{
	if (!pList->tail)
		return NULL;

	return pList->tail->data;
}