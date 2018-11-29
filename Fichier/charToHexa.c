#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Read.h"
#include "charToHexa.h"

#define NBINSTRUCTIONJ 2
#define NBINSTRUCTIONI
#define NBINSTRUCTIONR

void main(){

  InstructionBrut *instruct;
  InstructionBrut instructBis[2] = {{"J", "3", NULL, NULL},{"JAL", "3", NULL, NULL}};
  instruct = &instructBis;

  charToHexa(instructBis);

}

  /*
  * On reçoit un tableau de type InstructionBrut
  * Si l'element Instruc de l'InstructionBrut est == NULL alors fin du tableau
  */

void charToHexa( InstructionBrut instruction[]){//Fonction de redirection

  char resultat [9] = {0};//8 caractere d'instruction, + 1 pour la sentinelle
  int i = 0;

  //Cas instruction System, pas de parametre
  if(instruction[0].Operande1 == NULL){



  }

  //séparation instruction type J, I, r
  if(instruction[0].Operande2 == NULL){//dans le cas d'une instruction de type J

    while(i<2){
    convertionInstructionTypeJ(instruction[i].Instruc, instruction[i].Operande1);
    i++;
    }
  }
  /*if(instruction.Operande3 == NULL){//dans le cas d'une instruction de type I

    resultat = convertionInstructionTypeI(instruction.Instruc, instruction.Operande1, instruction.Operande2);

  }
  else{//dans le cas d'une instruction de type R

    resultat = convertionInstructionTypeR(instruction.Instruc, instruction.Operande1, instruction.Operande2, instruction.Operande3);

  }*/

}

void convertionInstructionTypeJ (char* instruction, char* operande){

  /*
  * stockage des instructions de typeJ,
  * tableau de tableau
  * 2n  colonne, operande,
  * 2n + 1 colonne, valeur en hexa
  */
  char instrucionJ [NBINSTRUCTIONJ * 2][7] = {
    {"J"}, {"000010"},
    {"JAL"}, {"000011"}
  };

  int i = 0;
  int j = 0;
  int match = 1;
  int val=0;
  char* result;

  for(i = 0; i < NBINSTRUCTIONJ * 2; i += 2){//on fait défiler le tableau d'instruction

    if( strlen(instruction) == strlen(instrucionJ[i])){//si l'instruction testée a la meme taille que celle dans le tableau
    j = 0;
    match = 1;
      while ((j < strlen(instruction)) && (match == 1)) {//verifie que l'instruction soit la meme, caractere par caractere
        if( instruction[j] != instrucionJ[i][j]){//teste le caractere i
          match = 0;
        }
        j++;
      }
    if(match == 1){ val = i; }
    }

  }

  printf("L'instruction %s correspond à la valeur: %s\n", instruction, instrucionJ[(val+1)]);
}
/*
char* convertionInstructionTypeI (char instruction, char operande1, char operande2){



}

char* convertionInstructionTypeR (char instruction, char operande1, char operande2, char operande3){



}*/
