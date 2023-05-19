#include "common.h"
#include "chunk.h"

void init_chunk(chunk_t* chunk) {
  chunk->buffer = malloc(MEMORY_MAX); /* allocate 256 bytes */
  chunk->buffer_offset = chunk->buffer; /* point beginning of buffer */
  chunk->buffer_length = chunk->buffer + MEMORY_MAX - 1; /* point end of buffer */
}

void write_chunk(chunk_t* chunk, uint8_t byte) {
  if (chunk->buffer_offset <= chunk->buffer_length) {
    *chunk->buffer_offset = byte; /* assign a value to the pointer */
    chunk->buffer_offset = chunk->buffer_offset + 1; /* point to next element in buffer */
  }
}

void disassemble_chunk(chunk_t* chunk, char* name) {
  printf("-- %s --\n", name);
  int line_number = 0;
  uint8_t* start = chunk->buffer;
  while (start <= chunk->buffer_length) {
    printf("%04d %p\t0o%03o\t0d%03d\t0x%02x\n", line_number, start, *start, *start, *start);
    line_number = line_number + 1;
    start = start + 1;
  }
}

void free_chunk(chunk_t* chunk) {
  free(chunk->buffer); /* free allocated buffer */
}
