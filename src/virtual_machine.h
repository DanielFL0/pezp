#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

typedef struct virtual_machine {
  linked_list* memory;
  uint16_t instruction_pointer;
  uint16_t accumulator;
} virtual_machine;

virtual_machine* create_virtual_machine(void);
linked_list* get_memory(virtual_machine* vm);
void increment_register(virtual_machine* vm);
void decrement_register(virtual_machine* vm);
void print_accumulator(virtual_machine* vm);

#endif