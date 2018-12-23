#ifndef READ_H_
#define READ_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct raw_instruction {
  char* instruction;
  char* operand1;
  char* operand2;
  char* operand3;
  char* label;
  size_t line;
} raw_instruction;


raw_instruction* parse(char* filename);

#endif // READ_H_
