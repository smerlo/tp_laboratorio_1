


#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "auxiliar.h"
#include <string.h>

/**
 * \brief Reserva un espacio en memoria para guardar un empleado
 * \param Void (No recibe nada en los parametros)
 * \return Retorna un puntero al espacio de memoria donde guardará el empleado
 */
Employee* employee_new(void)
{
	Employee* aux = NULL;
	aux = malloc(sizeof(Employee));
	return aux;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* aux = NULL;
	aux = employee_new();
	if(aux != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(aux_verificarNumerica(idStr, 10) == 0 && aux_verificarNumerica(horasTrabajadasStr, 10) == 0 && aux_verificarNumerica(sueldoStr, 10) == 0)
		{
			if(employee_setId(aux, atoi(idStr)) == 1 &&
				employee_setNombre(aux, nombreStr) == 1 &&
				employee_setHorasTrabajadas(aux, atoi(horasTrabajadasStr)) == 1 &&
				employee_setSueldo(aux, atoi(sueldoStr)) == 1)
			{
				return aux;
			}
			else
			{
				employee_delete(aux);
			}
		}
	}
	return NULL;
}

int employee_setId(Employee* this, int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int employee_imprimir(Employee* this)
{
	int retorno=0;
	int id;
	int hsTrabajadas;
	int sueldo;
	char nombre[128];
	if(this != NULL)
	{
		retorno = 1;
		employee_getId(this,&id);
		employee_getNombre(this,nombre);
		employee_getSueldo(this,&sueldo);
		employee_getHorasTrabajadas(this,&hsTrabajadas);
		printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d\n",id,nombre,hsTrabajadas,sueldo);
	}
	return retorno;
}

int employee_CompararId(void* compareOne,void* compareTwo)
{
	int retorno = 0;
	Employee* auxOne;
	Employee* auxTwo;
	auxOne = (Employee*) compareOne;
	auxTwo = (Employee*) compareTwo;
	if(auxOne->id>auxTwo->id)
	{
		retorno = 1;
	}
	else if(auxOne->id<auxTwo->id)
	{
		retorno = -1;
	}
	return retorno;
}

int employee_CompararNombre(void* compareOne,void* compareTwo)
{
	int retorno = 0;
		Employee* auxOne;
		Employee* auxTwo;
		auxOne = (Employee*)compareOne;
		auxTwo = (Employee*)compareTwo;
		if(auxOne != NULL && auxTwo != NULL)
		{
			if(strncmp(auxOne->nombre,auxTwo->nombre,128)>0)
			{
				retorno = -1;
			}
			else if(strncmp(auxOne->nombre,auxTwo->nombre,128) < 0)
			{
				retorno = 1;
			}
		}
		return retorno;
}
