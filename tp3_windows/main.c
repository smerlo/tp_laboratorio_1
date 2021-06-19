#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "auxiliar.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	aux_getNumeroInt(&option,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    	        						  "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
    	        						  "3. Alta de empleado\n"
    	        						  "4. Modificar datos de empleado\n"
    	        						  "5. Baja de empleado\n"
    	        						  "6. Listar empleados\n"
    	        						  "7. Ordenar empleados\n"
    	        						  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
    	        						  "9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n"
    	        						  "10. Salir\n",
    	    							  "Opción inválida\n",
    	    							  1,10,2);
        switch(option)
        {

			case 1:
				if(controller_loadFromText("data.csv",listaEmpleados) == 0)
				{
					printf("Hubo un error, intente nuevamente.\n");
				}
				break;
			case 2:
				if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
				{
					printf("Hubo un error, intente nuevamente.\n");
				}
				break;
			case 3:
				if(controller_addEmployee(listaEmpleados) == 0)
				{
					printf("Hubo un error, intente nuevamente.\n");

				}
				break;
			case 4:
				if(controller_editEmployee(listaEmpleados) == 0)
				{
					printf("Hubo un error, intente nuevamente.\n");
				}
				break;
			case 5:
				if(controller_removeEmployee(listaEmpleados) == 0)
				{
					printf("Hubo un error, intente nuevamente.\n");
				}
				break;
			case 6:
				if(controller_ListEmployee(listaEmpleados)== 0)
				{
					printf("Hubo un error, intente nuevamente.\n");
				}
				break;
			case 7:
				if(controller_sortEmployee(listaEmpleados) == 0)
				{
					printf("Hubo un error, intente nuevamente.\n");
				}
				break;
			case 8:
				if(controller_saveAsText("data.csv",listaEmpleados))
				{
					printf("Se guardo correctamente (csv).\n");
					system("pause");
				}
				system("cls");
				break;
			case 9:
				if(controller_saveAsBinary("data.bin",listaEmpleados))
				{
					printf("Se guardo correctamente (bin).\n");
					system("pause");
				}
				system("cls");
				break;
        }
    }while(option != 10);
    return 0;
}

