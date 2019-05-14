#ifndef LIST_H
#define LIST_H
#include "darknet.h"

list *make_list();

void *list_pop(list *l);
void list_insert(list *l, void *val);

// 2019/5/8
void list_bsort(list *l);

void free_node(node *n);
void free_list(list *l);
void free_list_contents(list *l);

void **list_to_array(list *l);


#endif
