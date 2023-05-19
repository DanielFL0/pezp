#include "common.h"
#include "chunk.h"

/**
 * PROCEDURE:
 * Load one instruction from memory at the address of the PC register.
 * Increment the PC register.
 * Look at the opcode to determine which type of instruction it should perform.
 * Go back to step 1.
 */

int main(void) {
  chunk_t buffer;
  srand(time(NULL));
  init_chunk(&buffer);
  for (int i = 0; i < MEMORY_MAX; i++)
    write_chunk(&buffer, rand() % 20);
  disassemble_chunk(&buffer, "TEST");
  // free_chunk(&buffer);
  return 0;
}