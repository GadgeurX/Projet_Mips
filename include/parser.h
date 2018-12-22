#ifndef READ_H_
#define READ_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct raw_instruction {
  char* instruc;
  char* operande1;
  char* operande2;
  char* operande3;
  char* label;
} raw_instruction;


raw_instruction* parse(char* filename);

#endif // READ_H_
