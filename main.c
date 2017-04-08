#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void reiniciarFlag(int a, int b);
int main()
{
    char seguir='s';
    int opcion=0;
    int flagA = 0;
    int flagB = 0;
    float a = 0;
    float b = 0;


    while(seguir=='s')
    {

        if(flagA == 0)
            printf("1- Ingresar 1er operando (A=x)\n");
        else
            printf("1- Ingresar 1er operando (A=%.2f)\n",a);
        if(flagB == 0)
            printf("2- Ingresar 2do operando (B=y)\n");
        else
            printf("2- Ingresar 2do operando (B=%.2f)\n",b);

        if(flagA == 0 && flagB== 0)
        {
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
        }
        else
        {
        printf("3- Calcular la suma (%.2f+%.2f)\n",a,b);
        printf("4- Calcular la resta (%.2f-%.2f)\n",a,b);
        printf("5- Calcular la division (%.2f/%.2f)\n",a,b);
        printf("6- Calcular la multiplicacion (%.2f*%.2f)\n",a,b);
        }

        if(a==0)
            printf("7- Calcular el factorial (A!)\n");
        else
            printf("7- Calcular el factorial (%.2f!)\n",a);

        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingrese el 1er operando: \n");
                scanf("%f",&a);
                flagA= 1;
                break;
            case 2:
                system("cls");
                printf("Ingrese el 2do operando: \n");
                scanf("%f",&b);
                flagB= 1;
                break;
            case 3:
                suma(a,b);
                reiniciarFlag(flagA,flagB);
                break;
            case 4:
                resta(a,b);
                reiniciarFlag(flagA,flagB);
                break;
            case 5:
                division(a,b);
                reiniciarFlag(flagA,flagB);
                break;
            case 6:
                multiplicacion(a,b);
                reiniciarFlag(flagA,flagB);
                break;
            case 7:
                factorial(a);
                reiniciarFlag(flagA,flagB);
                break;
            case 8:
                suma(a,b);
                resta(a,b);
                division(a,b);
                multiplicacion(a,b);
                factorial(a);
                reiniciarFlag(flagA,flagB);
                break;
            case 9:
                seguir = 'n';
                break;
        }



    }
return 0;
}

void reiniciarFlag(int a, int b)
{
    a = 0;
    b = 0;

    return;
}
