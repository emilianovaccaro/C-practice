#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ARTI {
	short int ART;
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
	int I = 0;
	FILE *DB, *DBINDEX;
	
	if ( !(DB = fopen("BDARTICULOS", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDARTICULOS");
		exit(1);
	};	
	
	if ( !(DBINDEX = fopen("BDINDICE", "wb"))) {
		printf("\n ERROR EN LA APERTURA DE INDICES");
		exit(1);
	};
	
	
	fread(&articulo, sizeof(articulo), 1, DB);
	while (!feof(DB)) {
		indice.ART = articulo.ART;
		indice.POS = I;
		fwrite(&indice, sizeof(indice), 1, DBINDEX);

		fread(&articulo, sizeof(articulo), 1, DB);
		I++;
	}
	
	
	fclose(DB);
	fclose(DBINDEX);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
