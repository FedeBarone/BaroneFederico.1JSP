/*
 * eCompras.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eCompras.h"
#include "input.h"
#include "menu.h"
#include "controller.h"

////******SETTERS Y GETTERS******////
int compra_setCodigoCompra(eCompras* this, int codigoCompra)//Setter
{
	int retorno = -1;
	if(this != NULL && codigoCompra > 0)
	{
		this->codigoCompra = codigoCompra;
		retorno = 0;
	}

	return retorno;
}


int compra_getCodigoCompra(eCompras* this, int* codigoCompra)//Getter
{
	int retorno = -1;
	if(this != NULL && codigoCompra > 0)
	{
		*codigoCompra = this->codigoCompra;
		retorno = 0;
	}

	return retorno;
}

int compra_setDescripcion(eCompras* this, char* descripcion)//Setter
{
	int retorno = -1;
	if(this != NULL)
	{
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}

	return retorno;
}

int compra_getDescripcion(eCompras* this, char* descripcion)//Getter
{
	int retorno = -1;
	if(this != NULL)
	{
		strcpy(descripcion, this->descripcion);
		retorno = 0;
	}

	return retorno;
}


int compra_setOrigen(eCompras* this, int origen)//Setter
{
	int retorno = -1;

		if(this != NULL && origen > 0)
		{
			this->origen = origen;
			retorno = 0;
		}

		return retorno;
}


int compra_getOrigen(eCompras* this, int* origen)//Getter
{
	int retorno = -1;
		if(this != NULL && origen > 0)
		{
			*origen = this->origen;
			retorno = 0;
		}

		return retorno;
}


int compra_setPrecioUnitario(eCompras* this, int precioUnitario)//Setter
{
	int retorno = -1;
		if(this != NULL && precioUnitario> 0)
		{
			this->precioUnitario = precioUnitario;
			retorno = 0;
		}

		return retorno;
}


int compra_getPrecioUnitario(eCompras* this, int* precioUnitario)//Getter
{
	int retorno = -1;
		if(this != NULL && precioUnitario != NULL)
		{
			*precioUnitario = this->precioUnitario;
			retorno = 0;
		}

		return retorno;
}


int compra_setCantidad(eCompras* this, int cantidad)//Setter
{
	int retorno = -1;
	if(this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		retorno = 0;
	}

	return retorno;

}


int compra_getCantidad(eCompras* this, int* cantidad)//Getter
{
	int retorno = -1;
		if(this != NULL && cantidad != NULL)
		{
			*cantidad = this->cantidad;
			retorno = 0;
		}

		return retorno;

}


int compra_setTotalCompra(eCompras* this, float totalCompra)//Setter
{
	int retorno = -1;
		if(this != NULL)
		{
			this->totalCompra = totalCompra;
			retorno = 0;
		}

		return retorno;

}


int compra_getTotalCompra(eCompras* this, float* totalCompra)//Getter
{
	int retorno = -1;
		if(this != NULL && totalCompra != NULL)
		{
			*totalCompra = this->totalCompra;
			retorno = 0;
		}

		return retorno;

}


////*****CONSTRUCTORES******////
eCompras* compra_new()
{
	eCompras* pCompra;
	pCompra = (eCompras*)malloc(sizeof(eCompras));
	if(pCompra != NULL)
	{
	 compra_setCodigoCompra(pCompra, 0);
	 compra_setDescripcion(pCompra, "\0");
	 compra_setOrigen(pCompra, 0);
	 compra_setPrecioUnitario(pCompra, 0);
	 compra_setCantidad(pCompra, 0);
	 compra_setTotalCompra(pCompra, 0);
	}
	return pCompra;
}


eCompras* compra_newParametros(char* codigoCompra,char* descripcion,char* origen, char* precioUnitario, char* cantidad, char* totalCompra)
{
	eCompras* pCompra;
	pCompra = compra_new();

	if(pCompra != NULL)
	{
	   if(compra_setCodigoCompra(pCompra, atoi(codigoCompra))!= 0||
		  compra_setDescripcion(pCompra, descripcion)!= 0||
		  compra_setOrigen(pCompra, atoi(origen))!= 0||
		  compra_setPrecioUnitario(pCompra, atof(precioUnitario))!= 0||
		  compra_setCantidad(pCompra, atoi(cantidad))!= 0||
		  compra_setTotalCompra(pCompra,atof(totalCompra))!= 0)
		{
			compra_delete(pCompra);
			pCompra= NULL;
		}
	}

	return pCompra;
}

////*****DESTRUCTOR*****////
int compra_delete(eCompras* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}

	return retorno;

}


////******IMPRIMIR****////
int compra_print(eCompras* This)
{
	int retorno = -1;
	int auxCodigoCompra;
	char auxDescripcion[100];
	//int auxOrigen;
	int auxPrecioUnitario;
	int auxCantidad;
	float auxTotalCompra;
	char nombre[100];
	cargarNombreOrigen(nombre, This->origen);


	if(This != NULL)
	{
			if(compra_getCodigoCompra(This, &auxCodigoCompra) == 0 &&
			   compra_getDescripcion(This, auxDescripcion)==0 &&
			   //compra_getOrigen(This, &auxOrigen) == 0 &&
			   compra_getPrecioUnitario(This, &auxPrecioUnitario) == 0 &&
			   compra_getCantidad(This, &auxCantidad) == 0 &&
			   compra_getTotalCompra(This, &auxTotalCompra) == 0)
			{
				printf("|%-20d|%-25s|%-25s|%-25d|%-18d|%-18.2f|\n", auxCodigoCompra, auxDescripcion, nombre, auxPrecioUnitario, auxCantidad, auxTotalCompra);
				printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
				retorno = 0;
			}
			else
			{
				printf("Ocurrió un error muy grave\n");
			}
		}
	return retorno;
}


int compra_printAll(LinkedList* pArrayListCompra)
{
    eCompras* auxCompra = compra_new();
    int retorno = -1;
    int i;
    int len = ll_len(pArrayListCompra);
    int anchoColumnaCodigoCompra = -20;
	int anchoColumnaDescripcion = -25;
	int anchoColumnaOrigen = -25;
	int anchoColumnaPrecioUnitario = -25;
	int anchoColumnaCantidad = -18;
	int anchoColumnaTotalCompra = -18;

    	  printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+------------------+\n");
    	  printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n", anchoColumnaCodigoCompra, " Codigo Compra", anchoColumnaDescripcion,
    	         "Descripcion", anchoColumnaOrigen, "Origen", anchoColumnaPrecioUnitario, "Precio Unitario", anchoColumnaCantidad, "Cantidad", anchoColumnaTotalCompra, "Total Compra");
    	  printf("+--------------------+-------------------------+-------------------------+-------------------------+------------------+------------------+\n");

    if(auxCompra != NULL && len > 0)
    {
        for (i = 0; i < len; i++)
        {
            auxCompra = ll_get(pArrayListCompra, i);
            retorno = compra_print(auxCompra);
        }
    }
    return retorno;
}


///***ORDENAMIENTO***///
int compra_ordenar(LinkedList* pArrayListCompra)
{
	int retorno = -1;
	int orden;

	if(pArrayListCompra!= NULL)
	{
		//descripcion
		utn_getEntero(&orden, 2, "1 ascendente o 0 descendente: ", "Error\n", 0, 1);
		printf("Espere unos segundos, por favor.\n");
		ll_sort(pArrayListCompra, compra_ordenarXDescripcion, orden);
		controller_listarCompras(pArrayListCompra);
		retorno = 0;
	}
	return retorno;
}


int compra_ordenarXDescripcion(void* pCompraUno, void* pCompraDos)
{
	int retorno = 0;//si son iguales
	char descripcionUno[100];
	char descripcionDos[100];

	compra_getDescripcion(pCompraUno,  descripcionUno);
	compra_getDescripcion(pCompraDos,  descripcionDos);

	if(strcmp(descripcionUno, descripcionDos) > 0)//el primero es mayor
	{
		retorno = 1;
	}
	else if(strcmp(descripcionUno, descripcionDos) < 0)// el primero es menor
	{
		retorno = -1;
	}
	return retorno;
}

///****FILTRAR*****///
int compras_filtrarAdministracion(void* pElement)
{
	int auxReturn = 0;
	eCompras* auxCompras = (eCompras*) pElement;

	if(pElement != NULL)
	{
		auxCompras = (eCompras*) pElement;

		if(auxCompras->origen == 1)
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}


int compras_filtrarTaller(void* pElement)
{
	int auxReturn = 0;
	eCompras* auxCompras = (eCompras*) pElement;

	if(pElement != NULL)
	{
		auxCompras = (eCompras*) pElement;

		if(auxCompras->origen == 2)
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}




int compras_filtrarVentas(void* pElement)
{
	int auxReturn = 0;
	eCompras* auxCompras = (eCompras*) pElement;

	if(pElement != NULL)
	{
		auxCompras = (eCompras*) pElement;

		if(auxCompras->origen == 3)
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}


/***BUSQUEDA NOMBRE ORIGEN***/
int cargarNombreOrigen(char* nombre, int origen)
{
	int retorno = 0;

	if(nombre!= NULL)
	{
		if(origen == 1)
		{
			strcpy(nombre, "ADMINISTRACION" );
		}
		else
		{
			if(origen == 2)
			{
				strcpy(nombre, "TALLER" );
			}
			else
			{
				strcpy(nombre, "VENTAS" );
			}
		}
		retorno = 1;
	}
	return retorno;
}

/***MAPEO DE COMPRAS***/
void* compra_totalCompra(void* pElemento)
{
	float total ;
	int cantidad ;
	int precio ;
	int origen;

	  eCompras* auxCompra;

	  if(pElemento != NULL)
	  {
	    auxCompra = (eCompras*) pElemento;
	    compra_getOrigen(auxCompra, &origen);//Traigo el get para verificar el origen de cada compra
	    compra_getCantidad(auxCompra, &cantidad);//Traigo el valor de la cantidad
	    compra_getPrecioUnitario(auxCompra, &precio);//Traigo el valor del precio unitario
	    if(origen == 1){
	      total = cantidad * precio;
	    }else if(origen == 2)
	    {
	      total = cantidad * precio;
	    }else
	    {
	      total = cantidad * precio;
	    }
	   compra_setTotalCompra(auxCompra, total);//Seteo el total de la compra

	  }
	    return auxCompra;
}
