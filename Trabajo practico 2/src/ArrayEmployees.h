/*
 * ArrayEmployees.h
 *
 *  Created on: 23 sep. 2020
 *      Author: santi
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);
/** \brief Busca a un empleado en el array a través de su id y en caso de encontrarlo devuelve su posición en el array
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int Parametro ingresado por el usuario indicando un ID de un usuario
 * \return int Devuelve la posición en el array del empleado, en caso de no encotnrarlo devuelve -1
 *
 */
int findEmployeeById(Employee* list, int len, int id);
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int findEmpty(Employee* list, int len);
/** \brief Ordena el array de empleados por sector y por apellido, tanto de forma cresciente como decresciente según lo decida el usuario
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param order int Valor que recibe la función por parametro, 1 cresciente, 0 decresciente
 * \return int Devuelve un cero si el orden se realiza
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Toma una cadena de caracteres y la valida para que solamente se ingresen letras
 *
 * \param palabra[30] char Cadena de caracteres a recibir
 * \return void No devuelve nada
 *
 */
void getChar(char palabra[51]);
/** \brief Valida una cadena de caracteres para que solo se ingresen numeros y luego la transforma en un entero
 *
 * \param void No toma nada
 * \return int Devuelve la conversión de caracter a entero
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
int totalAndAverageSalary(Employee* list, int len, float *average, float *acumulator);
/** \brief Elimina un usuario de forma lógica (bandera isEmpty = 1)
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int Valor ingresado por teclado, haciendo referencia al ID del empleado a buscar
 * \return int Devuelve 0 si la baja se hizo de forma exitosa, en el caso contrario devuelve -1
 *
 */
int removeEmployee(Employee* list, int len, int id);
/** \brief Busca en el array de empleados un empleado por ID
 *
 * \param list Employee* Puntero al array de empleados
 * \param id int ID a buscar
 * \param size int Tamaño del array de empleados
 * \return int Devuelve 0 en caso de OK
 *
 */
int printOneEmployee(Employee* list, int id, int size);
/** \brief Busca un ID en el array de empleados en caso de encontrarlo permite modificar sus parametros
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \param id int ID a buscaar
 * \return int Devuelve 0 en caso de haber modificado algo, -1 en caso de error (No se modifico, no se dio de baja)
 *
 */
int modifyEmployee(Employee* list, int len, int id);
/** \brief Imprime el array de empleados que se encuentran dados de alta
 *
 * \param list Employee* Puntero del array de empleados
 * \param int length Tamaño del array de empleados
 * \return int Devuelve un cero cuando termina de imprimir los empleados
 *
 */
int printEmployees(Employee* list, int length);
#endif
