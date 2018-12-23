#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

<<<<<<< HEAD
#ifndef DATA_INSTRUCT_H_
#define DATA_INSTRUCT_H_

typedef enum instruc_type_e {J,I,R} instruc_type;
=======
typedef enum instruc_type {J,I,R};
>>>>>>> createru d'instruction

typedef struct match_instruct_hexa match_instruct_hexa;
struct match_instruct_hexa{
  char* name;
  uint8_t instruc;
  instruc_type type;
  uint8_t special;
};

match_instruct_hexa tab_instruct[] = {
  {"ADDI", 0x20,I, 0x00},
  {"ADD", 0x00, R, 0x80},
  {"BEQ" , 0x10, I, 0x00},
  {"AND", 0x00, R, 0x90},
  {"BLEZ", 0x18, I, 0x00},
  {"BGTZ",0x1C, I,0x00},
  {"DIV", 0x00, R, 0x068},
  {"BNE",0x14, I,0x00},
  {"J", 0x08, J,0x00},
  {"JR", 0x00, R, 0x20},
  {"JAL", 0x0C, J,0x00},
  {"LUI", 0x3C, I, 0x00},
  {"MFHI", 0x00, R, 0x40},
  {"LW", 0x8C, I, 0x00},
  {"MULT", 0x00, R, 0x60},
  {"MFLO", 0x00, R, 0x48},
  {"OR", 0x00, R, 0x94},
  {"NOP", 0x00, R, 0x00},
  {"ROTR", 0x00, R, 0x08},
  {"SLL", 0x00, R, 0x00},
  {"SLT", 0x00, R, 0xA8},
  {"SRL", 0x00, R,0x08},
  {"SUB", 0x00, R, 0x88},
  {"SW", 0xAC, I, 0x00},
  {"SYSCALL", 0x00, R, 0x30},
  {"XOX", 0x00, R, 0x98},
  {NULL, 0x00, R, 0x00},
};

#endif