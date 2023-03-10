#include <stdio.h>
#include <stdlib.h>
#include "arena.h"

void arena_init(arena* arena, size_t arena_buffer_length) {
  arena->arena_offset = 0;
  arena->arena_buffer_length = arena_buffer_length;
  arena->arena_buffer = malloc(arena_buffer_length);
}

void* arena_alloc(arena* arena, size_t size) {
  if (arena->arena_offset + size > arena->arena_buffer_length) {
    return NULL;
  }
  char* ptr = arena->arena_buffer + arena->arena_offset;
  arena->arena_offset += size;
  return ptr;
}

void arena_reset(arena* arena) {
  arena->arena_offset = 0;
}

void arena_free(arena* arena) {
  free(arena->arena_buffer);
}