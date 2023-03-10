#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node_t node_t;
typedef struct linked_list linked_list;
linked_list* create_linked_list();
void insert(linked_list* list, int data);
void print_linked_list(linked_list* list);

#endif