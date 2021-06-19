/*
 * auxiliar.h
 *
 *  Created on: Apr 11, 2021
 *      Author: linuxmint
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_

int aux_getNumeroFlotante(float* pResultado, char* mensaje, char* Error, float minimo, float maximo, int reintentos);
int aux_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);



#endif /* AUXILIAR_H_ */
