#ifndef CHUNK_H
#define CHUNK_H

#define MEMORY_MAX (1 << 8)

typedef struct chunk_t {
  uint8_t*  buffer;
  uint8_t*  buffer_offset;
  uint8_t*  buffer_length;
} chunk_t;

void init_chunk(chunk_t* chunk);
void write_chunk(chunk_t* chunk, uint8_t byte);
void disassemble_chunk(chunk_t* chunk, char* name);
void free_chunk(chunk_t* chunk);

#endif