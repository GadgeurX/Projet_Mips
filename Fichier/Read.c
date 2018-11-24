#include <stdio.h>
#include <stdlib.h>
#include "Read.h"


InstructionBrut* Decode(char* Fichier){
  InstructionBrut* InstructionCoupe = malloc(sizeof(InstructionBrut));
  InstructionCoupe->Instruc = malloc(sizeof(char)*4);
  InstructionCoupe->Operande1 = NULL;
  InstructionCoupe->Operande2 = NULL;
  InstructionCoupe->Operande2 = NULL;

  FILE* Base = NULL;
  Base = fopen(Fichier, "r");
  char carrac = 'A';
  int i = 0;
  carrac = fgetc(Base);
  while(carrac != ' ' && carrac != '\n'){
    InstructionCoupe->Instruc[i] = carrac;
    carrac = fgetc(Base);
    i++;
  }
  i = 0;
  if(carrac != '\n'){
    InstructionCoupe->Operande1 = malloc(sizeof(char)*4);
    carrac = fgetc(Base);
    do{
      InstructionCoupe->Operande1[i] = carrac;
      carrac = fgetc(Base);

      i++;
    }while(carrac != ' ' && carrac != ',' && carrac != '\n');
  }


  i = 0;
  if(carrac != '\n'){
    InstructionCoupe->Operande2 = malloc(sizeof(char)*4);
    carrac = fgetc(Base);
    do{
      InstructionCoupe->Operande2[i] = carrac;
      carrac = fgetc(Base);

      i++;
    }while(carrac != ' ' && carrac != ',' && carrac != '\n');
  }


  i = 0;
  if(carrac != '\n'){
    InstructionCoupe->Operande3 = malloc(sizeof(char)*4);
    carrac = fgetc(Base);
    do{
      InstructionCoupe->Operande3[i] = carrac;
      carrac = fgetc(Base);

      i++;
    }while(carrac != ' ' && carrac != ',' && carrac != '\n');
  }
  fclose(Base);
  return InstructionCoupe;
}
