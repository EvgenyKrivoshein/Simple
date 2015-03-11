#include "DynamicStack.h"
#include <assert.h>

#define INIT_SIZE 50

void test_dynamic_stack()
{
	char el0 = 'c';
	int el1 = 12;
	float el2 = 10.2f;
	char * el3 = "string";

	Pointer elems[] = { &el0, &el1, &el2, &el3 };

	Stack * st = stack_create(1, 1);
	assert(st != NULL);

	assert(stack_size(st) == 0);
	assert(stack_peek(st) == NULL);

	stack_push(st, elems[0]);
	assert(stack_size(st) == 1);
	assert(stack_peek(st) == elems[0]);

	stack_push(st, elems[1]);
	assert(stack_size(st) == 2);
	assert(stack_peek(st) == elems[1]);

	stack_push(st, elems[2]);
	assert(stack_size(st) == 3);
	assert(stack_peek(st) == elems[2]);

	stack_push(st, elems[3]);
	assert(stack_size(st) == 4);
	assert(stack_peek(st) == elems[3]);

	stack_pop(st);
	assert(stack_size(st) == 3);
	assert(stack_peek(st) == elems[2]);

	stack_pop(st);
	assert(stack_size(st) == 2);
	assert(stack_peek(st) == elems[1]);

	stack_pop(st);
	assert(stack_size(st) == 1);
	assert(stack_peek(st) == elems[0]);

	stack_pop(st);
	assert(stack_size(st) == 0);
	assert(stack_peek(st) == NULL);

	assert(stack_pop(st) == NULL);
	stack_destroy(st);
}

struct tStack
{
	size_t initial_size;
	size_t increment;
	Pointer * buffer;
	size_t bufferSize;
	size_t size;
};


/* Создать пустой стек */
Stack * stack_create(size_t initial_size, size_t increment)
{
	if (initial_size == 0 || increment == 0)
		return NULL;

	Stack * s =  (Stack *) malloc(sizeof(Stack));
	assert(s != NULL);

	s->initial_size = initial_size;
	s->increment = increment;
	s->bufferSize = 0;
	s->size = 0;
	s->buffer = NULL;
	return s;
}

/* Уничтожить стек, освободив выделенную память */
void stack_destroy(Stack *pstack)
{
	assert(pstack != NULL);

	free(pstack->buffer);
	free(pstack);
	pstack = NULL;
}

/* Поместить значение value на вершину стека */
void stack_push(Stack *pstack, Pointer value)
{
	assert(pstack != NULL);
	assert(pstack->size <= pstack->bufferSize);

	if (pstack->bufferSize == pstack->size)
	{
		if (pstack->bufferSize == 0)
		{
			pstack->bufferSize = pstack->initial_size;
			pstack->buffer = (Pointer *) malloc(pstack->initial_size * sizeof(Pointer));
		}
		pstack->bufferSize += pstack->increment;
		pstack->buffer = (Pointer *) realloc(pstack->buffer, pstack->bufferSize * sizeof(Pointer));
	}

	pstack->buffer[pstack->size++] = value;
}

/* Возвращает количество элементов в стеке (0, если стек пуст) */
size_t stack_size(Stack *pstack)
{
	assert(pstack != NULL);
	return pstack->size;
}

/* Снять значение с вершины стека. Если стек пуст, возвращает 0 */
Pointer stack_pop(Stack *pstack)
{
	assert(pstack != NULL);
	if (!pstack->size)
	{
		return NULL;
	}
	
	return pstack->buffer[pstack->size-- - 1];
}

/*
* Возвращает значение с вершины стека, не удаляя его из стека.
* Если стек пуст, возвращает 0
*/
Pointer stack_peek(Stack *pstack)
{
	assert(pstack != NULL);
	if (!pstack->size)
	{
		return NULL;
	}

	return pstack->buffer[pstack->size - 1];
}