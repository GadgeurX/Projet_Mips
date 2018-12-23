#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#ifndef DATA_INSTRUCT_H_
#define DATA_INSTRUCT_H_

typedef enum instruc_type_e {J,I,R} instruc_type;

typedef struct match_instruct_hexa match_instruct_hexa;
struct match_instruct_hexa{
  char* name;
  uint8_t instruc;
  instruc_type type;
  uint8_t special;
};

#endif