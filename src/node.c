#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node_t* create_node(int vertex) {
  node_t* node = malloc(sizeof(node_t));
  node->vertex = vertex;
  node->next = NULL;
  return node;
}

node_t* next_node(node_t* node) {
  return node->next;
}

void delete_node(node_t* node) {
  free(node);
}

void print_node(node_t* node) {
  printf("%d\n", node->vertex);
}
