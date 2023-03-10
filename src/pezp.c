#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(void) {
  linked_list* list = create_linked_list();
  insert(list, 1);
  insert(list, 2);
  insert(list, 3);
  print_linked_list(list);
  return 0;
}