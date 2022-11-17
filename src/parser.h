/*
 * parser.h
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */
#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_

/**
 * \fn int parser_CompraFromText(FILE*, LinkedList*)
 * \brief parsea los datos del archivo a texto
 *
 * \param pFile
 * \param pArrayListCompra
 * \return
 */
int parser_CompraFromText(FILE* pFile , LinkedList* pArrayListCompra);


#endif /* PARSER_H_ */
