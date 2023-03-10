#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list {
  int       size;
  node_t*   head;
} linked_list;

linked_list* create_linked_list(void);
void delete_linked_list(linked_list* list);
void insert(linked_list* list, int data);
void print_linked_list(linked_list* list);

#endif