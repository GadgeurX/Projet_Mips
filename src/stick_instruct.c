#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binary_instruction.h"


uint32_t* stick(binary_instruction *instruct){
  uint32_t* hexa_instruct;
  int i = 0;
  while ((instruct + i)!=NULL){
      if ((instruct + i)->instruction.type == R){
          printf("[ERROR]: type R not supply");
          hexa_instruct = 0;
      }
      else if ((instruct + i)->instruction.type == I){
          *(hexa_instruct + i) = (instruct + i)->instruction.instruc << 26;
          *(hexa_instruct + i) += (instruct + i)->operand1.value.registerRef << 21;
          *(hexa_instruct + i) += (instruct + i)->operand2.value.registerRef << 16;
          *(hexa_instruct + i) += (instruct + i)->operand3.value.immediate;
      }
      else{
        *(hexa_instruct + i) = (instruct + i)->instruction.instruc << 26;
        *(hexa_instruct + i) += (instruct + i)->operand1.value.index_offset;
      }
  i++;
  }
}
