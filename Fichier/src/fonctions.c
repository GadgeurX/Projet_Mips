#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fonctions.h"

void jump(int instruct){
  int index_registre; //opérande de l'instruction Jump

  printf("%x\n", instruct);


  index_registre = instruct%0x04000000; //garde uniquement les 26 premiers bits
  index_registre = index_registre << 2; //décale à gauche pour retrouver l'adresse pointé par l'instruction
  printf("%x\n", index_registre);

}


void lireCodeHexa(){
  //tableau de int contenant la ligne d'instruction
  int instruct;
  int carrac;
  int operateur = 0; //variable récupérant l'opérateur de l'instruction
  //Ouverture du fichier avec les codes hexa
  FILE * fichier;

  fichier = fopen("assembleur_hexa.txt","r");

  if(fichier != NULL){
    do{
      fscanf(fichier, "%x", &instruct);
      printf("%x\n", instruct);

      operateur = instruct>>26;
      switch (operateur) {
        case 0x02:  jump(instruct);
        break;


      }
      carrac = fgetc(fichier);
    }while(carrac != EOF);
    fclose(fichier);

  }
  else{
    printf("impossible d'ouvrir ce fichier\n");
  }
}
