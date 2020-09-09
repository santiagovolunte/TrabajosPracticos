/*
 * funciones.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Santiago Volunté 1"E"
 */
#include <stdio.h>
#include <stdlib.h>

/** \brief Funcion sumar de num1, num2
     *
     * \param toma primer numero entero
     * \param  toma segundo numero entero
     * \return resultado de la suma de num1, num2
     *
     */
int suma(int num1, int num2) {
	int respuesta;

	respuesta = num1 + num2;

	return respuesta;
}
/** \brief funcion resta variable num1, num2
     *
     * \param toma primer numero entero
     * \param toma segundo numero entero
     * \return resultado de  la resta de num1, num2
     *
     */
int resta(int num1, int num2) {
	int respuesta;

	respuesta = num1 - num2;

	return respuesta;
}
/** \brief funcion division num1/num2
        *
        * \param toma primer numero entero
        * \param toma segundo numero entero
        * \return resultado de la division de num1, num2
        *
        */
float division(int num1, int num2) {
	float respuesta;

	respuesta = ((float)num1) / num2;

	return respuesta;
}
/** \brief funcion multiplicar num1*num2
     *
     * \param toma numero uno entero
     * \param toma numero dos entero
     * \return resultado de la multiplicacion de num1, num2
     *
     */
int multiplicacion(int num1, int num2) {
	int respuesta;
	respuesta = num1 * num2;
	return respuesta;
}
/** \brief factorial de un numero
 *
 * \param toma un numero entero
 * \return resultado del factoreo de num1
 *
 */
int factorial(int num1) {

	int respuesta = 1;

	for (int i = num1; i > 1; i--) {

		respuesta = respuesta * i;
	}

	return respuesta;
}

