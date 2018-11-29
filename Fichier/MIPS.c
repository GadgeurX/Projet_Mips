 #include <stdio.h>
 #include <stdlib.h>
 #include "Read.h"




 int main(int argc, char *argv[]){
  if(argc > 0){
    InstructionBrut* premier;
    int i = 0;
    do{
      premier = Decode (argv[1]);
      printf("L'instruction est :%s\n", (*(premier+i)).Instruc);
      printf("avec l'operande :%s\n", (*(premier+i)).Operande1);
      if((*(premier+i)).Operande2 != NULL){printf("Et :%s\n", (*(premier+i)).Operande2);}
      if((*(premier+i)).Operande3 != NULL){printf("Et :%s\n", (*(premier+i)).Operande3);}
      i++;
    }while (((*(premier+i)).Instruc != NULL));
    free(premier);
  }
  else{printf("j'ai pas reusii a ouvrir les fichier");}
}
