#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#include "Employee.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int emp_initEmployees(Employee* list, int len)
{
	int respuesta = -1;
		int i;
		if(list != NULL && len > 0)
			{
				respuesta = 0;
				for(i=0;i<len;i++)
				{
					list[i].isEmpty = 1;
				}
			}
		return respuesta;
}


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */

int emp_addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int respuesta = -1;
	int indice = -1;
	Employee bufferEmployee;
	if(list != NULL && len > 0)
	{
		indice = emp_getEmptyIndex(list,len);
		if(len > 0 && indice < len && indice >= 0)
		{
			respuesta = 0;
			bufferEmployee.id = id;
			bufferEmployee.isEmpty = 0;
			strncpy(bufferEmployee.name,name,51);
			strncpy(bufferEmployee.lastName,lastName,51);
			bufferEmployee.salary = salary;
			bufferEmployee.sector = sector;
			list[indice] = bufferEmployee;
		}
	}
	return respuesta;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int emp_findEmployeeById(Employee* list, int len,int id)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == 0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Modifica los datos de un Empleado
 * \param array. Puntero a al array de Empleado
 * \param limite. Cantidad maxima de posiciones del array
 * \param clienteId. Id del Empleado a modificar
 * \return Retorna 0 si semodifica el Empleado correctamente y -1 si ocurre algun error
 *
 */
int emp_modificarArray(Employee* list,int length, int employeeId)
{
	int respuesta = -1;
	int indice = -1;
	int auxclienteId = -1;
	Employee bufferEmployee;
	if(list != NULL && length > 0 )
	{
		emp_printEmployees(list,length);
		if(aux_getNumeroInt(&auxclienteId,"\nIndique el ID del Empleado a modificar\n","\nID invalido. Reingrese\n",0,length,3) == 0)
		{
			indice = emp_findEmployeeById(list,length,auxclienteId);
			if(	indice < length && indice >= 0 && list[indice].isEmpty == 0)
			{
				if(	aux_getString(bufferEmployee.name,51,"\nIngrese el nombre del Empleado: \n","\nERROR\n",2) == 0 &&
						aux_getString(bufferEmployee.lastName,51,"\nIngrese el apellido del Empleado: \n","\nERROR\n",2) == 0 &&
						aux_getNumeroFlotante(&bufferEmployee.salary, "Ingrese el salario\n","Error, ingrese nuevamente \n", 0, 10000, 3) == 0 &&
						aux_getNumeroInt(&bufferEmployee.sector, "Ingrese el sector: \n","\nERROR\n", 1, 10000,3) == 0)
				{
					respuesta = 0;
					bufferEmployee.id = list[indice].id;
					bufferEmployee.isEmpty = 0;
					list[indice] = bufferEmployee;
				}
			}
		}
	}
	return respuesta;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int emp_removeEmployee(Employee* list, int len, int id)
{
	int respuesta = -1;
	int auxclienteId = -1;
	int indice = -1;
	if(list != NULL && len > 0 )
	{
		emp_printEmployees(list,len);
		if(aux_getNumeroInt(&auxclienteId,"\nIndique el ID del Empleado a eliminar","\nID invalido",0,id-1,2)==0)
		{
			indice = emp_findEmployeeById(list,len,auxclienteId);
			if(indice < len && indice >= 0 && list[indice].isEmpty == 0)
			{
				if( emp_EliminarPorEmpleadoId(list,len, indice) == 0)
				{
					respuesta = 0;
				}
			}
		}
	}
	return respuesta;
}

/**
 * \brief Elimina un Empleado del array
 * \param list. Puntero a al array de Empleados
 * \param limite. Cantidad maxima de posiciones del array
 * \param indice. Posicion del Empleado en el array
 * \return Retorna 0 si elimina el empleado correctamente y -1 si ocurre algun error
 *
 */
int emp_EliminarPorEmpleadoId(Employee* list,int limite, int indice)
{
	int respuesta = -1;
	if(list != NULL && limite > 0 && indice < limite && indice >= 0 && list[indice].isEmpty == 0)
	{
		list[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int emp_sortEmployees(Employee* list, int len, int order)
{
	int respuesta = -1;
	Employee bufferEmployee;
	if(list != NULL && len > 0)
	{
		respuesta = 0;
		for (int i = 0; i < len-1; i++)
		{
			for (int j = i; j < len; j++)
			{
				if(order == 1)
				{
					if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
					{
						if (strcmp(list[i].lastName, list[j].lastName) == 0)
						{
							if(list[i].sector > list[j].sector)
							{
								bufferEmployee = list[j];
								list[j] = list[i];
								list[i] = bufferEmployee;
							}
						}
						else if(strcmp(list[i].lastName, list[j].lastName) > 0)
						{
							bufferEmployee = list[j];
							list[j] = list[i];
							list[i] = bufferEmployee;
						}
					}
				}
				else if(order == 0)
				{
					if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
					{
						if (strcmp(list[j].lastName, list[i].lastName) == 0)
						{
							if(list[i].sector > list[j].sector)
							{
								bufferEmployee = list[j];
								list[j] = list[i];
								list[i] = bufferEmployee;
							}
						}
						else if(strcmp(list[j].lastName, list[i].lastName) > 0)
						{
							bufferEmployee = list[j];
							list[j] = list[i];
							list[i] = bufferEmployee;
						}
					}
				}
			}
		}
	}
	return respuesta;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int emp_printEmployees(Employee* list, int length)
{
	int respuesta = -1;
	int i;
	if(list != NULL && length > 0)
	{
		respuesta = 0;
		printf("ID - Nombre - Apellido - Salario - Sector");
			for(i=0;i<length;i++)
			{
					emp_imprimir(&list[i]);
			}
	}
	return respuesta;
}

/** \brief Imprime el contenido de un empleado
 *
 * \param list Employee*
 * \return int
 *
 */
int emp_imprimir(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\n %d - %s - %s - %.2f - %i ",pElemento->id,pElemento->name,pElemento->lastName,pElemento->salary, pElemento->sector);
		}
	return retorno;
}


/** \brief Encuentra un indice vacio en el array
 *
 * \param list Employee*
 * \param length int
 * \return int -1 si hay error, y sino el numero de indice encotrado
 *
 */
int emp_getEmptyIndex(Employee* list,int length)
{
	int respuesta = -1;
	int i;
	if(list != NULL && length > 0)
	{
		for(i=0;i<length;i++)
			{
				if(list[i].isEmpty == 1)
					{
						respuesta = i;
						break;
					}
			}
	}
	return respuesta;
}

/** \brief Verifica si el array tiene datos
 *
 * \param list Employee*
 * \param length int
 * \return -1 si no hay empleados y 0 si hay
 *
 */
int emp_hasData(Employee* list,int length)
{
	int respuesta = -1;
	int i;
	if(list != NULL && length > 0)
	{
		for(i=0;i<length;i++)
			{
				if(list[i].isEmpty == 0)
					{
						respuesta = 0;
						break;
					}
			}
	}
	return respuesta;
}


/** \brief Calcula e imprime el total de sueldos, promedio de sueldos y cantidad de empleados que cobran mas que el promedio
 *
 * \param list Employee*
 * \param length int
 * \return -1 si hay error o 0 si sale ok
 *
 */
int emp_Sueldos(Employee list[], int len)
{
	int respuesta = -1;
    float total = 0;
    int contador=0;
    int contador2=0;
    float promedio;

    if(list != NULL && len > 0)
    {
    	respuesta = 0;
    	for(int i = 0; i < len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
				total += list[i].salary;
			}
		}
		promedio = total / contador;

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > promedio)
			{
				contador2++;
			}
		}
		printf("El total de salarios es: %.2f\n",total);
		printf("El salario promedio es: %.2f\n",promedio);
		printf("Los empleados que superan el salario promedio son: %d\n",contador2);
    }
    return respuesta;
}


