/*
 ============================================================================
 Name        : 2doParcial-Labo.c
 Author      : Federico Barone 1ero J
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"
#include "parser.h"
#include "input.h"


int main()
{
	setbuf(stdout,NULL);

	char continuar = 's';
	char confirmar;
	int flagTexto = 0;
	int flagOrdenar = 0;

	LinkedList* listaCompras = ll_newLinkedList();


		do
		{
			switch(mostrarMenuPrincipal())
			{

			case 1:
						flagTexto = 1;
						controller_cargarComprasDesdeTexto("data.csv", listaCompras);//Check
				break;
			case 2:
						if(flagTexto == 1)
						{
							controller_listarCompras(listaCompras);//Check
						}
						else
						{
							printf("DEBE CARGAR EL ARCHIVO\n");
						}
				break;
			case 3:
						if(flagTexto == 1)
						{
							controller_map(listaCompras);//Check
						}
						else
						{
							printf("DEBE CARGAR EL ARCHIVO\n");
						}
				break;
			case 4:
						if(flagTexto == 1)
						{
							controller_filter(listaCompras);//Check
						}
						else
						{
							printf("DEBE CARGAR EL ARCHIVO\n");
						}
				break;
			case 5:
						if(flagTexto == 1)
						{
							controller_ordenarCompras(listaCompras);//Check
							flagOrdenar = 1;
						}
						else
						{
							printf("DEBE CARGAR EL ARCHIVO\n");
						}

				break;
			case 6:
						if(flagTexto == 1 && flagOrdenar == 1)
						{
							controller_guardarOrdenamientoModoTexto("compraOrdenada.csv" , listaCompras);//Check
						}
						else
						{
							printf("DEBE ORDENAR\n");
						}
				break;
			case 7:
					printf("\n\n\n---EXIT--- \n\n\n ");
					printf("Esta seguro que desea salir? [s/n]: ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{
					 continuar = 'n';
					}
				break;
			 default :
				printf("ERROR...Vuelva a elegir una opcion\n");
			}

		}while(continuar == 's');

    return 0;
}
