/*
 ============================================================================
 Name        : TpCalculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"
#include "funciones.h"
#define MINIMO -1000
#define MAXIMO 1000
#define OPCIONES 6

int main(void) {

	float primerOperando = 0;
	float segundoOperando = 0;
	int opcion = -1;
	float resultado;


	if(aux_getNumeroFlotante(&primerOperando, "Ingrese el Primer operando\n","Error, ingrese nuevamente \n", MINIMO, MAXIMO, 3) == 0
		&& aux_getNumeroFlotante(&segundoOperando, "Ingrese el Segundo operando\n","Error, ingrese nuevamente \n", MINIMO, MAXIMO, 3) == 0)
	{
		if(aux_getNumeroInt(&opcion, "\nIngrese una opcion"
				"\n1. Calcular Suma (A+B)"
				"\n2. Calcular Resta (A-B)"
				"\n3. Calcular Division (A/B)"
				"\n4. Calcular Multiplicacion (A*B)"
				"\n5. Calcular Factorial (A!, B!)"
				"\n6. Salir\n", "Opcion Invalida", 1, OPCIONES, 3) == 0)
		{
			switch(opcion)
			{
				case 1:
					if(func_CalcularSuma(&resultado, primerOperando, segundoOperando) == 0)
					{
						printf("\nLa suma de A+B es: %.2f", resultado);
					}
					break;
				case 2:
					if(func_CalcularResta(&resultado, primerOperando, segundoOperando) == 0)
					{
						printf("\nLa resta de A-B es: %.2f", resultado);
					}
					break;
				case 3:
					if(func_CalcularDivision(&resultado, primerOperando, segundoOperando) == 0)
					{
						printf("\nLa division de A/B es: %.2f", resultado);
					}
					break;
				case 4:
					if(func_CalcularMultiplicacion(&resultado, primerOperando, segundoOperando) == 0)
					{
						printf("\nLa multiplicacion de A*B es: %.2f", resultado);
					}
					break;
				case 5:
					if(func_CalcularFactorial(&resultado, primerOperando) == 0)
					{
						printf("\nEl factorial de A es: %.2f", resultado);
					}
					if(func_CalcularFactorial(&resultado, segundoOperando) == 0)
					{
						printf("\nEl factorial de B es: %.2f", resultado);
					}
					break;
			}
		}
	}
	return EXIT_SUCCESS;
}
