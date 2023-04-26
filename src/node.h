#ifndef NODE_H
#define NODE_H

typedef struct node_t {
  int             vertex;
  struct node_t*  next;
  struct node_t*  prev;
} node_t;

node_t* create_node(int vertex);
node_t* next_node(node_t* node);
node_t* prev_node(node_t* node);
void set_node(node_t* node, int vertex);
void delete_node(node_t* node); /* TODO: FIX THIS */
void print_node(node_t* node);

#endif