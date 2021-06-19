#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opc;

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");
    scanf("%d",&opc);

    return opc;
}

int menuModify()
{
    int opc;

    printf("\nBienvenido al menu de modificacion!\n\n");
    printf("1.Nombre.\n");
    printf("2.Sueldo.\n");
    printf("3.Horas trabajadas.\n");
    printf("Ingrese la opcion: ");
    scanf("%d",&opc);

    return opc;
}
