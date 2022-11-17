/*
 * input.h
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#ifndef INPUT_H_
#define INPUT_H_

/**
 * \fn int utn_getCadena(char*, int, int, char*, char*)
 * \brief  Obtiene una cadea
 *
 * \param pAux
 * \param limit
 * \param retry
 * \param msg
 * \param msgError
 * \return
 */
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);


/**
 * \fn int getCadena(char*, int)
 * \brief
 *
 * \param pAux
 * \param limit
 * \return
 */
int getCadena(char* pAux, int limit);


/**
 * \fn int isChar(char[])
 * \brief
 *
 * \param str
 * \return
 */
int isChar(char str[]);



/**
 * \fn int utn_getFlotante(float*, int, char*, char*, float, float)
 * \brief   verifica que el numero sea flotante
 *
 * \param pFloat
 * \param retry
 * \param msg
 * \param msgError
 * \param min
 * \param max
 * \return
 */
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

int getFloat(float*pAux);

int isFloat(char* pAux);


/**
 * \fn int utn_getEntero(int*, int, char*, char*, int, int)
 * \brief  Verifica que el numero sea entero
 *
 * \param pEntero
 * \param retry
 * \param msg
 * \param msgError
 * \param min
 * \param max
 * \return
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

/**
 * \fn int getInt(int*)
 * \brief
 *
 * \param pAux
 * \return
 */
int getInt(int* pAux);
/**
 * \fn int isInt(char*)
 * \brief
 *
 * \param pAux
 * \return
 */
int isInt(char *pAux);
/**
 * \fn int strLwr(char*)
 * \brief
 *
 * \param str
 * \return
 */
int strLwr(char* str);
/**
 * \fn int normalizeStr(char*)
 * \brief
 *
 * \param str
 * \return
 */
int normalizeStr(char* str);
/**
 * \fn int utn_getPath(char*, int, int, char*, char*)
 * \brief
 *
 * \param pAux
 * \param limit
 * \param retry
 * \param msg
 * \param msgError
 * \return
 */
int utn_getPath(char *pAux, int limit, int retry, char* msg, char* msgError);
/**
 * \fn int isPath(char*)
 * \brief
 *
 * \param pAux
 * \return
 */
int isPath(char* pAux);
/**
 * \fn char getChar(char*)
 * \brief
 *
 * \param mensaje
 * \return
 */
char getChar(char* mensaje);
/**
 * \fn int getValidYesNoChar(char[], char[])
 * \brief
 *
 * \param mensaje
 * \param errorMensaje
 * \return
 */
int getValidYesNoChar(char mensaje[], char errorMensaje[]);
/**
 * \fn int isYesNoCharacter(char)
 * \brief
 *
 * \param caracter
 * \return
 */
int isYesNoCharacter(char caracter);


#endif /* INPUT_H_ */
