#pragma once

typedef struct tStack Stack;

Stack * stack_create();
void stack_destroy(Stack * st);

void stack_push(Stack * st, void * data);
void * stack_pop(Stack * st);