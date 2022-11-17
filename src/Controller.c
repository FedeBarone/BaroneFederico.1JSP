/*
 * Controller.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "input.h"
#include "menu.h"
#include "controller.h"
#include "eCompras.h"

/****CARGAR ARCHIVO COMPRAS *******/
int controller_cargarComprasDesdeTexto(char* path , LinkedList* pArrayListCompra)//Check
{
	int retorno = -1;
	FILE* pFile;
	pFile = fopen(path, "r");
	if(pFile!= NULL)
	{
	  if(parser_CompraFromText(pFile , pArrayListCompra)== 0)
	  {
		  printf("Archivo de texto cargado con exito\n");
		  retorno = 0;

	  }
	  else
	  {
		  printf("Error en el parser\n");
	  }
	}
	else
	{
		printf("Error NULL\n");
	}
	fclose(pFile);
	return retorno;
}


/****IMPRIMIR LISTA COMPRAS *******/
int controller_listarCompras(LinkedList* pArrayListCompra)//Check
{
	int retorno = compra_printAll(pArrayListCompra);
    return retorno;
}





/****FILTRADAS COMPRAS**////
int controller_filter(LinkedList* pArrayListCompra)
{
	int retorno = -1;
	char continuar = 's';
	char confirmar;
	LinkedList* listaFiltrada = NULL;

		do{
			switch(mostrarMenuFiltrarXTipo())
			{
					case 1:
							listaFiltrada = ll_filter(pArrayListCompra, compras_filtrarAdministracion);
							if(controller_guardarModoTexto("comprasFiltradas.csv", listaFiltrada)== 0)
							{
								printf("Lista guardada con exito!\n");
							}
							controller_listarCompras(listaFiltrada);
					  break;
					case 2:
							listaFiltrada = ll_filter(pArrayListCompra, compras_filtrarTaller);
							if(controller_guardarModoTexto("comprasFiltradas.csv", listaFiltrada)== 0)
							{
								printf("Lista guardada con exito!\n");
							}
							controller_listarCompras(listaFiltrada);
					 break;
					case 3:
							listaFiltrada = ll_filter(pArrayListCompra, compras_filtrarVentas);
							if(controller_guardarModoTexto("comprasFiltradas.csv", listaFiltrada)== 0)
							{
								printf("Lista guardada con exito!\n");
							}
							controller_listarCompras(listaFiltrada);
					 break;
					case 4:
							printf("\n\n\n---EXIT--- \n\n\n ");
							printf("Esta seguro que desea salir? [s/n]: ");
							fflush(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
							 continuar = 'n';
							}
						break;
				default:
					printf("No es una opcion valida \n");

				}

			}while(continuar == 's');

			//controller_listarCompras(listaFiltrada);

	return retorno;
}


int controller_guardarModoTexto(char* path , LinkedList* pArrayListCompras)
{
	int retorno = -1;

	FILE* pFile;
	int auxCodigoCompra;
	char auxDescripcion[100];
	int auxOrigen;
	int auxPrecioUnitario;
	int auxCantidad;
	float auxTotalCompra;
	eCompras* pCompra;


	if(pArrayListCompras != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 1; i < ll_len(pArrayListCompras); i++)//por cada elemento del array lo escribo en el archivo, desde la pos 1
			{
				pCompra = ll_get(pArrayListCompras, i);
				//utilizo los getter para traerme la info
				if(!compra_getCodigoCompra(pCompra, &auxCodigoCompra) &&
				   !compra_getDescripcion(pCompra, auxDescripcion) &&
				   !compra_getOrigen(pCompra, &auxOrigen) &&
				   !compra_getPrecioUnitario(pCompra, &auxPrecioUnitario) &&
				   !compra_getCantidad(pCompra, &auxCantidad) &&
				   !compra_getTotalCompra(pCompra, &auxTotalCompra))

				{
					fprintf(pFile, "%d,%s,%d,%d,%d,%.2f\n", auxCodigoCompra, auxDescripcion, auxOrigen, auxPrecioUnitario, auxCantidad, auxTotalCompra);
				}
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
		}//if fpArchivo NULL
	}//if NULL

    return retorno;
}


/***MAPEO***////
int controller_map(LinkedList* pArrayListCompra)
{
	int retorno = -1;

	pArrayListCompra = ll_map(pArrayListCompra, compra_totalCompra);
	if(pArrayListCompra != NULL)
	{
		controller_listarCompras(pArrayListCompra);
		retorno = 0;
	}

	return retorno;
}


/***ORDENAR COMPRAS*****/
int controller_ordenarCompras(LinkedList* pArrayListCompra)//Check
{
	int retorno = -1;

		if(pArrayListCompra != NULL)
		{
			if(compra_ordenar(pArrayListCompra) == 0)
			{
				printf("Compras ordenadas por descripcion exitosamente.\n");
			}
		}
		else
		{
			printf("Error\n");
		}

	    return retorno;
}



int controller_guardarOrdenamientoModoTexto(char* path , LinkedList* pArrayListCompras)
{
	int retorno = -1;

	FILE* pFile;
	int auxCodigoCompra;
	char auxDescripcion[100];
	int auxOrigen;
	int auxPrecioUnitario;
	int auxCantidad;
	float auxTotalCompra;
	eCompras* pCompra;


	if(pArrayListCompras != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 1; i < ll_len(pArrayListCompras); i++)//por cada elemento del array lo escribo en el archivo, desde la pos 1
			{
				pCompra = ll_get(pArrayListCompras, i);
				//utilizo los getter para traerme la info
				if(!compra_getCodigoCompra(pCompra, &auxCodigoCompra) &&
				   !compra_getDescripcion(pCompra, auxDescripcion) &&
				   !compra_getOrigen(pCompra, &auxOrigen) &&
				   !compra_getPrecioUnitario(pCompra, &auxPrecioUnitario) &&
				   !compra_getCantidad(pCompra, &auxCantidad) &&
				   !compra_getTotalCompra(pCompra, &auxTotalCompra))

				{
					fprintf(pFile, "%d,%s,%d,%d,%d,%.2f\n", auxCodigoCompra, auxDescripcion, auxOrigen, auxPrecioUnitario, auxCantidad, auxTotalCompra);
				}
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
		}//if fpArchivo NULL
	}//if NULL

    return retorno;
}
