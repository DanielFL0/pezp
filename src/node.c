#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "chunk.h"
#include "node.h"

node_t* create_node(chunk_t* chunk) {
  node_t* node = malloc(sizeof(node_t));
  node->chunk = chunk;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

node_t* next_node(node_t* node) {
  return node->next;
}

node_t* prev_node(node_t* node) {
  return node->prev;
}

void set_node(node_t* node, chunk_t* chunk) {
  node->chunk = chunk;
}

void delete_node(node_t* node) {
  free(node);
}

void print_node(node_t* node) {
  print_chunk(node->chunk);
}
