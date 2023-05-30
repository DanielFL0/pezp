#include "common.h"
#include "error.h"
#include "chunk.h"

error_t init_chunk(chunk_t* chunk, uint32_t size) {
  chunk->buffer = malloc(size);
  if (chunk->buffer == NULL) {
    return PEZP_MEMORY_MALLOC_ERROR;
  }
  chunk->buffer_size = size;
  chunk->program_counter = 0;
  return PEZP_SUCCESS;
}

error_t write_chunk(chunk_t* chunk, uint8_t byte) {
  if (chunk->program_counter >= chunk->buffer_size) {
    chunk->buffer_size = chunk->buffer_size * 2;
    chunk->buffer = realloc(chunk->buffer, chunk->buffer_size);
    if (chunk->buffer == NULL) {
      return PEZP_MEMORY_REALLOC_ERROR;
    }
  }
  chunk->buffer[chunk->program_counter] = byte;
  chunk->program_counter = chunk->program_counter + 1;
  return PEZP_SUCCESS;
}

error_t free_chunk(chunk_t* chunk) {
  free(chunk->buffer);
  return PEZP_SUCCESS;
}