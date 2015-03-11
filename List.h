#pragma once

typedef struct tList List;

List * list_create();
void list_destroy(List * pList);

void list_add_head(List * pList, void * data);
void list_add_tail(List * pList, void * data);

void list_remove_head(List * pList);

void * list_get_head_data(List * pList);
void * list_get_tail_data(List * pList);