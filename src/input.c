/*
 * input.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError)
{
	int retorno = -1;
    char auxString[limit];

    if(pAux != NULL && msg != NULL && msgError != NULL && limit > 0 && retry >= 0){
        do{
        	printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                retorno = 0;
                break;
            }else
            {
            	printf("%s", msgError);
            }
            retry--;

        }while(retry>=0);
    }

    return retorno;
}

int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int retorno = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            retorno = 0;
        }
    }

    return retorno;
}

int isChar(char str[])
{

	int retorno = 0;

	for(int i = 0; str[i] != '\0'; i++)
	{

		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			retorno = -1;
		}
	}

	return retorno;

}

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int retorno = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return retorno;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int retorno =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString);
        retorno = 0;
    }
    return retorno;
}

int isFloat(char* pAux)
{
    int retorno = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        retorno = 0;
    }
    return retorno;
}

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int retorno = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }
        while(retry >= 0);
    }
    return retorno;
}

int getInt(int* pAux)
{
    char auxString[400];
    int retorno = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString);
        retorno = 0;
    }
    return retorno;
}

int isInt(char *pAux)
{
    int retorno = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        retorno = 0;
    }

    return retorno;
}

int strLwr(char* str)
{
	int retorno = -1;
	int i = 0;

	if(str != NULL)
	{
		while(str[i] != '\0')
		{
			str[i] = tolower(str[i]);
			i++;
		}
		retorno = 0;
	}
	return retorno;
}

int normalizeStr(char* str)
{
	int retorno = -1;
	int i = 0;

	if(str != NULL)
	{
		strLwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				retorno = 0;
			}
			i++;
		}
	}
	return retorno;
}


int utn_getPath(char *pAux, int limit, int retry, char* msg, char* msgError)
{
	int retorno = -1;
    char auxString[limit];

    if(pAux != NULL && msg != NULL && msgError != NULL && limit > 0 && retry >= 0){
        do{
        	printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isPath(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                retorno = 0; //exito
                break;
            }else
            {
            	printf("%s", msgError);
            }
            retry--;

        }while(retry>=0);
    }

    return retorno;
}

int isPath(char* pAux)
{
    int retorno= -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
        }

        if(dotCount > 1)
        {
        	break;
        }

        i++;
    }while (i < stringLong);

    if(stringLong == i)
    {
    	retorno = 0;//exito
    }
    return retorno;
}


int isYesNoCharacter(char caracter){
    int retorno = 0;
    if ((caracter == 's') || (caracter == 'n'))
        retorno = 1;
    return retorno;
}



int getValidYesNoChar(char mensaje[], char errorMensaje[]){
    char aux='n';
    do{
        if(isYesNoCharacter(aux)==0){
            aux = getChar(errorMensaje);
        }else{
            aux = getChar(mensaje);
        }
    }while (isYesNoCharacter(aux)==0);
    return aux;
}



char getChar(char* mensaje){
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

