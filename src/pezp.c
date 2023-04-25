#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "linked_list.h"
#include "defs.h"
#include "virtual_machine.h"

int main(void) {
  virtual_machine* vm = create_virtual_machine();
  run(vm);
  return 0;
}