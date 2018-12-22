#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "data_instruct.h"

#ifndef BINARY_INSTRUCTION_H_
#define BINARY_INSTRUCTION_H_

typedef enum operand_type_e { REGISTER, IMMEDIATE, INDEX, NONE } operand_type;

typedef struct operand_s {
  operand_type type;
  uint8_t registerRef;
  uint16_t immediate;
  uint32_t index_offset;
} operand;

typedef struct binary_instruction_s {
  match_instruct_hexa instruction;
  operand Operande1;
  operand Operande2;
  operand Operande3;
} binary_instruction;

#endif // READ_H_