/*
 * eCompras.h
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */
#include "LinkedList.h"

#ifndef ECOMPRAS_H_
#define ECOMPRAS_H_

typedef struct
{
	int codigoCompra;
	char descripcion[100];
	int origen;
	float precioUnitario;
	int cantidad;
	float totalCompra;
}eCompras;

////******SETTERS Y GETTERS******////
/**
 * \fn int compra_setCodigoCompra(eCompras*, int)
 * \brief fijan el valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_setCodigoCompra(eCompras* this, int codigoCompra);//Setter
/**
 * \fn int compra_getCodigoCompra(eCompras*, int*)
 * \brief  permiten acceder al valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_getCodigoCompra(eCompras* this, int* codigoCompra);//Getter
/**
 * \fn int compra_setCodigoCompra(eCompras*, int)
 * \brief fijan el valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_setDescripcion(eCompras* this, char* descripcion);//Setter
/**
 * \fn int compra_getCodigoCompra(eCompras*, int*)
 * \brief  permiten acceder al valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_getDescripcion(eCompras* this, char* descripcion);//Getter
/**
 * \fn int compra_setCodigoCompra(eCompras*, int)
 * \brief fijan el valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_setOrigen(eCompras* this, int origen);//Setter
/**
 * \fn int compra_getCodigoCompra(eCompras*, int*)
 * \brief  permiten acceder al valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_getOrigen(eCompras* this, int* origen);//Getter
/**
 * \fn int compra_setCodigoCompra(eCompras*, int)
 * \brief fijan el valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_setPrecioUnitario(eCompras* this, int precioUnitario);//Setter
/**
 * \fn int compra_getCodigoCompra(eCompras*, int*)
 * \brief  permiten acceder al valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_getPrecioUnitario(eCompras* this, int* precioUnitario);//Getter
/**
 * \fn int compra_setCodigoCompra(eCompras*, int)
 * \brief fijan el valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_setCantidad(eCompras* this, int cantidad);//Setter
/**
 * \fn int compra_getCodigoCompra(eCompras*, int*)
 * \brief  permiten acceder al valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_getCantidad(eCompras* this, int* cantidad);//Getter
/**
 * \fn int compra_setCodigoCompra(eCompras*, int)
 * \brief fijan el valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_setTotalCompra(eCompras* this, float totalCompra);//Setter
/**
 * \fn int compra_getCodigoCompra(eCompras*, int*)
 * \brief  permiten acceder al valor de un atributo
 *
 * \param this
 * \param codigoCompra
 * \return -1 mal o 0 bien
 */
int compra_getTotalCompra(eCompras* this, float* totalCompra);//Getter
////*****CONSTRUCTORES******////
/**
 * \fn eCompras compra_new*()
 * \brief Crea espacio en memoria dinamica e inicializa variables por default
 *
 * \return retorna puntero a eCompras
 */
eCompras* compra_new();
/**
 * \fn eCompras compra_newParametros*(char*, char*, char*, char*, char*, char*)
 * \brief Crea un dato con los valores que se le pasan por parametro
 *
 * \param codigoCompra
 * \param descripcion
 * \param origen
 * \param precioUnitario
 * \param cantidad
 * \param totalCompra
 * \return retorna puntero a eCompras
 */
eCompras* compra_newParametros(char* codigoCompra,char* descripcion,char* origen, char* precioUnitario, char* cantidad, char* totalCompra);
////*****DESTRUCTOR*****////
/**
 * \fn int compra_delete(eCompras*)
 * \brief libera espacio en memoria dinamica o un una compra para ser mas especifico
 *
 * \param this
 * \return -1 mal o 0 bien
 */
int compra_delete(eCompras* this);
////******IMPRIMIR****////
/**
 * \fn int compra_print(eCompras*)
 * \brief imprime una compra
 *
 * \param This
 * \return -1 mal o 0 bien
 */
int compra_print(eCompras* This);
/**
 * \fn int compra_printAll(LinkedList*)
 * \brief imprime todas las compras
 *
 * \param pArrayListCompra
 * \return -1 mal o 0 bien
 */
int compra_printAll(LinkedList* pArrayListCompra);
///***ORDENAMIENTO***///
/**
 * \fn int compra_ordenar(LinkedList*)
 * \brief ordena por doble criterio ascendente o descendente
 *
 * \param pArrayListCompra
 * \return -1 mal o 0 bien
 */
int compra_ordenar(LinkedList* pArrayListCompra);
/**
 * \fn int compra_ordenarXDescripcion(void*, void*)
 * \brief ordena las compras por descripcion
 *
 * \param pCompraUno
 * \param pCompraDos
 * \return -1 mal o 0 bien
 */
int compra_ordenarXDescripcion(void* pCompraUno, void* pCompraDos);
///*****FILTRAR****///
/**
 * \fn int compras_filtrarAdministracion(void*)
 * \brief filtra las compras de administracion
 *
 * \param pElement
 * \return -1 mal o 0 bien
 */
int compras_filtrarAdministracion(void* pElement);
/**
 * \fn int compras_filtrarAdministracion(void*)
 * \brief filtra las compras de taller
 *
 * \param pElement
 * \return -1 mal o 0 bien
 */
int compras_filtrarTaller(void* pElement);
/**
 * \fn int compras_filtrarAdministracion(void*)
 * \brief filtra las compras de Ventas
 *
 * \param pElement
 * \return -1 mal o 0 bien
 */
int compras_filtrarVentas(void* pElement);
/***BUSQUEDA NOMBRE ORIGEN***/
/**
 * \fn int cargarNombreOrigen(char*, int)
 * \brief carga el nombre del origen de las compras(1 Administracion,2 taller,3Ventas)
 *
 * \param nombre
 * \param origen
 * \return
 */
int cargarNombreOrigen(char* nombre, int origen);
/***MAPEO DE COMPRAS***/
/**
 * \fn void compra_totalCompra*(void*)
 * \brief calcula el campo total compra
 *
 * \param pElemento
 */
void* compra_totalCompra(void* pElemento);


#endif /* ECOMPRAS_H_ */
