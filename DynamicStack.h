#include "stdlib.h"

typedef struct tStack Stack;
typedef void * Pointer;

Stack * stack_create(size_t initial_size, size_t increment);
void stack_destroy(Stack *pstack);

void stack_push(Stack *pstack, Pointer value);
Pointer stack_pop(Stack *pstack);

Pointer stack_peek(Stack *pstack);

size_t stack_size(Stack *pstack);