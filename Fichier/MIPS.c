 #include <stdio.h>
 #include <stdlib.h>
 #include "Read.h"




 int main(int argc, char *argv[]){

   InstructionBrut* premier;
   premier = Decode (argv[1]);
   printf("L'instruction est : %s\n", (*premier).Instruc);
   printf("avec l'operande : %s\n", (*premier).Operande1);
   if((*premier).Operande2 != NULL){printf("Et : %s\n", (*premier).Operande2);}
   if((*premier).Operande3 != NULL){printf("Et : %s\n", (*premier).Operande3);}

   premier = Decode (argv[1]);
   printf("L'instruction est : %s\n", (*premier).Instruc);
   printf("avec l'operande : %s\n", (*premier).Operande1);
   if((*premier).Operande2 != NULL){printf("Et : %s\n", (*premier).Operande2);}
   if((*premier).Operande3 != NULL){printf("Et : %s\n", (*premier).Operande3);}

   premier = Decode (argv[1]);
   printf("L'instruction est : %s\n", (*premier).Instruc);
   printf("avec l'operande : %s\n", (*premier).Operande1);
   if((*premier).Operande2 != NULL){printf("Et : %s\n", (*premier).Operande2);}
   if((*premier).Operande3 != NULL){printf("Et : %s\n", (*premier).Operande3);}
}
