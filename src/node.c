#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node_t* create_node(int vertex) {
  node_t* node = malloc(sizeof(node));
  node->vertex = vertex;
  node->next = NULL;
  return node;
}