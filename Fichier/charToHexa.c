#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Read.h"
#include "charToHexa.h"

void main(){

  InstructionBrut instructBis[] = {{"J", "3", NULL, NULL},{"JAL", "3", NULL, NULL},{"J", "3", NULL, NULL},{NULL,NULL,NULL,NULL}};

  charToHexa(instructBis);

}

  /*
  * On reçoit un tableau de type InstructionBrut
  * Si l'element Instruc de l'InstructionBrut est == NULL alors fin du tableau
  */

void charToHexa( InstructionBrut instruction[]){//Fonction de redirection

  int i = 0;
  while(instruction[i].Instruc != NULL){//arret lorsque plus d'instructions

    char resultatHexa [9] = {0};//8 caractere d'instruction, + 1 pour la sentinelle
    char resultatBinaire[33] = {0}, *resBin;

    //Cas instruction System, pas de parametre
    if(instruction[i].Operande1 == NULL){



    }

    //séparation instruction type J, I, r
    if(instruction[i].Operande2 == NULL){//dans le cas d'une instruction de type J

      resBin = convertionInstructionTypeJ(instruction[i].Instruc, instruction[i].Operande1);
      printf("adresse de visee de res = %d\n", resBin );
      printf("%s\n",*resBin );

    }
    /*if(instruction.Operande3 == NULL){//dans le cas d'une instruction de type I

      resultat = convertionInstructionTypeI(instruction.Instruc, instruction.Operande1, instruction.Operande2);

    }
    else{//dans le cas d'une instruction de type R

      resultat = convertionInstructionTypeR(instruction.Insctruc, instruction.Operande1, instruction.Operande2, instruction.Operande3);

    }*/
    i++;
  }
}

char* convertionInstructionTypeJ (char* instruction, char* operande){

  int i = 0;
  int j = 0;
  int match = 1;
  int val=0;
  char* result = malloc(sizeof(char));

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
  printf("adresse de tab = %d\n", &instrucionJ[val+1] );

  result = &instrucionJ[val+1];

  printf("adresse visee par result = %d\n", result );
  printf("result = %s\n", *result );

  return(result);//renvoi pointeur sur bon element du tableau

}
/*
char* convertionInstructionTypeI (char instruction, char operande1, char operande2){



}

char* convertionInstructionTypeR (char instruction, char operande1, char operande2, char operande3){



}*/
