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
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int findEmpty(Employee* list, int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief Calcula el total, promedio y cantidad de empleados que ganen mas que el promedio
 *
 * \param list Employee* Puntero al array de empleados
 * \param len int Tamaño del array de empleados
 * \return int Devuelvo la cantidad de empleados que ganan mas que el promedio
 *
 */
int totalAndAverageSalary(Employee* list, int len, float *average, float *acumulator);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
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
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);
#endif
