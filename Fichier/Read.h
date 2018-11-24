#include <stdio.h>
#include <stdlib.h>

typedef struct InstructionBrut InstructionBrut;
struct InstructionBrut{
  char* Instruc;
  char* Operande1;
  char* Operande2;
  char* Operande3;
};


InstructionBrut* Decode(char*);
