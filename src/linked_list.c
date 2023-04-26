#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "chunk.h"
#include "node.h"
#include "linked_list.h"

linked_list* create_linked_list(void) {
  linked_list* list = malloc(sizeof(linked_list));
  list->head = NULL;
  list->size = 0;
  return list;
}

node_t* get_node(linked_list* list, int index) {
  node_t* current = list->head;
  int counter = 0;
  while (next_node(current) != NULL && counter <= index) {
    current = next_node(current);
    counter++;
  }
  return current;
}

void insert_node(linked_list* list, chunk_t* chunk) {
  node_t* node = create_node(chunk);
  if (list->head == NULL) {
    list->head = node;
  } else {
    node_t* current = list->head;
    while (next_node(current) != NULL) {
      current = next_node(current);
    }
    current->next = node;
    node->prev = current;
  }
  list->size++;
}

void delete_linked_list(linked_list* list) {
  if (list->head == NULL) {
    return;
  } else {
    node_t* current = list->head;
    while (next_node(current) != NULL) {
      node_t* temp = current;
      current = next_node(current);
      delete_node(temp);    
    }
    free(list);
  }
}

void print_linked_list(linked_list* list) {
  node_t* current = list->head;
  while (current != NULL) {
    print_node(current);
    current = next_node(current);
  }
  printf("\n");
}