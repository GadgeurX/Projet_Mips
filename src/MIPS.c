#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "memoire.h"

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("[ERROR]: An error has occurred\n");
}

int main(int argc, char *argv[])
{

  signal(SIGINT, sig_handler);

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
