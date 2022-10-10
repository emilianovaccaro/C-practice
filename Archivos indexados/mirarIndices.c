#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ARTI {
	short int ART ;
	char COD[50];
	char DESC[100];
	char FAB[50];
	short int STOCK ;
};

struct INDEX {
	short int ART;
	int POS;
};

int main () {
	struct ARTI articulo;
	struct INDEX indice;
	int size;
	FILE *DB;
	
	if ( !(DB = fopen("BDINDICE", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDARTICULOS");
		exit(1);
	};
	
	printf("ARTICULO - INDICE");
	fread(&indice, sizeof(indice), 1, DB);
	while (!feof(DB)) {
		printf("\n %d %d",
			indice.ART,
			indice.POS
		);
		
		fread(&indice, sizeof(indice), 1, DB);
	}
	
	fclose(DB);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
