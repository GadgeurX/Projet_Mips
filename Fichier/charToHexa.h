#ifndef charToHexa_H_
#define charToHexa_H_

void charToHexa( InstructionBrut instruction[]);//Fonction de redirection
char* convertionInstructionTypeJ (char* instruction, char* operande1);
char* convertionInstructionTypeI (char* instruction, char* operande1, char* operande2);
char* convertionInstructionTypeR (char* instruction, char* operande1, char* operande2, char* operande3);

//tableau de convertion pour caractere
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
