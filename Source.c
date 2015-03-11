#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "List.h"
#include "Stack.h"
#include "Queue.h"


#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_LEN 100

#define BYTE char

void ShowBits(BYTE a)
{
	for (int i = 0; i < 8; ++i)
	{
		if (a & 0x01)
			printf("1");
		else
			printf("0");
		
		a = a >> 1;
	}
	printf("\n");
}

main(void)
{
	int elems[] = { 0, 1, 2, 3, 4, 5 };
	List * list = list_create();

	list_add_head(list, &elems[0]);
	assert(*(int*)list_get_head_data(list) == 0);
	assert(*(int*)list_get_tail_data(list) == 0);

	list_add_head(list, &elems[1]);
	assert(*(int*)list_get_head_data(list) == 1);
	assert(*(int*)list_get_tail_data(list) == 0);

	list_add_head(list, &elems[2]);
	assert(*(int*)list_get_head_data(list) == 2);
	assert(*(int*)list_get_tail_data(list) == 0);

	list_remove_head(list);
	assert(*(int*)list_get_head_data(list) == 1);
	assert(*(int*)list_get_tail_data(list) == 0);

	list_remove_head(list);
	assert(*(int*)list_get_head_data(list) == 0);
	assert(*(int*)list_get_tail_data(list) == 0);

	list_remove_head(list);
	assert(list_get_head_data(list) == NULL);
	assert(list_get_tail_data(list) == NULL);

	list_add_tail(list, &elems[0]);
	assert(*(int*)list_get_head_data(list) == 0);
	assert(*(int*)list_get_tail_data(list) == 0);

	list_add_tail(list, &elems[1]);
	assert(*(int*)list_get_head_data(list) == 0);
	assert(*(int*)list_get_tail_data(list) == 1);
	
	list_add_tail(list, &elems[2]);
	assert(*(int*)list_get_head_data(list) == 0);
	assert(*(int*)list_get_tail_data(list) == 2);

	list_destroy(list);

	char str[] = "I love programming";
	size_t len = strlen(str);
	void * data;

	Stack * st = stack_create();
	for (size_t i = 0; i < len; ++i)
	{
		stack_push(st, &str[i]);
	}

	while (data = stack_pop(st))
		putchar(*(char*)data);
	
	stack_destroy(st);

	putchar('\n');

	Que * q = que_create();
	for (size_t i = 0; i < len; ++i)
	{
		que_push(q, &str[i]);
	}

	while (data = que_pop(q))
		putchar(*(char*)data);

	que_destroy(q);

	putchar('\n');
}