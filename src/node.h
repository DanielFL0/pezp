#ifndef NODE_H
#define NODE_H

typedef struct node_t {
  int             vertex;
  struct node_t*  next;
} node_t;

node_t* create_node(int vertex);
void delete_node(node_t* node);
void print_node(node_t* node);

#endif