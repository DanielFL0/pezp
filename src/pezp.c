#include "common.h"
#include "defs.h"
#include "chunk.h"
#include "debug.h"

/*
 * PROCEDURE:
 * Load one instruction from memory at the address of the PC register.
 * Increment the PC register.
 * Look at the opcode to determine which type of instruction it should perform.
 * Go back to step 1.
 */

int main(void) {
  chunk_t chunk;
  init_chunk(&chunk);
  write_chunk(&chunk, OP_ADD);
  disassemble_chunk(&chunk, "test chunk");
  free_chunk(&chunk);
  return 0;
}