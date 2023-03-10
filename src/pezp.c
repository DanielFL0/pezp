#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linked_list.h"
#include "arena.h"

int main(void) {
  linked_list* list = create_linked_list();
  insert(list, 1);
  insert(list, 2);
  print_linked_list(list);
  delete_linked_list(list);

  return 0;
}