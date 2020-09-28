/*
 * ArrayEmployees.c
 *
 *  Created on: 23 sep. 2020
 *      Author: Santiago Volunté
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"

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
	int flag;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 1) {
			flag = i;
			break;
		} else {
			flag = -1;
		}
	}
	return flag;
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
	int flag;
	for (i = 0; i < len; i++)
			{
		if (id == list[i].id && list[i].isEmpty == 0)
				{
			flag = i;
			break;
		} else {
			flag = -1;
		}
	}

	return flag;
}

int removeEmployee(Employee *list, int len, int id) {
	int i;
	int decition;
	int flag = 0;

	i = findEmployeeById(list, len, id);
	if (i != -1)
			{
		system("CLS");
		printOneEmployee(list, list[i].id, len);
		printf("\nDesea darlo de baja? \n1-Si\n2-No\nUsted ingreso: ");
		if (decition == 1)
				{
			flag = 0;
			list[i].isEmpty = 1;
		} else {
			flag = -1;
		}
	} else {
		flag = -1;
		system("CLS");
		printf("No se encontro en el sistema ese ID\n");
		system("PAUSE");
	}
	return flag;
}

int sortEmployees(Employee *list, int len, int order) {
	int i;
	int j;
	Employee auxEmployee[len];

	for (i = 0; i < len - 1; i++)
			{
		for (j = i + 1; j < len; j++)
				{
			if (order == 1)
					{
				if (list[i].sector > list[j].sector)
						{
					auxEmployee[i] = list[i]; // Swap de variable
					list[i] = list[j]; // Swap de variable
					list[j] = auxEmployee[i]; //Swap de variable
				} else if (list[i].sector == list[j].sector
						&& strcmp(list[i].lastName, list[j].lastName) > 0)
								{
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				}
			} else if (order == 0)
					{
				if (list[i].sector < list[j].sector)
						{
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				} else if (list[i].sector == list[j].sector
						&& strcmp(list[i].lastName, list[j].lastName) < 0)
								{
					auxEmployee[i] = list[i];
					list[i] = list[j];
					list[j] = auxEmployee[i];
				}
			}
		}
	}
	return 0;
}

int printEmployees(Employee *list, int length) {
	int i;

	printf("ID\tNOMBRE\tAPELLIDO\t\tSALARIO\t\tSECTOR\n");
	for (i = 0; i < length; i++)
			{
		if (list[i].isEmpty == 0)
				{
			printf("%d\t%s\t%s\t\t%.2f\t\t%d\n", list[i].id, list[i].name,
					list[i].lastName, list[i].salary, list[i].sector);
		}
	}
	return 0;
}

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	int numero;
	int retorno;

	do {
		printf(mensaje);
		fflush(stdin);
		scanf("%d", &numero);

		if (numero >= minimo && numero <= maximo) {
			retorno = 0;
			*pResultado = numero;
			break;
		} else {
			reintentos--;
			printf(mensajeError);
			fflush(stdin);
		}

	} while (reintentos > 0);

	if (reintentos == 0) {
		retorno = -1;
	}
	return retorno;
}

void getChar(char string[51]) {
	int state = 1;
	int state2 = 1;
	int size;
	int i;

	fflush(stdin);
	gets(string);
	size = strlen(string);

	if (size >= 51) {
		state = 0;
	} else {
		state = 1;
	}

	do {
		if (state == 0)
				{
			printf("\n\nReingrese la palabra: ");
			gets(string);
			size = strlen(string);
			if (size >= 51) {
				state = 0;
			} else {
				state = 1;
			}
		}
		if (state == 1) {
			for (i = 0; i < size; i++)
					{
				state = isalpha(string[i]);
			}
			for (i = 0; i < size; i++)
					{
				state2 = isdigit(string[i]);
			}
		}
	} while (state == 0 || state2 != 0);
}

int getInt(void) {
	char number[30];
	int numberI;
	int size;
	int state = 0;
	int i;

	fflush(stdin);
	gets(number);
	size = strlen(number);

	do {
		if (state != 0 || size >= 30) {
			printf("Invalido, reingrese un numero: ");
			gets(number);
			size = strlen(number);
		}
		for (i = 0; i < size; i++) {
			state = isalpha(number[i]);

			if (number[i] == '.' || number[i] == ',')
					{
				state = 1;
				break;
			}
		}

	} while (state != 0);

	numberI = atoi(number);
	return numberI;
}

int totalAndAverageSalary(Employee *list, int len, float *average,
		float *acumulator) {
	int i;
	int c = 0;
	int d = 0;
	*acumulator = 0;
	*average = 0;

	for (i = 0; i < len; i++) {
		if (list[i].isEmpty == 0)
				{
			*acumulator = *acumulator + list[i].salary;
			c++;
		}
	}

	*average = *acumulator / c;
	for (i = 0; i < len; i++) {
		if (list[i].salary > *average)
				{
			d++;
		}

	}

	return d;
}

int printOneEmployee(Employee *list, int id, int size) {
	int i;
	i = findEmployeeById(list, size, id);

	if (i != -1)
			{
		printf("\nID\tNOMBRE\tAPELLIDO\tSALARIO\tSECTOR\n");
		printf("%d\t%s\t%s\t%f\t%d", list[i].id, list[i].name, list[i].lastName,
				list[i].salary, list[i].sector);
	} else {
		printf("\nID no encontrado");
	}

	return 0;
}
int modifyEmployee(Employee *list, int len, int id) {

	int modify;
	int flag;
	int index;

	index = findEmployeeById(list, len, id);

	if (index != -1)
			{
		printOneEmployee(list, id, len);
		printf(
				"\nQue dato desea modificar: \n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Nada");
		scanf("%d", &modify);
		system("CLS");
		if (modify == 1)
				{

			printf("\nIngrese el nuevo nombre: ");
			getChar(list[index].name);
			flag = 0;
			system("CLS");
		} else if (modify == 2)
				{
			printf("\nIngrese el nuevo apellido: ");
			getChar(list[index].lastName);
			flag = 0;
			system("CLS");
		} else if (modify == 3)
				{
			printf("\nIngrese el nuevo salario: ");
			scanf("%f", &list[index].salary);
			flag = 0;
			system("CLS");
		} else if (modify == 4)
				{
			printf("\nIngrese el nuevo sector: ");
			list[index].sector = getInt();
			flag = 0;
			system("CLS");
		} else if (modify == 5)
				{
			flag = -1;
		}
	} else {
		printf("\nID no encontrado");
		flag = -1;
	}

	return flag;
}
