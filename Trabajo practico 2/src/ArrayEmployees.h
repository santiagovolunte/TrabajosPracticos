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
/**
 * \brief	Modify an element of the Employees array
 *  \param	Receive the list of Employees
 *  \param	Receive the size of that list
 *  \return Returns 0 in case of not being able to Print on screen, or 1 if it printed correctly
 */
int getEmployee(Employee *list, int len, int *lastID);
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

/** \brief Calculate the total, average and number of employees who earn more than the average
 *
 * \param list Employee*  array of employee
 * \param len is int Size of  array of employee
 * \return int Return  the number of employees who earn more than average
 *
 */
int AverageSalary(Employee* list, int len, float *average, float *acumulator);
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
/** \brief Search the employee array for an employee by ID
 *
 * \param  list Employee*
 * \param len int Size of the employee array
 * \param ID search
 * \return int Devuelve 0 en caso de OK
 *
 */
int printOneEmployee(Employee* list, int id, int size);
/** \brief Search for an ID in the employee array, if found, it allows modifying its parameters
 *
 * \param list Employee*
 * \param len int Size of the employee array
 * \param id int ID a buscaar
 * \return int Returns 0 in case of having modified something, -1 in case of error
 *
 */
int modifyEmployee(Employee* list, int len, int id);
/** \brief print the content of employees array
*
* \param list Employee*
* \param len int Size of the employee array
* \return int return 0 is everything is fine
*
*/
int printEmployees(Employee* list, int length);
#endif
