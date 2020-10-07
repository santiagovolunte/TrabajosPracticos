/*
 * utn.c
 *
 *  Created on: 9 sep. 2020
 *      Author: Santiago Volunté
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"

int unt_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	int retorno = -1;
	char buffer;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);

			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}

		} while (reintentos >= 0);

	}

	return retorno;
}
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	int numero;
	int retorno;

	while (reintentos > 0) {
		printf(mensaje);
		fflush(stdin);
		if (scanf("%d", &numero) == 1) {
			if (numero >= minimo && numero <= maximo) {
				break;
			} else {
				reintentos--;
				printf(mensajeError);
				fflush(stdin);
			}
		}
	}
	if (reintentos == 0) {
		retorno = -1;
	} else {
		retorno = 0;
		*pResultado = numero;
	}
	return retorno;
}
float utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {
	float numero;
	int retorno;

	while (reintentos > 0) {
		printf(mensaje);
		fflush(stdin);
		if (scanf("%f", &numero) == 1) {
			if (numero >= minimo && numero <= maximo) {
				break;
			} else {
				reintentos--;
				printf(mensajeError);
				fflush(stdin);
			}
		}
	}
	if (reintentos == 0) {
		retorno = -1;
	} else {
		retorno = 0;
		*pResultado = numero;
	}
	return retorno;
}
int getInt(void) {
	char number[30];
	int numberI;
	int size;
	int state = 0;
	int i;

	fflush(stdin);
	gets(number);
	size = strlen(number);

	do {
		if (state != 0 || size >= 30) {
			printf("Invalido, reingrese un numero: ");
			gets(number);
			size = strlen(number);
		}
		for (i = 0; i < size; i++) {
			state = isalpha(number[i]);

			if (number[i] == '.' || number[i] == ',') {
				state = 1;
				break;
			}
		}

	} while (state != 0);

	numberI = atoi(number);
	return numberI;
}

void utn_getName(char string[51]) {
	int state = 1;
	int state2 = 1;
	int size;
	int i;

	fflush(stdin);
	gets(string);
	size = strlen(string);

	if (size >= 51) {
		state = 0;
	} else {
		state = 1;
	}

	do {
		if (state == 0) {
			printf("\nReingrese la palabra: ");
			gets(string);
			size = strlen(string);
			if (size >= 51) {
				state = 0;
			} else {
				state = 1;
			}
		}
		if (state == 1) {
			for (i = 0; i < size; i++) {
				state = isalpha(string[i]);
			}
			for (i = 0; i < size; i++) {
				state2 = isdigit(string[i]);
			}
		}
	} while (state == 0 || state2 != 0);
}
int inicializar(int v[], int libre, int tam) {
	int i, retorno = -1;

	for (i = 0; i < tam; i++) {
		v[i] = libre;
		retorno = 0;
	}

	return retorno;
}


int cargar(int v[], int *pos) {
	int retorno = -1;
	char aux;
	do {
		printf("Ingrese posicion");
		scanf("%d", pos);

		printf("Ingrese valor a cargar en el vector");
		scanf("%d", &v[*pos]);

		printf("Desea ingresar otro dato s/n?");
		fflush(stdin);
		retorno = 0;
		scanf("%c", &aux);
	} while (aux == 's');

	return retorno;
}

