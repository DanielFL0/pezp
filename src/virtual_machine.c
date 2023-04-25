#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linked_list.h"
#include "defs.h"
#include "virtual_machine.h"

virtual_machine* create_virtual_machine(void) {
  virtual_machine* vm = malloc(sizeof(virtual_machine));
  vm->program = create_linked_list();
  vm->tape = create_linked_list();
  return vm;
}

void run(virtual_machine* virtual_machine) {
  node_t* current = virtual_machine->program->head;
  while (current != NULL) {
    print_node(current);
    current = current->next;
  }
  printf("\n");
}