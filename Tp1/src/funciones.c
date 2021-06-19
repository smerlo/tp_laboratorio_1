/*
 * funciones.c
 *
 *  Created on: Apr 11, 2021
 *      Author: linuxmint
 */
#include <stdio.h>
#include <stdlib.h>


/**
 * \brief 	Calcula la suma entre dos valores ingresados por el usuario
 * \param resultado Puntero al espacio de memoria donde se guardara el resultado de la suma
 * \param primerOperando Valor ingresado para calcular la suma
 * \param segundoOperando Valor ingresado para calcular la suma
 * \return Retorna 0 si pudo hacer la suma, y -1 si no
 *
 */
int func_CalcularSuma(float* resultado, float primerOperando, float segundoOperando)
{
	int retorno = -1;
	int suma;
	if(resultado != NULL)
	{
		suma = primerOperando + segundoOperando;
		*resultado = suma;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief 	Calcula la resta entre dos valores ingresados por el usuario
 * \param resultado Puntero al espacio de memoria donde se guardara el resultado de la resta
 * \param primerOperando Valor ingresado para calcular la resta
 * \param segundoOperando Valor ingresado para calcular la resta
 * \return Retorna 0 si pudo hacer la resta, y -1 si no
 *
 */
int func_CalcularResta(float* resultado, float primerOperando, float segundoOperando)
{
	int retorno = -1;
	int resta;
	if(resultado != NULL)
	{
		resta = primerOperando - segundoOperando;
		*resultado = resta;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief 	Calcula la division entre dos valores ingresados por el usuario. Verifica que el divisor no sea 0
 * \param resultado Puntero al espacio de memoria donde se guardara el resultado de la division
 * \param primerOperando dividendo para la operacion
 * \param segundoOperando divisor para la operacion
 * \return Retorna 0 si pudo hacer la division, y -1 si no
 *
 */
int func_CalcularDivision(float* resultado, float primerOperando, float segundoOperando)
{
	int retorno = -1;
	int division;
	if(resultado != NULL)
	{
		if(segundoOperando != 0)
		{
			division = primerOperando / segundoOperando;
			*resultado = division;
			retorno = 0;
		}
		else
		{
			printf("No se puede dividir por 0");
		}

	}
	return retorno;
}

/**
 * \brief 	Calcula la multiplicacion entre dos valores ingresados por el usuario
 * \param resultado Puntero al espacio de memoria donde se guardara el resultado de la multiplicacion
 * \param primerOperando Valor ingresado para calcular la multiplicacion
 * \param segundoOperando Valor ingresado para calcular la multiplicacion
 * \return Retorna 0 si pudo hacer la multiplicacion, y -1 si no
 *
 */
int func_CalcularMultiplicacion(float* resultado, float primerOperando, float segundoOperando)
{
	int retorno = -1;
	int multiplicacion;
	if(resultado != NULL)
	{
		multiplicacion = primerOperando * segundoOperando;
		*resultado = multiplicacion;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief 	Calcula el factorial de un numero
 * \param resultado Puntero al espacio de memoria donde se guardara el resultado del factorial
 * \param primerOperando Valor ingresado para calcular su factorial
 * \return Retorna 0 si pudo hacer la operacion, y -1 si no
 *
 */
int func_CalcularFactorial(float* resultado, float numero)
{
	int retorno = -1;
	float factorial = numero;
	if(resultado != NULL)
	{
		for(int i = 1; i < numero; i++)
		{
			factorial *= (numero - i);
			*resultado = factorial;
		}
		retorno = 0;
	}
	return retorno;
}
