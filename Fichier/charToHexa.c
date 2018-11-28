#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Read.h"
#include "charToHexa.h"

#define NBINSTRUCTIONJ 2
#define NBINSTRUCTIONI
#define NBINSTRUCTIONR

void main(){

  InstructionBrut instruct = {"J", "3", NULL, NULL};

  charToHexa(instruct);

}

char* charToHexa( InstructionBrut instruction){//Fonction de redirection

  char resultat [8] = {0};

  //Cas instruction System, pas de parametre
  if(instruction.Operande1 == NULL){



  }

  //séparation instruction type J, I, r
  if(instruction.Operande2 == NULL){//dans le cas d'une instruction de type J

    convertionInstructionTypeJ(instruction.Instruc, instruction.Operande1);

  }
  /*if(instruction.Operande3 == NULL){//dans le cas d'une instruction de type I

    resultat = convertionInstructionTypeI(instruction.Instruc, instruction.Operande1, instruction.Operande2);

  }
  else{//dans le cas d'une instruction de type R

    resultat = convertionInstructionTypeR(instruction.Instruc, instruction.Operande1, instruction.Operande2, instruction.Operande3);

  }*/

  return (resultat);

}

void convertionInstructionTypeJ (char* instruction, char* operande){

  /*
  * stockage des instructions de typeJ,
  * tableau de tableau
  * 2n  colonne, operande,
  * 2n + 1 colonne, valeur en hexa
  */
  char instrucionJ [NBINSTRUCTIONJ * 2][6] = {
    {'J'}, {'0','0','0','0','1','0'},
    {'J','A','L'}, {'0','0','0','0','1','1'}
  };

  int i = 0;
  int j = 0;
  int match = 1;
  int val;
  char* result;

  for(i = 0; i < NBINSTRUCTIONJ * 2; i += 2){//on fait défiler le tableau d'instruction

    if( strlen(instruction) == strlen(instrucionJ[i][0])){//si l'instruction testée a la meme taille que celle dans le tableau
    j = 0;
    match = 1;
      while ((j < strlen(instruction)) || (match == 1)) {//verifie que l'instruction soit la meme, caractere par caractere
        if( instruction[j] != instrucionJ[j][0]){//teste le caractere i
          match == 0;
        }
        j++;
      }
    if(match == 1){ val = i; }
    }

  }

  printf("L'instruction %s correspond à la valeur: %s", instruction, instrucionJ[val++]);

}
/*
char* convertionInstructionTypeI (char instruction, char operande1, char operande2){



}

char* convertionInstructionTypeR (char instruction, char operande1, char operande2, char operande3){



}*/
