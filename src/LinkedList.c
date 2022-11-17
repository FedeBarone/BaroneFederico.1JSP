/*
 * LinkedList.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) //la inicializo en 0
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!= NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista//
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)//Nos dice la direccion de memoria de un nodo
{
	Node* pNode = NULL;
	if(this!= NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		if(pNode!= NULL)
		{
			for(int i = 0 ; i < nodeIndex; i++)
			{
				pNode = pNode->pNextNode;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;

    if(this!= NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	newNode = (Node*)malloc(sizeof(Node));
    	if(newNode != NULL)
    	{
    		newNode->pElement = pElement; //Cargo el nodo, hago que apunte al elemento
    		newNode->pNextNode = getNode(this, nodeIndex);//Le paso el indice del nodo que quiero
    		if(nodeIndex == 0)
    		{
    			this->pFirstNode = newNode;//Hago que linkedlist apunte al nuevo
    		}
    		else
    		{
    			(getNode(this, nodeIndex-1))->pNextNode = newNode;  //Hago que la dir del nodo anterior me apunte al nuevo nodo
    			//getNode(this, nodeIndex-1);//esto es la dir memoria del nodo anterior
    		}
    		this->size++;
    		returnAux = 0;//ok
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)//El add agrega un nodo al final de la lista
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!addNode(this, ll_len(this), pElement))//Niego y transformo cero en 1 para entrar
    	{
    		returnAux= 0;
    	}
    }

    return returnAux;
}

/** \brief Devuelve el elemento guardado en la lista en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this!= NULL && index >= 0 && index < ll_len(this))
    {
    	if(getNode(this, index)!= NULL)
    	{
    		returnAux = getNode(this, index)->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//El set pisa el nodo con el elemento
{
    int returnAux = -1;
    if(this!= NULL && index >= 0 && index < ll_len(this))
    {
    	if(getNode(this, index)!=NULL)
    	{
    		getNode(this, index)->pElement = pElement;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)//Vamos a sacar pero lo tenemos que dejar enganchado
{
    int returnAux = -1;
    Node* prevNode = NULL;//Este es el nodo que quiero borrar
    Node* nodoRemover = NULL;
    if(this != NULL && index >=0 && index < ll_len(this))
    {
    	nodoRemover = getNode(this, index); //Guardo la direccion de memoria del nodo que quiero eliminar
    	if(index == 0)
    	{
    		this->pFirstNode = nodoRemover->pNextNode;//Este es el nodo que quiero borrar

    	}
    	else
    	{
    		prevNode = getNode(this, index-1);//voy al nodo anterior
    		prevNode->pNextNode = nodoRemover->pNextNode;
    	}

    	free(nodoRemover);
    	nodoRemover = NULL;
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)//El clear va a ir recorriendo y llamando al remove
{
	int returnAux = -1;

		if(this != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)
			{
				ll_remove(this, i);
			}

			if(ll_len(this) == 0)
			{
				returnAux = 0;
			}
		}
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)//LLama al clear
{
	 int returnAux = -1;

		if (this != NULL && !ll_clear(this))
		{
			free(this); //libero la linkedlist
			returnAux = 0;
		}
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int indexNode = -1;
	Node* pNodeAux;

	    if(this != NULL)
	    {
	    	for(int i = 0; i < ll_len(this); i++)
	    	{
	    		pNodeAux = getNode(this, i);
	    		if(pNodeAux != NULL && pNodeAux->pElement == pElement)
	    		{
					indexNode = i;
					break;//PRIMERA ocurrencia
	    		}
	    	}
	    }

	return indexNode;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int isEmpty = -1;

	    if(this != NULL)
	    {
	    	if(ll_len(this))
	    	{
	    		isEmpty = 0; //no esta vacia
	    	}
	    	else
	    	{
	    		isEmpty = 1;//esta vacia
	    	}
	    }
	    return isEmpty;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)//Inserta un nodo entre el medio de dos
{
	return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* pElement = NULL;

	    if(this != NULL && index <= ll_len(this) && index >= 0)
	    {
	    	pElement = ll_get(this, index);
	    	if(ll_remove(this, index) == -1)//si falla ll remove
	    	{
	    		pElement = NULL;
	    	}
	    }

	    return pElement;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int exist = -1;

		if (this != NULL)
		{
			if (ll_indexOf(this, pElement) > -1)//si el indice del elemento existe
			{
				exist = 1;
			}
			else // si no existe
			{
				exist = 0;
			}
		}
	    return exist;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	    void* pElem;
	    int sizeThis2;

	    if(this != NULL && this2 != NULL)
	    {
	    	sizeThis2 = ll_len(this2);
	    	returnAux = 1;//si nunca entra al if, todos los elems estan contenidos

			for(int i = 0; i < sizeThis2; i++)
			{
				pElem = ll_get(this2, i);
				if(!ll_contains(this, pElem))//si el elemento de this2 no esta en this
				{
					returnAux = 0;
					break;
				}
			}
	    }
	    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	 LinkedList* cloneArray = NULL;
	    void* pElement;

	    if(this != NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this))
	    {
	    	cloneArray = ll_newLinkedList();//pido espacio

	    	if(cloneArray != NULL)
	    	{
	    		for(int i = from; i < to; i++)
				{
	    			pElement = ll_get(this, i);
	    			ll_add(cloneArray, pElement);
				}
	    	}
	    }
	    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;

	    cloneArray = ll_subList(this, 0, ll_len(this));//desde 0 hasta el tamanio de this

	    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	 int retorno = -1;
	    void* pElement1;
	    void* pElement2;

	    if(this != NULL && pFunc != NULL && (order == 0 || order == 1) )
		{
			for(int i = 0; i < ll_len(this) - 1 ; i++)
			{
				for(int j = i + 1; j < ll_len(this); j++)
				{
					pElement1 = ll_get(this, i);
					pElement2 = ll_get(this, j);

					//1. si el primer elemento es mas grande que el segundo, y el orden es ascendente, swapeo
					//2. si el primer elemento es mas chico que el segundo, y el orden es descendente, swapeo
					if((pFunc(pElement1, pElement2) > 0 && order == 1) || (pFunc(pElement1, pElement2) < 0 && order == 0))
					{
						ll_set(this, i, pElement2); //copio el elemento 2 en el lugar del 1
						ll_set(this, j, pElement1); //copio el elemento 1 en el lugar del 2
					}
				}
			}
			retorno = 0;
		}
	    return retorno;
}

/**
 * \fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
 * \brief filtra los elemntos y los agrega si  la condicion de pfunc es 1
 *
 * \param this
 * \param pFunc
 * \return puntero de la linkedlist
 */
//Lo unico que va a hacer el filter lo que va hacer segun el criterio de la funcion que recibe decide si se cumple el criterio o no se cumple para ser filtrado
LinkedList* ll_filter (LinkedList* this, int (*pFunc) (void* element))///**En el filtro tengo que llamar a mi puntero a funcion, pasarle el elemento*/
{																			//y ver que retorno me devuelve la funcion , en base al retorno yo voy a hacer algo
	LinkedList* listaFiltrada = NULL;									//voy a querer hacer un filtro , entonces voy a tener una nueva linkedlist y voy a hacer
	void* pElement = NULL;											//Un add de un elemento que me haya devuelto mi puntero a funcion un valor de true, osea de que
																	//Hay que cargar lo que sea que este comparando en mi funcion , que esta recibiendo
	if(this != NULL && pFunc != NULL)							//tengo que retornarle 0,1 o 2 segu nel criterio
	{
		listaFiltrada = ll_newLinkedList();//Nuevas altas de los elementos que estoy filtrando, me creo esta linked para filtrar de la anterior linked
		if(listaFiltrada != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)//Len es el largo de la primer lista
			{
				pElement = ll_get(this, i);//Con el get voy tomando elemento por elemento, voy tomando elemtnos que gurado en el auxiliar. Me traigo el elemento que quiero saber si voy a agregar en mi nueva linkedlist
				if(pFunc(pElement))//si da 1 es porque cumple la condicion que le puso pFunc //Debe ser compatible con cualqueir tipo de elementos, el puntero a funcion si pasa o no pasa el elemento
				{
					ll_add(listaFiltrada, pElement);//si cumple lo agrego a la lista filtrada
				}
			}//for
		}//if null
	}//if null
	return listaFiltrada;
}


/**
 * \fn LinkedList ll_map*(LinkedList*, void*(*)(void*))
 * \brief	mapea los elementos de la lista que recibe por parametro y lo resultado de esta lista lo agregua a la nueva linkedlist
 *
 * \param this
 * \param pFunc
 * \return puntero de la linkedlist
 */
LinkedList* ll_map (LinkedList* this, void* (*pFunc) (void* element))
{
	LinkedList* listaResultado = NULL;
	void* pElement = NULL;

	if(this != NULL && pFunc != NULL)
	{
		listaResultado = ll_newLinkedList();
		if(listaResultado != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)
			{
				pElement = ll_get(this, i);
				pElement = pFunc(pElement);//calcula y devuelve el elemento
				if(pElement != NULL)
				{
					ll_add(listaResultado, pElement);
				}
			}
		}
	}
	return listaResultado;
}
