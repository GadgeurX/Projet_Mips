#ifndef charToHexa_H_
#define charToHexa_H_

#define NBINSTRUCTIONJ 2
#define NBINSTRUCTIONI
#define NBINSTRUCTIONR

void charToHexa( InstructionBrut instruction[]);//Fonction de redirection
void convertionInstructionTypeJ (char* instruction, char* operande1);
char* convertionInstructionTypeI (char* instruction, char* operande1, char* operande2);
char* convertionInstructionTypeR (char* instruction, char* operande1, char* operande2, char* operande3);

int convAphaToDec(char* chaine, int i, int taille);
int calculTaille(char* chaine);

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

char binaireToHexa[33][5] = {
  {"0000"},{"0"},
  {"0001"},{"1"},
  {"0010"},{"2"},
  {"0011"},{"3"},
  {"0100"},{"4"},
  {"0101"},{"5"},
  {"0110"},{"6"},
  {"0111"},{"7"},
  {"1000"},{"8"},
  {"1001"},{"9"},
  {"1010"},{"A"},
  {"1011"},{"B"},
  {"1100"},{"C"},
  {"1101"},{"D"},
  {"1110"},{"E"},
  {"1111"},{"F"},
};

#endif
