#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "chunk.h"
#include "node.h"
#include "linked_list.h"
#include "defs.h"
#include "file_loader.h"
#include "virtual_machine.h"

/*
 * PROCEDURE:
 * Load one instruction from memory at the address of the PC register.
 * Increment the PC register.
 * Look at the opcode to determine which type of instruction it should perform.
 * Go back to step 1.
 */

int main(void) {
  linked_list* memory = create_linked_list();
  for (int i = 0; i < 10; i++) {
    chunk_t* chunk = create_chunk(i, i);
    insert_node(memory, chunk);
  }
  print_linked_list(memory);
  node_t* test = get_node(memory, 2);
  print_node(test);
  delete_linked_list(memory);
  return 0;
}