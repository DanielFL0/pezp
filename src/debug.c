#include "common.h"
#include "defs.h"
#include "chunk.h"
#include "debug.h"

void disassemble_chunk(chunk_t* chunk, const char* name) {
  printf("-- %s --\n", name);
  int offset = 0;
  while (offset < chunk->count) {
    offset = disassemble_instruction(chunk, offset);
  }
}

int disassemble_instruction(chunk_t* chunk, int offset) {
  printf("%04d ", offset);
  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_ADD:
      simple_instruction("OP_ADD");
      return offset + 1;
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}

void simple_instruction(const char* name) {
  printf("%s\n", name);
}