#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

typedef struct virtual_machine {
  linked_list*  program;
  linked_list*  tape;
} virtual_machine;

virtual_machine* create_virtual_machine(void);
void run(virtual_machine* virtual_machine);
    
#endif