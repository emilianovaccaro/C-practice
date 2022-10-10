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

int main () {
	struct ARTI articulo;
	FILE *DB;
	
	if ( !(DB = fopen("BDARTICULOS", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDARTICULOS");
		exit(1);
	};
	
	
	printf("ARTICULO CODIGO \tDESCRIPCION \t\tFABRICANTE \tSTOCK");
	fread(&articulo, sizeof(articulo), 1, DB);
	while (!feof(DB)) {
		printf("\n %d %s %s %s %d",
			articulo.ART,
			articulo.COD,
			articulo.DESC,
			articulo.FAB,
			articulo.STOCK
		);
		
		fread(&articulo, sizeof(articulo), 1, DB);
	}
	
	fclose(DB);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
