/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Santiago_Volunté 1 E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);
	int num1;
	int num2;
	int opcion;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMul;
	float resultadoDiv;
	int resultadoFac;
	int resultadoFac2;
	int flagA = 0;
	int flagB = 0;
    int flagC = 0;

	do {
		if (flagA == 0) {
			printf("1- Ingrese 1er operando: A \n");
		} else if (flagA == 1) {
			printf("1- Ingrese 1er operando: %d  \n", num1);
		}

		if (flagB == 0) {
			printf("\n2- Ingrese 2do operando: B \n");
		} else if (flagB == 1) {
			printf("2- Ingrese 2do operando: %d  \n", num2);
		}

		printf("\n3- Calcular todas las operaciones:");
		printf(
				"\n a) Calcular la suma (A+B) \n b) Calcular la resta (A-B) \n c) Calcular la division (A/B) \n d) Calcular la multiplicacion (A*B) \n e) Calcular el factorial (A!)\n");
		printf("\n4- Informar resultados\n ");
		printf("\n5- Salir \n");

		printf("\n\nSeleccione una opcion: ");
		scanf("%d", &opcion);

		switch (opcion) {
		case 1:
			system("cls");
			printf("1- Ingrese 1er operando: ");
			scanf("%d", &num1);
			flagA = 1;
			system("pause");
			break;

		case 2:
			system("cls");
			printf("2- Ingrese 2do operando: \n");
			scanf("%d", &num2);
			flagB = 1;
			system("pause");
			break;

		case 3:
			if(flagA==1 && flagB==1){
			system("cls");
			printf("\nCalculando...\nPresione 4 para ver los resutlados\n");
			resultadoSuma = suma(num1, num2);
			resultadoResta = resta(num1, num2);
			resultadoDiv = division(num1, num2);
			resultadoMul = multiplicacion(num1, num2);
			resultadoFac = factorial(num1);
			resultadoFac2 = factorial(num2);
			flagC= 1;
			system("pause");

			}
			else{
				printf("Debe ingresar dos numeros antes de calcular \n");
			}
			break;
		case 4:
			if(flagA==1 && flagB==1){
				if (flagC==1){
			system("cls");
			printf("\n4- Resultados: \n ");
			printf("\na) El resultado de %d + %d es: %d", num1, num2,
					resultadoSuma);
			printf("\nb) El resultado de %d - %d es: %d", num1, num2,
					resultadoResta);
			if (num2 == 0) {
				printf("\nc)No es posible dividir por 0");
			} else {
				printf("\nc) El resultado de %d/%d es: %.2f", num1, num2,
						resultadoDiv);
			}

			printf("\nd) El resultado de %d*%d es: %d", num1, num2,
					resultadoMul);

			if (num1 >= 0) {
				printf("\ne) Elfactorial de %d es: %d",
						num1, resultadoFac);
			} else {
				printf("\ne)No se puede factorizar %d por ser un valor negativo",num1);
			}
			if (num2 >= 0) {
				printf(" y el resultado del factorial de %d es: %d\n",
						num2, resultadoFac2);
			} else {
				printf(
						"\n, no se puede factorizar %d por ser un valor negativo\n\n",num2);
			}

			system("pause");}
				else{
					printf("\n Debe calcular antes de mostrar los resultados\n");
				}
				}
			else{printf("Debe ingresar dos numeros antes de calcular \n");}
			break;

		case 5:
			break;

		default:
			system("cls");
			printf("Error!!! Ingrese un dato valido. \n");
			system("pause");
		}

	} while (opcion != 5);

	return 0;
}
