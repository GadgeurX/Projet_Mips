#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Read.h"
#include "charToHexa.h"

int convAphaToDec(char* chaine, int i, int taille){

  printf("carac = %d\n", chaine[taille - i]);
  if (i == taille){
    return(chaine[0]);
  }else{
    return(chaine[taille - i] + (10 * convAphaToDec(chaine, i+1, taille)));
  }

}

int calculTaille(char* chaine){

  int i = 0;
  while(chaine[i] != '\0'){

    i++;

  }

  return i;
}

void main(){

  /*char chaine[5] = {4,8,5,2};
  int taille = calculTaille(chaine);
  printf("%d\n", taille);
  int val = convAphaToDec(chaine, 1, taille);

  printf("%d\n",val );*/
/*
  char tab[3][3] = {{"A4"}, {"T1"}, {"VF"}};
  char ** pointeur = NULL;
  pointeur = &tab[1][2];
  printf("%c\n", *pointeur);
*/

  char sortie[9] = {"00011100"};
  char rep[3] = {0};

for(int i=0; i<2; i ++){

  int j =0;
  char tabTest[5] = {sortie[4*i], sortie[(4*i) + 1], sortie[(4*i) + 2], sortie[(4*i) + 3]};
  printf("%s\n", tabTest);
  char** pointeur = NULL;
  printf("test\n" );
  while(pointeur == NULL){//on suppose le bloc de caractere traite juste

    printf("nfois\n" );
    if(strcmp(binaireToHexa[2*j], tabTest) == 0){//meme chaine

      pointeur = &binaireToHexa[(2*j)+1];//pointe vers l'entree du tableau correspondant à la traduction

    }

    j++;

  }

  printf("le caractere en hexa est:%c\n", *pointeur);

  rep[i] = *pointeur;

}

printf("%s\n",rep );

}
