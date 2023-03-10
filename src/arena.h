#ifndef ARENA_H
#define ARENA_H

typedef struct arena {
  size_t    arena_offset;
  size_t    arena_buffer_length;
  char*     arena_buffer;
} arena;

void arena_init(arena* arena, size_t capacity);
void* arena_alloc(arena* arena, size_t size);
void arena_reset(arena* arena);
void arena_free(arena* arena);

#endif