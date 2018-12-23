#include <stdio.h>
#include <stdlib.h>
#include "memoire.h"

int main(int argc, char *argv[])
{

  if (argc > 0) {
    int *memoire = NULL;
    memoire = InitMem();

    AfficherMemoireProg(memoire);
    AfficherMemoireDonnee(memoire);
    EcrireMemDonne(memoire, 120, 300);
    AfficherMemoireDonnee(memoire);
    Loadprog(memoire, "Test/Test2.o");
    AfficherMemoireProg(memoire);
  } else {
    printf("j'ai pas reussi a ouvrir les fichier");
  }
}
