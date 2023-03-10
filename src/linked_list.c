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

void insert(linked_list* list, int data) {
  node_t* node = create_node(data);
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

void print_linked_list(linked_list* list) {
  node_t* current = list->head;
  while (current != NULL) {
    printf("%d ", current->vertex);
    current = current->next;
  }
  printf("\n");
}