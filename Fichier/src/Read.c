#include <stdio.h>
#include <stdlib.h>
#include "Read.h"


InstructionBrut* Decode(char* Fichier){
  InstructionBrut* InstructionCoupe = malloc(sizeof(InstructionBrut)*100);

  int j = 0;

  FILE* Base = NULL;
  Base = fopen(Fichier, "r");
  char carrac = '1';
  int i = 0;

  while(carrac != EOF){


    (InstructionCoupe+j)->Instruc = malloc(sizeof(char)*7);
    (InstructionCoupe+j)->Operande1 = NULL;
    (InstructionCoupe+j)->Operande2 = NULL;
    (InstructionCoupe+j)->Operande2 = NULL;



    i =0;

    if(carrac != EOF){carrac = fgetc(Base);}

    do{
      if(carrac >='A' && carrac <= 'Z'){
        (InstructionCoupe+j)->Instruc[i] = carrac;
        i++;
      }
      if(carrac != EOF){carrac = fgetc(Base);}
    }while(carrac != ' ' && carrac != ',' && carrac != '\n' && carrac != EOF);
    (InstructionCoupe+j)->Instruc[i] = '\0';


    i = 0;


    if(carrac != '\n' && carrac != EOF){
      (InstructionCoupe+j)->Operande1 = malloc(sizeof(char)*2);
      if(carrac != EOF){carrac = fgetc(Base);}
      do{
        (InstructionCoupe+j)->Operande1[i] = carrac;
        if(carrac != EOF){carrac = fgetc(Base);}

        i++;

      }while(carrac != ' ' && carrac != ',' && carrac != '\n' && carrac != EOF);

      (InstructionCoupe+j)->Operande1[i] = '\0';
    }


    i = 0;
    if(carrac != '\n' && carrac != EOF){
      (InstructionCoupe+j)->Operande2 = malloc(sizeof(char)*4);
      if(carrac != EOF){carrac = fgetc(Base);}
      do{
        (InstructionCoupe+j)->Operande2[i] = carrac;
        if(carrac != EOF){carrac = fgetc(Base);}

        i++;
      }while(carrac != ' ' && carrac != ',' && carrac != '\n' && carrac != EOF);
      (InstructionCoupe+j)->Operande2[i] = '\0';
    }


    i = 0;
    if(carrac != '\n' && carrac != EOF){
      (InstructionCoupe+j)->Operande3 = malloc(sizeof(char)*4);
      if(carrac != EOF){carrac = fgetc(Base);}
      do{
        (InstructionCoupe+j)->Operande3[i] = carrac;
        if(carrac != EOF){carrac = fgetc(Base);}

        i++;
      }while(carrac != '\n' && carrac != EOF);
      (InstructionCoupe+j)->Operande3[i] = '\0';
    }

    j++;
  }

  (InstructionCoupe+j-1)->Instruc = NULL;


  fclose(Base);
  return InstructionCoupe;
}
