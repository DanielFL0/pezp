#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linked_list.h"
#include "defs.h"
#include "eval.h"

int ip = 0; /* instruction pointer */
int sp = 0; /* stack pointer */

int main(void) {
  linked_list* memory = create_linked_list();
  for (int i = 0; i < 10; i++)
    insert_node(memory, i);
  print_linked_list(memory);
  node_t* test = get_node(memory, 2);
  set_node(test, 44);
  print_linked_list(memory);
  delete_node(test);
  print_linked_list(memory);
  delete_linked_list(memory);
  return 0;
}