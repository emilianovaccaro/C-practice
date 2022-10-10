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
	short int articuloBuscado, encontrado;
	FILE *DB;
	
	if ( !(DB = fopen("BDARTICULOS", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDARTICULOS");
		exit(1);
	};
	
	printf("\nINGRESAR ARTICULO: ");
	scanf("%d", &articuloBuscado);
	
	fread(&articulo, sizeof(articulo), 1, DB);
	while(!feof(DB) && !encontrado) {
		if (articulo.ART == articuloBuscado) {
			printf("\n %d %s %s %s %d",
				articulo.ART,
				articulo.COD,
				articulo.DESC,
				articulo.FAB,
				articulo.STOCK
			);
			encontrado = 1;
		}
		
		fread(&articulo, sizeof(articulo), 1, DB);
	}
	
	
	if (!encontrado) {
		printf("\n NO SE ENCONTRO EL ARTICULO BUSCADO");
	}
	
	
	fclose(DB);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
