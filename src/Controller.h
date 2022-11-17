/*
 * Controller.h
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Carga los datos de los compras desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCompra LinkedList*
 * \return int
 *
 */
/****CARGAR COMPRAS DESDE TEXTO***////
int controller_cargarComprasDesdeTexto(char* path , LinkedList* pArrayListCompra);//Check
/****LISTAR COMPRAS****////
 /**
   * \fn int controller_listarCompras(LinkedList*)
  * \brief muestra la lista de compras
  *
  * \param pArrayListCompra
  * \return
  */
int controller_listarCompras(LinkedList* pArrayListCompra);//Check
/***MAPEO***////
 /**
   * \fn int controller_map(LinkedList*)
  * \brief  MAPEA
  *
  * \param pArrayListCompra
  * \return -1 mal o 0 bien
  */
int controller_map(LinkedList* pArrayListCompra);
/***COMPRAS FILTRADAS***////
/**
 * \fn int controller_filter(LinkedList*)
 * \brief se encarga de filtrar por compra
 *
 * \param pArrayListCompra
 * \return -1 mal o 0 bien
 */
int controller_filter(LinkedList* pArrayListCompra);
/**GUARDAR MODO TEXTO**/
/**
 * \fn int controller_guardarModoTexto(char*, LinkedList*)
 * \brief Guarda archivo en modo texto
 *
 * \param path
 * \param pArrayListCompras
 * \return -1 mal o 0 bien
 */
int controller_guardarModoTexto(char* path , LinkedList* pArrayListCompras);
/****ORDENAMIENTO***////
 /**
   * \fn int controller_ordenarCompras(LinkedList*)
  * \brief ordena las compras por descripcion de manera ascendente o descendente
  *
  * \param pArrayListJugador
  * \return -1 mal o 0 bien
  */
int controller_ordenarCompras(LinkedList* pArrayListJugador);//Check
/**GUARDAR ORDENAMIENTO MODO TEXTO**////
 /**
   * \fn int controller_guardarOrdenamientoModoTexto(char*, LinkedList*)
  * \brief guarda la lista ordenada en modo texto
  *
  * \param path
  * \param pArrayListCompras
  * \return -1 mal o 0 bien
  */
int controller_guardarOrdenamientoModoTexto(char* path , LinkedList* pArrayListCompras);


#endif /* CONTROLLER_H_ */
