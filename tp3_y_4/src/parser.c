#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	char id[51];
	char nombre[51];
	char horasTrabajadas[51];
	char sueldo[51];
	int retorno = 0;
	Employee* auxEmployee;

	if(pFile!=NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)== 4)
			{
				auxEmployee = (Employee*) employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(ll_add(pArrayListEmployee,auxEmployee)==0)
				{
					retorno = 0;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int retorno= 0;

	    char id[10];
	    char nombre[128];
	    char horasTrabajadas[64];
	    char sueldo[64];
	    Employee auxEmployee;
	    Employee* pAuxEmployee;
	    if(pFile!=NULL && pArrayListEmployee !=NULL)
	    {
	    	do
	    	{
	    		if(fread(&auxEmployee, sizeof(Employee),1,pFile)== 1)
	    		{
	    			sprintf(id,"%d",auxEmployee.id);
	    			strcpy(nombre,auxEmployee.nombre);
	    			sprintf(horasTrabajadas, "%d", auxEmployee.horasTrabajadas);
	    			sprintf(sueldo, "%d", auxEmployee.sueldo);
	    			pAuxEmployee = (Employee*) employee_newParametros(id,nombre,horasTrabajadas,sueldo);
	    			if(ll_add(pArrayListEmployee,pAuxEmployee)== 0)
	    			{
	    				retorno = 1;
	    			}
	    		}
	    	}while(!feof(pFile));
	    }
	    return retorno;
}
