#ifndef DEFS_H
#define DEFS_H

#define PC_START 0x3000
#define MEMORY_MAX (1 << 16)
#define RUNNING 1
#define HALTED 0

typedef enum {
  OP_INC, /* increment the register */
  OP_DEC, /* decrement the register */
  OP_DONE /* stop execution*/
} opcodes;

typedef enum {
  R_R0,   /* register 0 */
  R_R1,   /* register 1 */
  R_R2,   /* register 2 */
  R_R3,   /* register 3 */
  R_R4,   /* register 4 */
  R_R5,   /* register 5 */
  R_R6,   /* register 6 */
  R_R7,   /* register 7 */
  R_PC,   /* program counter */
  R_COND, /* condition flags register*/
  R_COUNT /* register count*/
} registers;

typedef enum {
  FL_POS = 1 << 0,  /* 1: P */
  FL_ZRO = 1 << 1,  /* 2: Z */
  FL_NEG = 1 << 2   /* 4: N */
} condition_flags;

typedef enum {
  MR_KBSR = 0xFE00, /* keyboard status */
  MR_KBDR = 0xFE02  /* keyboard data */
} memory_registers;

#endif