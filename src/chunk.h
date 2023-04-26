#ifndef CHUNK_H
#define CHUNK_H

typedef struct chunk_t {
  int count;
  int capacity;
} chunk_t;

chunk_t* create_chunk(int count, int capacity);
void print_chunk(chunk_t* chunk);
void delete_chunk(chunk_t* chunk);

#endif