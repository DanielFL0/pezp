#include <stdio.h>
#include <stdlib.h>
#include "chunk.h"

chunk_t* create_chunk(int count, int capacity) {
  chunk_t* chunk = malloc(sizeof(chunk_t));
  chunk->count = count;
  chunk->capacity = capacity;
  return chunk;
}

void print_chunk(chunk_t* chunk) {
  printf("COUNT: %d CAPACITY: %d\n", chunk->count, chunk->capacity);
}

void delete_chunk(chunk_t* chunk) {
  free(chunk);
}