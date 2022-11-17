/*
 * parser.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eCompras.h"



/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_CompraFromText(FILE* pFile , LinkedList* pArrayListCompra)//Parser listo
{
		int cantidadFscanf;
		int retorno = -1;
		char codigoCompra[150];
		char descripcion[150];
		char origen[150];
		char precioUnitario[150];
		char cantidad[150];
		char totalCompra[150];

		eCompras* pCompra;
		pCompra = NULL;

		if(pFile != NULL && pArrayListCompra != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
			while(!feof(pFile))
			{
				cantidadFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);//Cortamos cadena en pedacitos

				if(cantidadFscanf == 6)//imprime mientras cantidad devuelva 6
				{
					pCompra = compra_newParametros(codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
					if(pCompra!= NULL)
					{
						ll_add(pArrayListCompra, pCompra);
					}
					retorno = 0;
					//printf("%s-%s-%s-%s-%s-%s\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
				}
				else
				{
					compra_delete(pCompra);
					pCompra = NULL;
				}
			}
		}
	    return retorno;
}
