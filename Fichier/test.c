#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  char chaine[5] = {4,8,5,2};
  int taille = calculTaille(chaine);
  printf("%d\n", taille);
  int val = convAphaToDec(chaine, 1, taille);

  printf("%d\n",val );

}
