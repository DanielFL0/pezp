#ifndef VM_H
#define VM_H

typedef enum {
  RE_X0 = 0x00, /* zero   hard-wired zero                       ------ */
  RE_X1,        /* ra     return address                        caller */
  RE_X2,        /* sp     stack pointer                         callee */
  RE_X3,        /* gp     global pointer                        ------ */
  RE_X4,        /* tp     thread pointer                        ------ */
  RE_X5,        /* t0     temporary/alternate link register     caller */
  RE_X6,        /* t1     temporaries                           caller */
  RE_X7,        /* t2     temporaries                           caller */
  RE_X8,        /* s0/fp  saved register/framer pointer         callee */
  RE_X9,        /* s1     saved register                        callee */
  RE_X10,       /* a0     function arguments/return values      caller */
  RE_X11,       /* a1     function arguments/return values      caller */
  RE_X12,       /* a2     function arguments                    caller */
  RE_X13,       /* a3     function arguments                    caller */
  RE_X14,       /* a4     function arguments                    caller */
  RE_X15,       /* a5     function arguments                    caller */
  RE_X16,       /* a6     function arguments                    caller */
  RE_X17,       /* a7     function arguments                    caller */
  RE_X18,       /* s2     saved registers                       callee */
  RE_X19,       /* s3     saved registers                       callee */
  RE_X20,       /* s4     saved registers                       callee */
  RE_X21,       /* s5     saved registers                       callee */
  RE_X22,       /* s6     saved registers                       callee */
  RE_X23,       /* s7     saved registers                       callee */
  RE_X24,       /* s8     saved registers                       callee */
  RE_X25,       /* s9     saved registers                       callee */
  RE_X26,       /* s10    saved registers                       callee */
  RE_X27,       /* s11    saved registers                       callee */
  RE_X28,       /* t3     temporaries                           caller */
  RE_X29,       /* t4     temporaries                           caller */
  RE_X30,       /* t5     temporaries                           caller */
  RE_X31,       /* t6     temporaries                           caller */
  RE_F0,        /* ft0    fp temporaries                        caller */
  RE_F1,        /* ft1    fp temporaries                        caller */
  RE_F2,        /* ft2    fp temporaries                        caller */
  RE_F3,        /* ft3    fp temporaries                        caller */
  RE_F4,        /* ft4    fp temporaries                        caller */
  RE_F5,        /* ft5    fp temporaries                        caller */
  RE_F6,        /* ft6    fp temporaries                        caller */
  RE_F7,        /* ft7    fp temporaries                        caller */
  RE_F8,        /* fs0    fp saved registers                    callee */
  RE_F9,        /* fs1    fp saved registers                    callee */
  RE_F10,       /* fa0    fp arguments/return values            caller */
  RE_F11,       /* fa1    fp arguments/return values            caller */
  RE_F12,       /* fa2    fp arguments                          caller */
  RE_F13,       /* fa3    fp arguments                          caller */
  RE_F14,       /* fa4    fp arguments                          caller */
  RE_F15,       /* fa5    fp arguments                          caller */
  RE_F16,       /* fa6    fp arguments                          caller */
  RE_F17,       /* fa7    fp arguments                          caller */
  RE_F18,       /* fs2    fp saved registers                    callee */
  RE_F19,       /* fs3    fp saved registers                    callee */
  RE_F20,       /* fs4    fp saved registers                    callee */
  RE_F21,       /* fs5    fp saved registers                    callee */
  RE_F22,       /* fs6    fp saved registers                    callee */
  RE_F23,       /* fs7    fp saved registers                    callee */
  RE_F24,       /* fs8    fp saved registers                    callee */
  RE_F25,       /* fs9    fp saved registers                    callee */
  RE_F26,       /* fs10   fp saved registers                    callee */
  RE_F27,       /* fs11   fp saved registers                    callee */
  RE_F28,       /* ft8    fp temporaries                        caller */
  RE_F29,       /* ft9    fp temporaries                        caller */
  RE_F30,       /* ft10   fp temporaries                        caller */
  RE_F31,       /* ft11   fp temporaries                        caller */
  RE_COUNT
} rg_t; /* registers */

typedef enum {
  /* arithmetic */
  OP_ADD  = 0x00, /* add                                  add x5, x6, x7      x5 = x6 + x7                  */
  OP_SUB ,        /* subtract                             sub x5, x6, x7      x5 = x6 - x7                  */
  OP_ADDI,        /* add immediate                        addi x5, x6, 20     x5 = x6 - 20                  */
  /* data transfer */
  OP_LD,          /* load doubleword                      ld x5, 40(x6)       x5 = Memory[x6 + 40]          */
  OP_SD,          /* store doubleword                     sd x5, 40(x6)       Memory[x6 + 40] = x5          */
  OP_LW,          /* load word                            lw x5, 40(x6)       x5 = Memory[x6 + 40]          */
  OP_LWU,         /* load word, unsigned                  lwu x5, 40(x6)      x5 = Memory[x6 + 40]          */
  OP_SW,          /* store word                           sw x5, 40(x6)       Memory[x6 + 40] = x5          */
  OP_LH,          /* load halfword                        lh x5, 40(x6)       x5 = Memory[x6 + 40]          */
  OP_LHU,         /* load halfword, unsigned              lhu x5, 40(x6)      x5 = Memory[x6 + 40]          */
  OP_SH,          /* store halfword                       sh x5, 40(x6)       Memory[x6 + 40] = x5          */
  OP_LB,          /* load byte                            lb x5, 40(x6)       x5 = Memory[x6 + 40]          */
  OP_LBU,         /* load byte, unsigned                  lbu x5, 40(x6)      x5 = Memory[x6 + 40]          */
  OP_SB,          /* store byte                           sb x5, 40(x6)       Memory[x6 + 40] = x5          */
  OP_LR,          /* load reserved                        lr.d x5, (x6)       x5 = Memory[x6 ]              */
  OP_SC,          /* store conditional                    sc.d x7, x5, (x6)   Memory[x6] = x5; x7 = 0/1     */
  OP_LUI,         /* load upper immediate                 lui x5, 0x12345     x5 = 0x12345000               */
  /* logical */
  OP_AND,         /* and                                  and x5, x6, x7      x5 = x6 & x7                  */
  OP_OR,          /* inclusive or                         or x5, x6, x8       x5 = x6 | x8                  */
  OP_XOR,         /* exclusive or                         xor x5, x6, x9      x5 = x6 ^ x9                  */
  OP_ANDI,        /* and immediate                        andi x5, x6, 20     x5 = x6 & 20                  */
  OP_ORI,         /* inclusive or immediate               ori x5, x6, 20      x5 = x6 | 20                  */
  OP_XORI,        /* exclusive or immediate               xori x5, x6, 20     x5 = x6 ^ 20                  */
  /* shift */
  OP_SLL,         /* shift left logical                   sll x5, x6, x7      x5 = x6 << x7                 */
  OP_SRL,         /* shift right logical                  srl x5, x6, x7      x5 = x6 >> x7                 */
  OP_SRD,         /* shift right arithmetic               sra x5, x6, x7      x5 = x6 >> x7                 */
  OP_SLLI,        /* shift left logical immediate         slli x5, x6, 3      x5 = x6 << 3                  */
  OP_SRLI,        /* shift right logical immediate        srli x5, x6, 3      x5 = x6 >> 3                  */
  OP_SRAI,        /* shift right arithmetic immediate     srai x5, x6, 3      x5 = x6 >> 3                  */
  /* conditional branch */
  OP_BEQ,        /* branch if equal                       beq x5, x6, 100     if (x5 == x6) go to PC+100    */
  OP_BNE,        /* branch if not equal                   bne x5, x6, 100     if (x5 != x6) go to PC+100    */
  OP_BLT,        /* branch if less than                   blt x5, x6, 100     if (x5 < x6) go to PC+100     */
  OP_BGE,        /* branch if greater or equal            bge x5, x6, 100     if (x5 >= x6) go to PC+100    */
  OP_BLTU,       /* branch if less, unsigned              bltu x5, x6, 100    if (x5 < x6) go to PC+100     */
  OP_BGEU,       /* branch if greater or equal unsigned   bgeu x5, x6, 100    if (x5 >= x6) go to PC+100    */
  /* unconditional branch */
  OP_JAL,        /* jump and link                         jal xl, 100         x1 = PC+4; go to PC+100       */
  OP_JALR,       /* jump and link register                jalr xl, 100(x5)    x1 = PC+4; go to x5+100       */
  OP_COUNT
} op_t; /* opcodes */

#endif