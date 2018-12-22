#include <stdio.h>
#include <stdlib.h>

#ifndef READ_H_
#define READ_H_
typedef struct InstructionBrut InstructionBrut;
struct InstructionBrut{
  char* Label;
  char* Instruc;
  char* Operande1;
  char* Operande2;
  char* Operande3;
};


InstructionBrut* Decode(char*);

#endif // READ_H_
