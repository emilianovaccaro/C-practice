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
	struct INDEX indice, MAX, MIN, MID;
	short int buscado = 0, encontrado = 0;
	int maxSize = 0, minSize = 0, midSize = 0;
	FILE *DB, *DBINDICE;
	
	if ( !(DBINDICE = fopen("BDINDICE", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDINDICE");
		exit(1);
	};	
	
	if ( !(DB = fopen("BDARTICULOS", "rb"))) {
		printf("\n ERROR EN LA APERTURA DE BDARTICULO");
		exit(1);
	};
	
	//calcular la cantidad de estructuras que hay == maxSize
	fseek(DBINDICE, 0, SEEK_END);
	maxSize = ftell(DBINDICE) / sizeof(indice);
	
	//buscar la ultima estructura (el maximo)
	fseek(DBINDICE, sizeof(indice) * ( maxSize - 1), SEEK_SET);
	fread(&indice, sizeof(indice), 1, DBINDICE);
	MAX = indice;
	//buscar la primer estructura (el minimo)
	fseek(DBINDICE, sizeof(indice) * (0), SEEK_SET);
	fread(&indice, sizeof(indice), 1, DBINDICE);
	MIN = indice;
	//buscar la estructura del medio (size/2)
	fseek(DBINDICE, sizeof(indice) * (maxSize / 2), SEEK_SET);
	fread(&indice, sizeof(indice), 1, DBINDICE);
	MID = indice;
	
	
	printf("\n BUSCAR ARTICULO: ");
	scanf("%d", &buscado);
	
	
	if (buscado <= MAX.ART && buscado >= MIN.ART) {
		while (MIN.ART <= MAX.ART && !encontrado) {
			midSize = (maxSize + minSize) / 2;
			fseek(DBINDICE, sizeof(indice) * midSize, SEEK_SET);
			fread(&indice,  sizeof(indice), 1, DBINDICE);
			MID = indice;
			
			if (buscado == MID.ART) {
				encontrado = 1;
				printf("\n ARTICULO: %d -- POS: %d ", MID.ART, MID.POS);
			}
			
			if (MID.ART > buscado) {
				fseek(DBINDICE, sizeof(indice) * (midSize - 1), SEEK_SET);
				fread(&indice, sizeof(indice), 1, DBINDICE);
				maxSize = midSize - 1;
				MAX = indice;
			} else {
				fseek(DBINDICE, sizeof(indice) * (midSize + 1), SEEK_SET);
				fread(&indice, sizeof(indice), 1, DBINDICE);
				minSize = midSize + 1;
				MIN = indice;
			}
			
			
			printf("\n MIN ART: %d, MAX ART: %d, MID ART: %d", MIN.ART, MAX.ART, MID.ART);
			getchar();
		}
	}
	
	
	if (!encontrado) {
		printf("\n NO SE ENCONTRO EL ARTICULO");
	} else {
		fseek(DB, sizeof(articulo) * MID.POS, SEEK_SET);
		fread(&articulo, sizeof(articulo), 1, DB);
		printf("\n %d %s %s %s %d",
			articulo.ART,
			articulo.COD,
			articulo.DESC,
			articulo.FAB,
			articulo.STOCK
		);
	}
	
	fclose(DBINDICE);
	fclose(DB);
	printf("\n TERMINO EL PROGRAMA");
	return 0;
}
