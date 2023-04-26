#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list {
  int       size;
  node_t*   head;
} linked_list;

linked_list* create_linked_list(void);
node_t* get_node(linked_list* list, int index);
void insert_node(linked_list* list, int vertex);
void delete_linked_list(linked_list* list);
void print_linked_list(linked_list* list);

#endif