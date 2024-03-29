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
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;
	this = malloc(sizeof(LinkedList));
	if(this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
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
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;
	int indice;
	int len = ll_len(this);
	if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		indice = 0;
		auxNode = this->pFirstNode;
		do
		{
			if(indice != nodeIndex)
			{
				auxNode = auxNode->pNextNode;
				indice++;
			}
			else
			{
				break;
			}
		}while(auxNode != NULL);
	}
	return auxNode;
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
	Node* auxNode = NULL;
	Node* auxNodeDos = NULL;
	if(this != NULL && nodeIndex >= 0)
	{
		auxNode = (Node*) malloc(sizeof(Node));
		auxNodeDos = auxNode;
		if(auxNode != NULL && auxNodeDos != NULL)
		{
			auxNode->pElement = pElement;
			this->size++;
			returnAux = 0;
			if(nodeIndex == 0)
			{
				auxNode->pNextNode = this->pFirstNode;
				this->pFirstNode = auxNode;
			}
			else if(nodeIndex != ll_len(this))
			{
				auxNodeDos = getNode(this, nodeIndex);
				auxNode->pNextNode = auxNodeDos;
				auxNodeDos = getNode(this, nodeIndex-1);
				auxNodeDos->pNextNode = auxNode;
			}
			else
			{
				auxNodeDos = getNode(this, nodeIndex-1);
				auxNodeDos->pNextNode = auxNode;
				auxNode->pNextNode = NULL;
			}
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
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && !addNode(this,ll_len(this),pElement))
	{
		returnAux = 0;
	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
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
	Node* auxNode;
	int len = ll_len(this);
	if(this != NULL && index >= 0 && index < len)
	{
		auxNode = getNode(this,index);
		returnAux = auxNode->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node* auxNode = NULL;
	int len = ll_len(this);
	if(this != NULL && index >= 0 && index < len)
	{
		auxNode = getNode(this,index);
		if(auxNode != NULL)
		{
			auxNode->pElement = pElement;
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
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	Node* auxNode = NULL;
	Node* anterior = NULL;
	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this,index);
		anterior = getNode(this,index-1);
		if(index == 0)
		{
			this->pFirstNode = auxNode->pNextNode;
		}
		else
		{
			anterior->pNextNode = auxNode->pNextNode;
		}
		this->size--;
		free(auxNode);
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
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int flag;
    int len;
    if(this != NULL)
    {
    	do
    	{
    		len = ll_len(this);
    		flag = ll_remove(this,len -1);
    	}while(flag != -1);
    	this->pFirstNode = NULL;
    	this->size = 0;
    	returnAux = 0;
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
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
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
	int returnAux = -1;
	int indice=0;
	int len = ll_len(this);
	if(this != NULL)
	{
		for(indice=0;indice<len;indice++)
		{
			if(ll_get(this, indice) == pElement)
			{
				returnAux = indice;
				break;
			}
		}
	}
	return returnAux;
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
	int returnAux = -1;
	int len = ll_len(this);
	if(this != NULL)
	{
		if(len == 0)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
		}
	}
	return returnAux;
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
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	int len = ll_len(this);
	if(this != NULL && index >= 0 && index <= len)
	{
		if(addNode(this,index,pElement)==0)
		{
			returnAux = 0;
		}
	}

	return returnAux;
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
	void* returnAux = NULL;
	int len = ll_len(this);
	if(this != NULL && index >=0 && index <= len)
	{
		returnAux = ll_get(this,index);
		if(returnAux != NULL)
		{
			ll_remove(this,index);
		}
	}
	return returnAux;
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
	int returnAux = -1;
	int index=0;
	int len = ll_len(this);
	if(this != NULL)
	{
		returnAux= 0;
		for(index=0;index<len;index++)
		{
			if(ll_get(this, index) == pElement)
			{
				returnAux = 1;
				break;
			}
		}
	}
	return returnAux;
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
	int index=0;
	void* aux;
	int len = ll_len(this2);
	if(this != NULL && this2 != NULL)
	{
		returnAux= 0;
		for(index=0;index<len;index++)
		{
			aux = ll_get(this,index);
			if(ll_contains(this2,aux)==0)
			{
				returnAux = 0;
				break;
			}
			else
			{
				returnAux = 1;
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
    int indice=0;
    void* aux;
    int len = ll_len(this);
    if(this != NULL && from >= 0 && to >= 0 && from < to && to <= len && from <= len)
    {
    	cloneArray = ll_newLinkedList();
    	for(indice=0;indice<len;indice++)
		{
    		aux = ll_get(this,indice);
			ll_add(cloneArray,aux);
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
	int len = ll_len(this);
	if(this != NULL)
	{
		cloneArray = ll_newLinkedList();
		if(ll_subList(this,0,len) != NULL)
		{
			cloneArray = ll_subList(this,0,len);
		}
	}
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
	int returnAux =-1;
	int indice;
	void* auxUno = NULL;
	void* auxDos = NULL;
	void* auxElemento;
	int swap;
	int auxiliarF;
	int len;

	if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
	{
		len = ll_len(this)-1;
		do
		{
			swap = 0;

			for(indice=0;indice<len;indice++)
			{
				auxUno = ll_get(this,indice);
				auxDos = ll_get(this,indice+1);
				auxiliarF = pFunc(auxUno,auxDos);
				if((auxiliarF == -1 && order == 0) || (auxiliarF == 1 && order == 1))
				{
					auxElemento = auxUno;
					ll_set(this,indice,auxDos);
					ll_set(this,indice+1,auxElemento);
					swap = 1;
				}
			}
			len--;
		}while(swap);
		returnAux = 0;
	}
	return returnAux;
}

