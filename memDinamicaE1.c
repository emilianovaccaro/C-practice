#include <stdio.h>
#include <stdlib.h>

//Escribir un programa que lea un numero de teclado,
//que indica cuantos numeros enteros ingresara el usuario.

//Crear el vector para almacenar el tamaño exacto de los datos
//y leer los enteros que seran guardados en el vector "dinamico"

//informar el promedio de los datos ingresados;


int main () {
  int I;
  int quantity;
  float acumulador = 0;

  printf("\nEnter quantity of grades: ");
  scanf("%d", &quantity);

  int gradesVector[quantity];
  int* gradesPointer;

  gradesPointer = (int*) malloc(quantity * sizeof(gradesVector));

  for (I=0; I < quantity; I++) {
    float value;

    printf("\nEnter grade of person %d :", (I+1));
    scanf("%f", &value);

    *(gradesPointer+I) = value;
    acumulador = acumulador + value;
  }

  for (I=0; I < quantity; I++) {
    printf("\n Student %d :", (I+1));
    printf(" %d", gradesPointer[I]);
  }

  printf("\n Total students average: %.2f", acumulador/quantity);

  free(gradesPointer);
  gradesPointer = 0;

  return 0;
}
