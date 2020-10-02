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
#include "utn.h"
#include "ArrayEmployees.h"
#define QTY_EMPLOYEES 1000

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	Employee list[QTY_EMPLOYEES];
	int flag = 0;
	int r;
	char name[51];
	char lastName[51];
	int sector;
	float salary;
	int ID;
	int idContador = 0;
	int d = 0;
	int ordenar;
	float acumulator = 0;
	float average = 0;
	int informar;

	r = initEmployees(list, QTY_EMPLOYEES);
	if (r != 0) {
		printf("El programa inicia con normalidad.");
		system("pause");
		system("CLS");
	}
	do {

		if (utn_getNumero(&opcion,
				"\n1-ALTAS \n2-MODIFICAR\n3- BAJA\n4-INFORMAR",
				"Error ingrese un numero valido", 1, 4, 3) == 0) {
			switch (opcion) {
			case 1:
				flag = 1;
				system("pause");
				system("CLS");
				printf("Ingrese el nombre del empleado/a:\n");

				getChar(name);

				printf("Ingrese el apellido del empleado/a:\n");
				getChar(lastName);

				printf("Ingrese el sueldo: \n");
				fflush(stdin);
				scanf("%f", &salary);

				printf("Ingrese el sector: \n");
				fflush(stdin);
				scanf("%d", &sector);

				idContador++;
				ID = idContador;

				r = addEmployee(list, QTY_EMPLOYEES, ID, name, lastName,
						salary, sector);
				if (r != -1) {
					system("CLS");
					printf("\nLa carga se realizo de forma extitosa\n");
				} else {
					system("CLS");
					printf("\nNo se ha podido cargar correctamente\n");
				}
				break;

			case 2:
				if (flag == 1) {

					system("PAUSE");
					system("CLS");
					printEmployees(list, QTY_EMPLOYEES);
					printf("Ingrese el id del empleado que desea modificar: ");
					scanf("%d", &ID);

					system("CLS");
					modifyEmployee(list, QTY_EMPLOYEES, ID);
				}

				else {
					printf("Error, antes debe ingresar un empleado");
				}
				break;

			case 3:
				if (flag == 1) {
					system("PAUSE");
					system("CLS");
					r = printEmployees(list, QTY_EMPLOYEES);
					if (r != -1) {
						printf("\nIngrese el id que desea dar de baja: ");
						scanf("%d", &ID);
						r = removeEmployee(list, QTY_EMPLOYEES, ID);
						if (r != -1) {
							system("CLS");
							printf("Baja exitosa\n");
						} else {
							system("CLS");
							printf("No se dio de baja\n");
						}
					}
				}

				else {
					printf("Error, antes debe ingresar un empleado");
				}
				break;
			case 4:
				if (flag == 1) {
					system("CLS");
					utn_getNumero(&informar,"\n1 - 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n0 -2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. " , "ERROR, ingrese un numero valido", 1,
							2, 2);
					switch (informar){
					case 1:
					printf(
							"\n - Si desea infomar de manera cresciente ingrese '1' \n-Si desea infomar de manera decresciente ingrese '0'");
					scanf("%d", &ordenar);
					system("CLS");
					r = sortEmployees(list, QTY_EMPLOYEES, ordenar);
					r = printEmployees(list, QTY_EMPLOYEES);
					break;
					case 2:
					d = totalAndAverageSalary(list, QTY_EMPLOYEES, &average,
							&acumulator);
					printf(
							"\nSueldos totales: %.2f\nPromedio de sueldos: %.2f\n-Personas que ganan mas que el promedio: %d",
							acumulator, average, d);
					break;
				}
				}
				else {
					printf("Error antes debe ingresar un empleado");
				}
				break;

			}
		}

	} while (opcion != 27);

	return 0;
}
