#Label chemin d'accès
SRC_PATH = src/


Mips : $(SRC_PATH)MIPS.c $(SRC_PATH)Read.c $(SRC_PATH)ecritureFichier.c $(SRC_PATH)Registre.c $(SRC_PATH)charToHexa.c
	gcc -o $@ -Wall -lm $^
	clear
	./Mips Test/Test5.txt
