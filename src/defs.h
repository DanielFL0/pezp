#ifndef DEFS_H
#define DEFS_H

#define PC_START 0x3000
#define MEMORY_MAX (1 << 16)

typedef enum {
  OP_BR,  /* branch */
  OP_ADD, /* add */
  OP_LD,  /* load */
  OP_ST,  /* store */
  OP_JSR, /* jump register */
  OP_AND, /* bitwise and */
  OP_LDR, /* load register */
  OP_STR, /* store register */
  OP_RTI, /* unused */
  OP_NOT, /* bitwise not */
  OP_LDI, /* load indirect */
  OP_STI, /* store indirect */
  OP_JMP, /* jump */
  OP_RES, /* reserved */
  OP_LEA, /* load effective address */
  OP_TRAP /* execute trap */
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