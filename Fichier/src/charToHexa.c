#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Read.h"
#include "charToHexa.h"

#define NBINSTRUCTIONJ 2
#define NBINSTRUCTIONI
#define NBINSTRUCTIONR

void main(){

  InstructionBrut instructBis[2] = {{"J", "3", NULL, NULL},{"JAL", "3", NULL, NULL}};

  charToHexa(instructBis);

}

  /*
  * On reçoit un tableau de type InstructionBrut
  * Si l'element Instruc de l'InstructionBrut est == NULL alors fin du tableau
  */

void charToHexa( InstructionBrut instruction[]){//Fonction de redirection

  int i = 0;
  while('instruction[i].Instruc' != NULL){

    char resultatHexa [9] = {0};//8 caractere d'instruction, + 1 pour la sentinelle
    char resultatBinaire [33] = {0};

    //Cas instruction System, pas de parametre
    if(instruction[i].Operande1 == NULL){



    }

    //séparation instruction type J, I, r
    if(instruction[i].Operande2 == NULL){//dans le cas d'une instruction de type J

      convertionInstructionTypeJ(instruction[i].Instruc, instruction[i].Operande1);

    }
    /*if(instruction.Operande3 == NULL){//dans le cas d'une instruction de type I

      resultat = convertionInstructionTypeI(instruction.Instruc, instruction.Operande1, instruction.Operande2);

    }
    else{//dans le cas d'une instruction de type R

      resultat = convertionInstructionTypeR(instruction.Instruc, instruction.Operande1, instruction.Operande2, instruction.Operande3);

    }*/

    //appelle de la fct de convertion de binaireToHexa


    i++;

  }
}

char* convertionInstructionTypeJ (char* instruction, char* operande){

  //pointeur sur un tableau de 32 carac, retour en binaire
  char* valeurRetourBinaire = malloc(32 * sizeof(int));

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

  i = 0;
  while(i < 6){//on ecrit dans la chaine de carac reponse, l'instruction

    valeurRetourBinaire[i] = instrucionJ[val + 1][i];

  }

  printf("L'instruction %s correspond à la valeur: %s\n", instruction, valeurRetourBinaire);

  return(valeurRetourBinaire);

}

/*
char* convertionInstructionTypeI (char instruction, char operande1, char operande2){



}

char* convertionInstructionTypeR (char instruction, char operande1, char operande2, char operande3){



}*/
