/*
 * funciones.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Santiago Volunté 1"E"
 */
#include <stdio.h>
#include <stdlib.h>


int suma(int num1, int num2) {
	int respuesta;

	respuesta = num1 + num2;

	return respuesta;
}

int resta(int num1, int num2) {
	int respuesta;

	respuesta = num1 - num2;

	return respuesta;
}

float division(int num1, int num2) {
	float respuesta;

	respuesta = ((float)num1) / num2;

	return respuesta;
}

int multiplicacion(int num1, int num2) {
	int respuesta;
	respuesta = num1 * num2;
	return respuesta;
}

int factorial(int num1) {

	int respuesta = 1;

	for (int i = num1; i > 1; i--) {

		respuesta = respuesta * i;
	}

	return respuesta;
}

