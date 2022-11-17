/*
 * menu.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "menu.h"

///***MENU PRINCIPAL***///
int mostrarMenuPrincipal()
{
	int opcion;

		printf(">>>>> MENU PRINCIPAL <<<<<\n\n");
		printf("1-  >CARGAR ARCHIVO<\n");
		printf("2-  >IMPRIMIR LISTA<\n");
		printf("3-  >ASIGNAR TOTALES<\n");
		printf("4-  >FILTRAR POR TIPO<\n");
		printf("5-  >MOSTRAR COMPRAS<\n");
		printf("6-  >GUARDAR COMPRAS<\n");
		printf("7-  >SALIR<\n");

	utn_getEntero(&opcion, 5," \nIngrese una opcion ","Error, Esa opcion no existe", 1, 7);

	return opcion;
}


///***MENU FILTRAR***///
int  mostrarMenuFiltrarXTipo()
{
	int option;

	printf("***** FILTRAR POR TIPO *****\n\n");
	printf("  1. ADMINISTRACION\n");
	printf("  2. TALLER\n");
	printf("  3. VENTAS\n");
	printf("  4. SALIR\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 4);

	return option;
}
