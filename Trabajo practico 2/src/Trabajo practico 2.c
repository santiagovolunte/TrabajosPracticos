/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Santiago_Volunté
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define QTY_EMPLOYEES 1000

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int flag = 0;
	int r;
	char name[51];
	char lastName[51];
	int sector;
	float salary;
	int ID;
	int idContador = 0;
	int add;
	int d=0;
	int sort;
	float acumulator = 0;
	float average=0;
	Employee list[QTY_EMPLOYEES];

	r = initEmployees(list, QTY_EMPLOYEES);
	if (r != 0) {
		printf("El programa inicia con normalidad.");
		system("pause");
		system("CLS");
	}
	do {

		if (utn_getInt(&opcion,
				"\n1-ALTAS \n2-MODIFICAR\n3- BAJA\n4-INFORMAR\n5- SALIR",
				"Error ingrese un numero valido", 1, 5, 3) == 0) {
			switch (opcion) {
			case 1:
				flag = 1;
				system("pause");
				system("CLS");
				idContador++;
				ID = idContador;
				printf("Ingrese el nombre del empleado/a:\n");
				getChar(name);
				printf("Ingrese el apellido del empleado/a:\n");
				getChar(lastName);
				printf("Ingrese el sueldo: \n");
				scanf("%f", &salary);
				printf("Ingrese el sector: \n");
				scanf("%d", &sector);
				add = addEmployee(list, QTY_EMPLOYEES, ID, name, lastName,
						salary, sector);
				if (add != -1) {
					system("CLS");
					printf("\nLa carga se realizo con exito\n");
				} else {
					system("CLS");
					printf("\nNo se ha podido cargar correctamente\n");
				}
				break;

			case 2:
				if (flag == 1) {
					printf("\ncaso 2");
					system("pause");

					printf("\nEn proceso: "); // Impresion por pantalla del mensaje
					system("PAUSE"); // Pausamos la ejecución del programa
					system("CLS"); // Limpiamos pantalla
					add = printEmployees(list, QTY_EMPLOYEES); // Llamamos a la función "printEmployees" pasandole el array de empleados y el tamaño del mismo, el valor devuelto lo guardamos en la variable "control"
					printf("Ingrese el id que desea modificar: "); // Impresion por pantalla del mensaje
					scanf("%d", &ID); // Guardamos el valor ingresado por teclado en la variable id
					system("CLS"); // Limpiamos pantalla
					modifyEmployee(list, QTY_EMPLOYEES, ID);
				}

				else {
					printf("Error antes debe ingresar un empleado");
				}
				break;

			case 3:
				if (flag == 1) {
					printf("En proceso: "); // Impresion por pantalla del mensaje
					system("PAUSE"); // Pausamos la ejecución del programa
					system("CLS"); // Limpiamos pantalla
					add = printEmployees(list, QTY_EMPLOYEES); // Llamamos a la funcion "printEmployees" pasandole como valores el array de empleados y el tamaño del mismo, el valor devuelto lo guardamos en la vriable "control"
					if (add != -1) // En caso que el valor de control sea distinto a -1 ejecutamos el sigueinte bloque de código
							{
						printf("\nIngrese el id que desea dar de baja: "); // Impresion por pantalla del mensaje
						scanf("%d", &ID); // Guardamos el valor ingresado por teclado en la variable id
						add = removeEmployee(list, QTY_EMPLOYEES, ID); // Llamamos a la función "removeEmployee" pasandole como valores el array de empleados, el tamaño del mismo y el id que deseamos eliminar del sistema, el valor devuelto lo guardamos en la variable "control"
						if (add != -1) // En caso que el valor de control sea distinto a -1 ejecutamos el sigueinte bloque de código
								{
							system("CLS"); // Limpiamos pantalla
							printf("Baja exitosa\n"); // Impresion por pantalla del mensaje
						} else {
							system("CLS"); // Limpiamos pantalla
							printf("No se dio de baja\n"); // Impresion por pantalla del mensaje
						}
					}
				}

				else {
					printf("Error antes debe ingresar un empleado");
				}
				break;
			case 4:
				if (flag == 1) {
					system("CLS"); // Limpiamos pantalla
					printf(
							"\nDesea imprimirlos de forma \n1 - Cresciente\n0 - Decresciente"); // Impresion por pantalla del mensaje
					scanf("%d", &sort); // Guardamos el valor ingresado por teclado en la variable sort
					system("CLS"); // Limpiamos pantalla
					add = sortEmployees(list, QTY_EMPLOYEES, sort); // Llamamos a la funcion "sortEmployees" para ordenar el array de empleados, el valor devuelto lo guardamos en la variable "control"
					add = printEmployees(list, QTY_EMPLOYEES); // Llamamos a la funcion "printEmployees" parar imprimir todos los usuarios dados de alta (isEmpty = 0), el valor devuelto lo guardamos en la variable "control"
					d = totalAndAverageSalary(list, QTY_EMPLOYEES, &average,
							&acumulator); // Llamamos a la función "totalAndAverageSalary" para calcular, el total de los salarios, el promedio y cuantos empleados ganan mas que el promedio
					printf(
							"\nSueldos totales: %f\nPromedio de sueldos: %f\nPersonas que ganan mas que el promedio: %d",
							acumulator, average, d); // Imprimimos por pantalla los valores
				}

				else {
					printf("Error antes debe ingresar un empleado");
				}
				break;

			case 5:
				break;
			}
		}

	} while (opcion != 5);

	return 0;
}
