#ifndef NODE_H
#define NODE_H

typedef struct node_t {
  struct chunk_t* chunk;
  struct node_t*  next;
  struct node_t*  prev;
} node_t;

node_t* create_node(chunk_t* chunk);
node_t* next_node(node_t* node);
node_t* prev_node(node_t* node);
void set_node(node_t* node, chunk_t* chunk);
void delete_node(node_t* node); /* TODO: FIX THIS */
void print_node(node_t* node);

#endif