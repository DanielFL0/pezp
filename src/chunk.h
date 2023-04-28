#ifndef CHUNK_H
#define CHUNK_H

#define IS_CHUNK_VALID(chunk) ((chunk)->count > 0)

typedef struct chunk_t {
  uint32_t  count;
  uint32_t  capacity;
  uint8_t*  code;
} chunk_t;

void init_chunk(chunk_t* chunk);
void read_chunk(chunk_t* chunk);
void write_chunk(chunk_t* chunk, uint8_t byte);
void free_chunk(chunk_t* chunk);


#endif