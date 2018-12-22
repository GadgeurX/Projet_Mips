#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "data_instruct.h"

#ifndef BINARY_INSTRUCTION_H_
#define BINARY_INSTRUCTION_H_

typedef struct binary_instruction_s {
  match_instruct_hexa instruction;
  operand Operande1;
  operand Operande2;
  operand Operande3;
} binary_instruction;

typedef struct operand_s {
  operand_type type;
  uint8_t registerRef;
  uint16_t immediate;
  uint32_t index_offset;
} operand;

typedef enum operand_type_e { REGISTER, IMMEDIATE, INDEX } operand_type;

#endif // READ_H_