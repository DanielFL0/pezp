#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int data;
  struct node_t* next;
} node_t;

typedef struct linked_list {
  int size;
  node_t* head;
} linked_list;

linked_list* create_linked_list() {
  linked_list* list = (linked_list*)malloc(sizeof(linked_list));
  list->head = NULL;
  list->size = 0;
  return list;
}

void insert(linked_list* list, int data) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  if (list->head == NULL) {
    list->head = node;
  }
  else {
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
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}