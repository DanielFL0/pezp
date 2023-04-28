#ifndef DEBUG_H
#define DEBUG_H

void disassemble_chunk(chunk_t* chunk, const char* name);
int disassemble_instruction(chunk_t* chunk, int offset);
void simple_instruction(const char* name);

#endif