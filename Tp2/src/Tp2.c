/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "Employee.h"

#define MAX_EMPLEADOS 1000
int main(void) {
	setbuf(stdout,NULL);
	Employee listEmployee[MAX_EMPLEADOS];
	int opcion;
	int idEmployee = 0;
	Employee bufferEmployee;
	if(emp_initEmployees(listEmployee, MAX_EMPLEADOS) == 0)
	{
		do{
			if(!aux_getNumeroInt(	&opcion,
					"\n\n1.   Alta Empleado"
					"\n2.   Modificar Empleado"
					"\n3.   Baja Empleado"
					"\n4.   Informes"
					"\n5.   Salir\n\n",
					"\nError, opcion no valida. Reingrese",1,5,2) )
			{
				switch(opcion)
				{
				case 1:
					if(aux_getString(bufferEmployee.name,51,"\nIngrese el nombre del Empleado: \n","\nERROR\n",2) == 0 &&
						aux_getString(bufferEmployee.lastName,51,"\nIngrese el apellido del Empleado: \n","\nERROR\n",2) == 0 &&
						aux_getNumeroFlotante(&bufferEmployee.salary, "Ingrese el salario\n","Error, ingrese nuevamente \n", 0, 10000, 3) == 0 &&
						aux_getNumeroInt(&bufferEmployee.sector, "Ingrese el sector: \n","\nERROR\n", 1, 10000,3) == 0)
					{
						if(emp_addEmployee(listEmployee,MAX_EMPLEADOS,idEmployee,bufferEmployee.name,bufferEmployee.lastName,bufferEmployee.salary,bufferEmployee.sector) == 0)
						{
							idEmployee++;
							printf("Empleado agregado\n");
						}
						else
						{
							printf("\nERROR");
						}
					}
						break;
				case 2:
					if(emp_hasData(listEmployee,MAX_EMPLEADOS) == 0)
					{
						if(emp_modificarArray(listEmployee,MAX_EMPLEADOS,idEmployee) == 0)
						{
							printf("\Empleado Modificado\n");
						}
						else
						{
							printf("\nERROR");
						}
					}
					else
					{
						printf("\nNo hay datos de empleados\n");
					}
					break;
				case 3:
					if(emp_hasData(listEmployee,MAX_EMPLEADOS) == 0)
					{
						if(emp_removeEmployee(listEmployee,MAX_EMPLEADOS,idEmployee) == 0)
						{
							printf("\nEmpleado Eliminado\n");
						}
						else
						{
							printf("\nERROR");
						}
					}
					else
					{
						printf("\nNo hay datos de empleados\n");
					}
					break;
				case 4:
					if(emp_hasData(listEmployee,MAX_EMPLEADOS) == 0)
					{
						printf("Seleccione el informe a imprimir:");
						do
						{
							if(aux_getNumeroInt(&opcion,
								"\n\n1.  Listado de los empleados"
								"\n2.   Total y promedio de los salarios, y cuántos empleados superan el salario promedio"
								"\n3.   Salir",
								"\nError, opcion no valida. Reingrese",1,3,2)== 0 )
							{
								switch(opcion)
								{
								case 1:
									if(emp_sortEmployees(listEmployee, MAX_EMPLEADOS, 0) == 0)
									{
										emp_printEmployees(listEmployee,MAX_EMPLEADOS);
									}
									else
									{
										printf("\nERROR");
									}
									break;
								case 2:
									if(emp_Sueldos(listEmployee, MAX_EMPLEADOS) != 0)
									{
										printf("\nERROR");
									}
									break;
								}
							}
						}while(opcion != 3);
						break;
					}
					else
					{
						printf("\nNo hay datos de empleados\n");
					}
					break;
				}
			}
		}while(opcion != 5);
	}


	return EXIT_SUCCESS;
}
