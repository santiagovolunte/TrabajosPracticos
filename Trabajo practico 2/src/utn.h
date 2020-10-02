/*
 * menu.h
 *
 *  Created on: 9 sep. 2020
 *      Author: Santiago Volute
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param
 * \param
 * \param
 * \return int Devuelve la conversión de caracteres a entero
 *
 */
int unt_getCaracter (char* pResultado, char* mensaje, char* mensajeError,char minimo,char maximo,int reintentos);
/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param
 * \param
 * \param
 * \return int Devuelve la conversión de caracteres a entero
 *
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);
/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param
 * \param
 * \param
 * \return int Devuelve la conversión de caracteres a entero
 *
 */
float utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

int inicializar(int[],int libre,int tam);
/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param void
 * \return int Devuelve la conversión de caracteres a entero
 *
 */
int getInt(void);
/** \brief Calcula el total, promedio y cantidad de empleados que ganen mas que el promedio
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelvo la cantidad de empleados que ganan mas que el promedio
 *
 */
void getChar(char string[51]);

int cargar(int[],int* pos);
