#pragma once

typedef struct tQue Que;

Que * que_create();
void que_destroy(Que * q);

void que_push(Que * q, void * data);
void * que_pop(Que * q);