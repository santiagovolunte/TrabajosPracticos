/*
 * utn.h
 *
 *  Created on: 9 sep. 2020
 *      Author: Santiago Volute
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
/** \brief Solicita caracter al usuario
 *
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado
 * \param Mensaje que  le solicitara una letra al usuario
 * \param Mensaje de error en caso de que el usuario haya ingresado algo incorrecto
 * \param Minimo segun el codigo ASCII
 * \param Maximo segun el codigo ASCII
 * \param Cantidad de reintentos que se le da al usuario
 * \return retorna 0  si salio con exito. retorna -1 en cado de error.
 *
 */
int unt_getCaracter (char* pResultado, char* mensaje, char* mensajeError,char minimo,char maximo,int reintentos);
/** \brief Solcita al usuario un numero del tipo int
 *
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado
 * \param Mensaje que  le solicitara el numero al usuario
 * \param Mensaje de error en caso de que el usuario haya ingresado algo incorrecto
 * \param Numero minimo que se debera ingresar
 * \param Numero maximo que se debera ingresar
 * \param Cantidad de reintentos que se le da al usuario
 * \return int Devuelve la conversión de caracteres a entero
 *
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);
/** \brief Solcita al usuario un numero del tipo float
 *
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado
 * \param Mensaje que  le solicitara el numero al usuario
 * \param Mensaje de error en caso de que el usuario haya ingresado algo incorrecto
 * \param Numero minimo que se debera ingresar
 * \param Numero maximo que se debera ingresar
 * \param Cantidad de reintentos que se le da al usuario
 * \return retorna 0  si salio con exito. retorna -1 en cado de error.
 *
 */
float utn_getFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

int inicializar(int[],int libre,int tam);
/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param void (Nada)
 * \return int Devuelve la conversión de caracteres a int
 *
 */
int getInt(void);
/** \brief Toma una cadena de caracteres y la valida para que solamente se ingresen letras
 *
 * \param Strint[51] char Cadena que recibe
 * \return void (Nada)
 *
 */
void utn_getName(char string[51]);

int cargar(int[],int* pos);
int inicializar(int[],int libre,int tam);
