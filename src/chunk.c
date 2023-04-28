#include "common.h"
#include "chunk.h"

void init_chunk(chunk_t* chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void write_chunk(chunk_t* chunk, uint8_t byte) {
  if (chunk->capacity < chunk->count + 1) {
    chunk->capacity = chunk->capacity * 2;
    chunk->code = realloc(chunk->code, chunk->capacity * sizeof(uint8_t));
  }
  chunk->code[chunk->count] = byte;
  chunk->count++;
}

void free_chunk(chunk_t* chunk) {
  free(chunk->code);
  init_chunk(chunk);
}