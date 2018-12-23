#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


uint32_t* stick(binary_instruction *instruct){
  uint32_t* hexa_instruct;
  while((instruct+i)!=NULL){
      if((instruc+i)->instruction.type == R){
          printf("[ERROR]: type R not supply");
          hexa_instruct = 0;
      }
      else if((instruct+i)->instruction.type == I){
          hexa_instruct = (instruc+i)->instruction.instruc << 26;
          hexa_instruct += (instruc+i)->Operande1.registerRef << 21;
          hexa_instruct += (instruc+i)->Operande2.registerRef << 16;
          hexa_instruct += (instruc+i)->Operande3.immediate;
      }
      else{
        hexa_instruct = (instruc+i)->instruction.instruc << 26;
        hexa_instruct += (instruc+i)->Operande1.index_offset;
      }
  i++;
  }
}
