#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "funciones.h"
#define OPCIONES 5

int main(void)
{

		setbuf(stdout, NULL);

		int opcion;
		float valorA;
		float valorB;
		float Suma;
		float Resta;
		float Multiplicacion;
		float Division;
		float FactorialA;
		float FactorialB;

		do
		{

			if(aux_getNumeroInt(&opcion, "\nIngrese una opcion"
					"\n1. 1. Ingresar 1er operando (A=x)"
					"\n2. Ingresar 2do operando (B=y)"
					"\n3. Calcular todas las operaciones"
					"\n4. Informar resultados"
					"\n5. Salir\n", "Opcion Invalida", 1, OPCIONES, 3)==0)
			{
				switch (opcion)
				{
				case 1:
					printf("Ingrese el valor de A\n");
					scanf("%f", &valorA);
					printf("El valor de A es: %f\n",valorA);
					break;

				case 2:
					printf("Ingrese el valor de B\n");
					scanf("%f", &valorB);
					printf("El valor de B es: %f\n",valorB);
					break;

				case 3:
					printf("Se realizaron todas las operaciones.\n\n");
					func_CalcularSuma(&Suma, valorA, valorB);
					func_CalcularResta(&Resta, valorA, valorB);
					func_CalcularMultiplicacion(&Multiplicacion, valorA, valorB);
					if(valorB!=0)
					{
						func_CalcularDivision(&Division, valorA, valorB);
					}
					func_CalcularFactorial(&FactorialA, valorA);
					func_CalcularFactorial(&FactorialB, valorB);
					break;
				case 4:
					printf("\nLa suma de %f y %f es : %f\n", valorA, valorB, Suma);
					printf("\nLa resta de %f y %f es: %f\n",valorA, valorB, Resta);
					printf("\nLa multiplicacion de %f y %f es : %f", valorA, valorB, Multiplicacion);
					if(valorB==0)
					{
						printf("\nNo se puede dividir por 0\n\n");
					}else
					{
					printf("\n\nLa division de %f y %f es : %f\n", valorA, valorB, Division);
					}
					printf("\nEl factorial de %f es %f\n", valorA, FactorialA);
					printf("\nEl factorial de %f es %f\n\n", valorB, FactorialB);
					break;
				}
			}



		}while(opcion!=5);

			return EXIT_SUCCESS;
}
