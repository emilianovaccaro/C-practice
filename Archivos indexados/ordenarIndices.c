#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct INDEX {
	short int ART; // de menor a mayor, segun el valor numerico de ART
	int POS;
};

int main () {
	struct INDEX indice, indiceB;
	int I, J, size;
	FILE *DB;
	
	if ( !(DB = fopen("BDINDICE", "r+b"))) {
		printf("\n ERROR EN LA APERTURA DE INDICES");
		exit(1);
	};
	
	fseek(DB, 0, SEEK_END);
	size = ftell(DB) / sizeof(indice);
	
	for (I=0; I < size; I++) {
		for (J=0; J < size - I - 1; J++) {
			fseek(DB, J * sizeof(indice), SEEK_SET);
			fread(&indice, sizeof(indice), 1, DB); //la primer lectura en indice
			//la ventana de lectura me queda en el inicio de la proxima struct
			fread(&indiceB, sizeof(indice), 1, DB); //lee y guarda en indiceB;
			
			if (indice.ART > indiceB.ART) {
				fseek(DB, J * sizeof(indice), SEEK_SET);
				fwrite(&indiceB, sizeof(indice), 1, DB);
				fwrite(&indice, sizeof(indice), 1, DB);
			}
		}
	}

	fclose(DB);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
