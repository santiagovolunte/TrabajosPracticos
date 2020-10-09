/*
 * ArrayEmployees.c
 *
 *  Created on: 23 sep. 2020
 *      Author: Santiago Volunté
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"

int initEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int findEmpty(Employee *list, int len) {
	int i;
	int retorno = -2;
	if (len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break;
			} else {
				retorno = -1;
			}
		}
	}
	return retorno;
}

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int i;
	int retorno;
	i = findEmpty(list, len);
	if (i != -1) {
		list[i].id = id;
		strcpy(list[i].name, name);
		strcpy(list[i].lastName, lastName);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty = 0;
		retorno = 1;
	} else {
		retorno = -1;
	}

	return retorno;
}

int findEmployeeById(Employee *list, int len, int id) {
	int i;
	int retorno;
	for (i = 0; i < len; i++) {
		if (id == list[i].id && list[i].isEmpty == 0) {
			retorno = i;
			break;
		} else {
			retorno = -1;
		}
	}

	return retorno;
}
int modifyEmployee(Employee *list, int len, int id) {

	int modify;
	int retorno;
	int empleado;

	empleado = findEmployeeById(list, len, id);

	if (empleado != -1) {
		printOneEmployee(list, id, len);
		printf(
				"\nQue dato desea modificar: \n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Nada");
		scanf("%d", &modify);
		system("CLS");

		switch (modify) {
		case 1:
			printf("\nIngrese el nuevo nombre: ");
			utn_getName(list[empleado].name);
			retorno = 0;
			system("CLS");
			break;
		case 2:
			printf("\nIngrese el nuevo apellido: ");
			utn_getName(list[empleado].lastName);
			retorno = 0;
			system("CLS");
			break;
		case 3:
			printf("\nIngrese el nuevo salario: ");
			scanf("%f", &list[empleado].salary);
			retorno = 0;
			system("CLS");
			break;
		case 4:
			printf("\nIngrese el nuevo sector: ");
			list[empleado].sector = getInt();
			retorno = 0;
			system("CLS");
			break;
		case 5:
			retorno = -1;
			break;

		default:
			printf("\nID no encontrado");
			retorno = -1;
			break;
		}
	}
	return retorno;
}
int removeEmployee(Employee *list, int len, int id) {
	int i;
	int decition;
	int retorno = 0;

	i = findEmployeeById(list, len, id);
	if (i != -1) {
		system("CLS");
		printOneEmployee(list, list[i].id, len);
		printf("\nDesea darlo de baja? \n1-Si\n2-No");
		scanf("%d", &decition);
		if (decition == 1) {
			retorno = 0;
			list[i].isEmpty = 1;
		} else {
			retorno = -1;
		}
	} else {
		retorno = -1;
		system("CLS");
		printf("No se encontro en el sistema ese ID\n");
		system("PAUSE");
	}
	return retorno;
}

int sortEmployees(Employee *list, int len, int order) {
	int i;
	int j;
	Employee auxEmployee[len];

	for (i = 0; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			if (order == 1) {
				if (list[i].sector > list[j].sector) {
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				} else if (list[i].sector == list[j].sector
						&& strcmp(list[i].lastName, list[j].lastName) > 0) {
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				}
			} else if (order == 0) {
				if (list[i].sector < list[j].sector) {
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				} else if (list[i].sector == list[j].sector
						&& strcmp(list[i].lastName, list[j].lastName) < 0) {
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				}
			}
		}
	}
	return 0;
}

int printOneEmployee(Employee *list, int id, int size) {
	int i;
	i = findEmployeeById(list, size, id);

	if (i != -1) {
		printf("\nID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR\n");
		printf("%d\t%s\t%s\t%f\t%d", list[i].id, list[i].name, list[i].lastName,
				list[i].salary, list[i].sector);
	} else {
		printf("\nID no encontrado");
	}

	return 0;
}

int printEmployees(Employee *list, int length) {
	int i;

	printf("ID\tNOMBRE\tAPELLIDO\t\tSALARIO\t\tSECTOR\n");
	for (i = 0; i < length; i++) {
		if (list[i].isEmpty == 0) {
			printf("%d\t%s\t%s\t\t%.2f\t\t%d\n", list[i].id, list[i].name,
					list[i].lastName, list[i].salary, list[i].sector);
		}
	}
	return 0;
}

int AverageSalary(Employee *list, int len, float *average,
		float *acumulator) {
	int i;
	int total = 0;
	int richEmployee = 0;

	*acumulator = 0;
	*average = 0;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 0) {
			*acumulator = *acumulator + list[i].salary;
			total++;
		}
	}

	*average = *acumulator / total;
	for (i = 0; i < len; i++) {
		if (list[i].salary > *average) {
			richEmployee++;
		}

	}

	return richEmployee;
}

int getEmployee(Employee *list, int len, int *lastID) {
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int retorno = 0;
	int ID;
	int r;


	if (findEmpty(list, len ) <= -1) {
		printf("No hay lugares Disponibles para nuevos empleados.\n");
		retorno = -1;
	} else
	{
		ID = *lastID + 1;
		printf("Ingrese el nombre del empleado/a:\n");
		utn_getName(name);
		printf("Ingrese el apellido del empleado/a:\n");
		utn_getName(lastName);
		printf("Ingrese el sueldo: \n");
		scanf("%f", &salary);
	    printf("Ingrese el sector: \n");
		scanf("%d", &sector);
	 r=addEmployee(list, len, ID, name, lastName, salary, sector);
		*lastID = ID;
		retorno = 0;
	}
	if (r != -1) {
		system("CLS");
		printf("\nLa carga se realizo de forma exitosa\n");
	} else {
		system("CLS");
		printf("\nNo se ha podido cargar correctamente\n");
	}
	return retorno;
}
