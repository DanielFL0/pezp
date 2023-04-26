#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "chunk.h"
#include "node.h"
#include "linked_list.h"
#include "virtual_machine.h"

virtual_machine* create_virtual_machine(void) {
  virtual_machine* vm = malloc(sizeof(virtual_machine));
  vm->memory = create_linked_list();
  vm->instruction_pointer = 0;
  vm->accumulator = 0;
  return vm;
}

linked_list* get_memory(virtual_machine* vm) {
    return vm->memory;
}

void increment_register(virtual_machine* vm) {
  vm->accumulator++;
}

void decrement_register(virtual_machine* vm) {
  vm->accumulator--;
}

void print_accumulator(virtual_machine* vm) {
    printf("%d\n", vm->accumulator);
}