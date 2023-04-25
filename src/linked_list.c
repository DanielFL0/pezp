#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linked_list.h"

linked_list* create_linked_list(void) {
  linked_list* list = malloc(sizeof(linked_list));
  list->head = NULL;
  list->size = 0;
  return list;
}

void insert(linked_list* list, int vertex) {
  node_t* node = create_node(vertex);
  if (list->head == NULL) {
    list->head = node;
    
  } else {
    node_t* current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }
  list->size++;
}

void delete_linked_list(linked_list* list) {
  if (list->head == NULL) {
    return;
  } else {
    node_t* current = list->head;
    while (current->next != NULL) {
      node_t* temp = current;
      current = current->next;
      delete_node(temp);    
    }
    free(list);
  }
}

void print_linked_list(linked_list* list) {
  node_t* current = list->head;
  while (current != NULL) {
    print_node(current);
    current = current->next;
  }
  printf("\n");
}