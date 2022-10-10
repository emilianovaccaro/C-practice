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

struct PROVEEDOR {
	char FAB[50];
	int CANTIDAD;
};

int main () {
	struct ARTI articulo;
	struct PROVEEDOR provX, provY, provMax;
	int I, J, size;
	FILE *DB;
	
	if ( !(DB = fopen("BDARTICULOS", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDARTICULOS");
		exit(1);
	};
	
	//tomamos el tamaño de la base de datos
	fseek(DB, 0, SEEK_END);
	size = ftell(DB) / sizeof(articulo);
	rewind(DB);
	
	
	//comparar provA vs provB, si son iguales sus string FAB, sumar 1 al acumulador de cantidad;
	for (I = 0; I < size; I++) {
		fseek(DB, I * sizeof(articulo), SEEK_SET);
		fread(&articulo, sizeof(articulo), 1, DB);
	
		strcpy(provX.FAB, articulo.FAB);
		provX.CANTIDAD = 0;
		
		for (J = 0; J < size - 1; J++) {
			fseek(DB, J * sizeof(articulo), SEEK_SET);
			fread(&articulo, sizeof(articulo), 1, DB);
			strcpy(provY.FAB, articulo.FAB);
			if ( !strcmp(provX.FAB, provY.FAB)) {
				provX.CANTIDAD = provX.CANTIDAD + 1;
			}
		}
		
		if (provX.CANTIDAD > provMax.CANTIDAD) {
			strcpy(provMax.FAB, provX.FAB);
			provMax.CANTIDAD = provX.CANTIDAD;
		}
	}

	printf("\nFABRICANTE CON MAS ARTICULOS: %s - %d", provMax.FAB, provMax.CANTIDAD);
	
	fclose(DB);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
