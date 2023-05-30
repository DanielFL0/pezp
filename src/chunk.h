#ifndef CHUNK_H
#define CHUNK_H

/**
 * CHUNK MODULE
 * This module is designed for the creation of chunk(s) of
 * bytecode. The main component chunk_t contains three 
 * basic elements, an array to store the bytecode, an
 * integer of 32 bits that stores the size of the buffer
 * (this integer is used to store the current size
 * of the buffer and as a boundary check so that the
 * memory gets reallocated when needed) and finally 
 * another integer of 32 bits that serves as an index
 * to keep track of the number of items in the array,
 * both of these integeres are used as a mechanism to
 * check if another byte can be written into the array
 * or if the buffer needs to get reallocated to a larger
 * space in memory.
 */

typedef struct chunk_t {
  uint8_t*  buffer;
  uint32_t  buffer_size;
  uint32_t  program_counter;
} chunk_t;

error_t init_chunk(chunk_t* chunk, uint32_t size);
error_t write_chunk(chunk_t* chunk, uint8_t byte);
error_t free_chunk(chunk_t* chunk);

#endif