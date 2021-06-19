#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "auxiliar.h"
#include "Controller.h"
#include "parser.h"

static int idMaximoEncontrado(LinkedList* pArrayListEmployee, int* idMaximo);
static int buscarPorId(LinkedList* pArrayListEmployee, int id);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno= 0;
	if(path!=NULL)
	{
		pArchivo=fopen(path,"r");
	}
	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		retorno = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
		printf("Archivo cargado correctamente\n\n");
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno = 0;
	pArchivo = fopen(path,"rb");
	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		retorno = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
		printf("Archivo cargado correctamente\n\n");
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-0;
		Employee* pAuxiliarEmpleado;
		char auxNombre[128];
		int auxHsTrabajadas;
		int sueldo;
		int idAux;
		char auxHsTrabajadasTxt[51];
		char sueldoTxt[51];
		char idAuxTxt[51];

		if(pArrayListEmployee != NULL)
		{
			if(aux_getString(auxNombre,128,"\nIngrese el nombre del Empleado: \n","\nERROR\n",2) == 0 &&
			   aux_getNumeroInt(&auxHsTrabajadas,"Ingrese las horas trabajadas\n", "Valor incorrecto\n",0, 10000,2) == 0 &&
			   aux_getNumeroInt(&sueldo,"Ingrese el sueldo\n", "Valor incorrecto\n",0, 1000000,2) == 0)
			{
				if(ll_len(pArrayListEmployee) == 0)
				{
					idAux = 0;
				}
				else
				{
					idMaximoEncontrado(pArrayListEmployee, &idAux);
					idAux = idAux + 1;

				}
				sprintf(idAuxTxt,"%d",idAux);
				sprintf(auxHsTrabajadasTxt, "%d",auxHsTrabajadas);
				sprintf(sueldoTxt,"%d", sueldo);

				if(employee_newParametros(idAuxTxt,auxNombre,auxHsTrabajadasTxt,sueldoTxt) >= 0)
				{
					pAuxiliarEmpleado = (Employee*)employee_newParametros(idAuxTxt,auxNombre,auxHsTrabajadasTxt,sueldoTxt);
					ll_add(pArrayListEmployee,pAuxiliarEmpleado);

					retorno = 1;
					printf("Empleado creado correctamente con ID %d\n\n", idAux);
				}
			}
		}
		return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int

 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* auxEmployee;
	int indiceEmployee;
	int id;
	char auxNombre[128];
	int auxHsTrabajadas;
	int sueldo;
	char auxHsTrabajadasTxt[51];
	char sueldoTxt[51];
	int confirma;


	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(aux_getNumeroInt(&id,"Ingrese el ID que desea modificar\n","Id incorrecto, reingrese.\n",0,ll_len(pArrayListEmployee), 2)== 0)
		{
			indiceEmployee = buscarPorId(pArrayListEmployee, id);
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,indiceEmployee);
			if(auxEmployee != NULL)
			{
				employee_imprimir(auxEmployee);

				if(!(aux_getString(auxNombre, 128,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
				   !(aux_getNumeroInt(&auxHsTrabajadas,"Ingrese horas trabajadas\n", "Valor incorrecto\n",1, 1000,2)) &&
				   !(aux_getNumeroInt(&sueldo,"Ingrese sueldo\n", "Valor incorrecto\n",1, 1000000,2)))
				{
					if(aux_getNumeroInt(&confirma,"Confirma los cambios? 0=NO 1=SI\n","Opcion incorrecta.Reingrese.\n",0,1, 2)== 0 && confirma == 1)
					{
						sprintf(auxHsTrabajadasTxt, "%d",auxHsTrabajadas);
						sprintf(sueldoTxt,"%d", sueldo);
						employee_setNombre(auxEmployee, auxNombre);
						employee_setHorasTrabajadas(auxEmployee, auxHsTrabajadas);
						employee_setSueldo(auxEmployee,sueldo);
						printf("El empleado fue editado correctamente.\n\n");
					}
					else
					{
						printf("No se ha realizado ningun cambio.\n\n");
					}

					retorno = 1;
				}

			}

		}


	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int indiceEmployee;
	int id;
	int confirma;
	Employee* auxEmployee;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(aux_getNumeroInt(&id,"Ingrese el ID del empleado a eliminar\n","Id incorrecto, reingrese.\n",0,ll_len(pArrayListEmployee), 2)== 0)
		{
			indiceEmployee = buscarPorId(pArrayListEmployee, id);
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,indiceEmployee);
			if(auxEmployee != NULL)
			{
				employee_imprimir(auxEmployee);
				if(aux_getNumeroInt(&confirma,"Confirma los cambios? 0=NO 1=SI\n","Opcion incorrecta.Reingrese.\n",0,1, 2)== 0 && confirma == 1)
				{
					ll_remove(pArrayListEmployee,indiceEmployee);
					employee_delete(auxEmployee);
					printf("Empleado eliminado correctamente\n\n");
				}
				else
				{
					printf("No se ha eliminado ningun empleado.\n\n");
				}
				retorno = 1;
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
  * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int retorno = 0;
	if(pArrayListEmployee != NULL)
	{
		printf("%s%15s%15s%30s\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");
		for(int i=0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmployee= (Employee*)ll_get(pArrayListEmployee,i);
			employee_imprimir(auxEmployee);
		}
		printf("\n\n");
		retorno = 1;
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int opcion;
	if(pArrayListEmployee != NULL)
	{
		if(aux_getNumeroInt(&opcion,"1. Ordenar empleados por Id\n"
    	        					"2. Ordenar empleados por Nombre\n","Opcion incorrecta.Reingrese.\n",1,2, 2)== 0)
		{
			switch(opcion)
			{
				case 1:
					ll_sort(pArrayListEmployee,employee_CompararId,1);
					printf("Empleados ordenados correctamente por ID.\n\n");
					retorno = 1;
					break;
				case 2:
					ll_sort(pArrayListEmployee,employee_CompararNombre,1);
					printf("Empleados ordenados correctamente por Nombre.\n\n");
					retorno = 1;
					break;
			}
		}


	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* auxEmployee;
	FILE* pFile=fopen(path,"w");
	if(pFile!=NULL && pArrayListEmployee !=NULL)
	{
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		for(int i= 0; i < ll_len(pArrayListEmployee); i++)
		{
			auxEmployee=ll_get(pArrayListEmployee,i);
			if(auxEmployee != NULL)
			{
				 fprintf(pFile,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			}
		}
		fclose(pFile);
		printf("Archivo Guardado Correctamente en modo texto.\n\n");
		retorno = 1;
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	    FILE* pFile;
	    pFile=fopen(path,"wb");
	    Employee* auxEmployee;
	    if (pFile!= NULL && pArrayListEmployee !=NULL)
	    {
	        for (int i=0; i<ll_len(pArrayListEmployee); i++)
	        {
	        	auxEmployee=ll_get(pArrayListEmployee,i);
	            fwrite(auxEmployee,sizeof(Employee),1,pFile);
	        }
	        fclose(pFile);
	        printf("Archivo Guardado Correctamente en modo binario.\n\n");
	        retorno = 1;
	    }
	    return retorno;
}


static int idMaximoEncontrado(LinkedList* pArrayListEmployee, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Employee* auxiliarEmployee;
	Employee* auxEmplo;
	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmplo = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmplo,&idAuxiliar);
			if(!flag)
			{
				auxiliarEmployee = ll_get(pArrayListEmployee,i);
				employee_getId(auxiliarEmployee,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}

/**
 * \brief Busca en la lista un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista que será evaluada
 * \param Id. Id del empleado a buscar
 * \return int Devuelve la ubicacion donde se encuentra el id, -1 si no lo encuentra y 0 si hay error
 */
static int buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int retorno=0;
	int i;
	int idAux;
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL && id >= 0)
	{
		retorno = -1;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmpleado, &idAux);
			if( idAux == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
