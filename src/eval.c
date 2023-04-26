#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "defs.h"
#include "eval.h"

void eval(node_t* node) {
  int opcode = node->vertex;
  switch (opcode) {
    case OP_BR:
      break;
    case OP_ADD:
      break;
    case OP_LD:
      break;
    case OP_ST:
      break;
    case OP_JSR:
      break;
    case OP_AND:
      break;
    case OP_LDR:
      break;
    case OP_STR:
      break;
    case OP_RTI:
      break;
    case OP_NOT:
      break;
    case OP_LDI:
      break;
    case OP_STI:
      break;
    case OP_JMP:
      break;
    case OP_RES:
      break;
    case OP_LEA:
      break;
    case OP_TRAP:
      break;
    default:
    puts("Incorrect opcode");
  }
}