#include "common.h"
#include "error.h"
#include "chunk.h"

int main(void) {
  chunk_t chunk;
  init_chunk(&chunk, 8);
  write_chunk(&chunk, 0);
  free_chunk(&chunk);
  return 0;
}