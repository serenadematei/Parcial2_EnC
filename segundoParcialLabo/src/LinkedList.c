/*
 * LinkedList.c
 * segundoParcialLabo
 */
#include <stdio.h>
#include <stdlib.h>
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
    this=(LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
     {
         this->size=0;
         this->pFirstNode = NULL;
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

    if(this!=NULL){
      returnAux= this->size;
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
	Node* pNodo=NULL;



	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)){


	    pNodo= this->pFirstNode;


	    for(int i=0; i<nodeIndex;i++){
	    	pNodo= pNodo->pNextNode;

	    }



	}

    return pNodo;
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
    Node* nuevoNodo=NULL;
    Node* auxNodo = NULL;


    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this)){

    	nuevoNodo=(Node*)malloc(sizeof(Node));

    	if(nuevoNodo!=NULL){

    		nuevoNodo->pElement=pElement;
    		nuevoNodo->pNextNode=getNode(this,nodeIndex);

    		if(nodeIndex==0){

             this->pFirstNode=nuevoNodo;

    		}
    		else
        	{
    			auxNodo =getNode(this,nodeIndex-1);
    			auxNodo->pNextNode=nuevoNodo;

        	}

    		this->size++;
    		returnAux=0;



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


/** \brief  Agrega un nodo al final de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if(this!=NULL){

    	addNode(this,ll_len(this),pElement);
    	returnAux=0;
    }

    return returnAux;
}

/** \brief Me devuelve el elemento al que apunta el nodo (la carga)
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
    Node* auxNodo=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this)){

    	auxNodo=getNode(this,index);
    	if(auxNodo!=NULL){
    		returnAux=auxNodo->pElement;
    	}

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista.
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

    if(this!=NULL && index>=0 && index<ll_len(this)){


    	getNode(this,index)->pElement=pElement;
    	returnAux=0;

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* pNodo=NULL;
    Node* nodoPrevio=NULL;


    if(this!=NULL && index>=0 && index<ll_len(this)){

    	pNodo = getNode(this,index);


    	if(pNodo!=NULL){


    		if(index==0){

    			this->pFirstNode=pNodo->pNextNode;


    		}
    		else
    		{
    			nodoPrevio = getNode(this,index-1);
    			if(nodoPrevio!=NULL){
    				nodoPrevio->pNextNode= pNodo->pNextNode;
    			}



    		}


    		free(pNodo);

    		this->size--;





    	}

    	returnAux=0;


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


    if(this!=NULL){

    	while(ll_len(this)!=0){
    		ll_remove(this,0);
    	}

    	if(ll_len(this)==0){
    		returnAux=0;
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
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){

      ll_clear(this);
      free(this);
      returnAux=0;

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


    if(this!=NULL){

    	for(int i=0; i<ll_len(this);i++){

    		if(ll_get(this,i)==pElement){
    			returnAux=i;
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

    if(this!=NULL){

    	returnAux=0;
    	if(this->size == 0){
    		returnAux=1;
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

    if(this!=NULL && index>=0 && index<=ll_len(this)){


    	if(!addNode(this,index,pElement)){
    		returnAux=0;
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



    if(this!=NULL && index>=0 && index<ll_len(this)){

    	returnAux=ll_get(this,index);
    	ll_remove(this,index);

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


    if(this!=NULL){

    	returnAux=0;


    	if(ll_indexOf(this,pElement)!=-1){
    		returnAux=1;
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


    if(this!=NULL && this2!=NULL){


    	returnAux=1;


    	for(int i=0; i<ll_len(this2) ; i++){

    		if(!ll_contains(this,ll_get(this2,i))){
    			returnAux=0;
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
    void* auxElement=NULL;

    if(this!=NULL && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this)){

    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL){


    		for(int i=from; i<to;i++){
    			auxElement=ll_get(this,i);
    			ll_add(cloneArray,auxElement);
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

    cloneArray=ll_subList(this,0,ll_len(this));

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


    void* auxI=NULL;
    void* auxJ=NULL;


    if(this!=NULL && pFunc!=NULL && (order==0 || order==1)){


    	for(int i=0; i<ll_len(this)-1; i++){
    		for(int j=i+1;  j<ll_len(this) ; j++){

    		   auxI=ll_get(this,i);
    		   auxJ=ll_get(this,j);




    			if(order && pFunc(auxI,auxJ)){ //ASCENDENTE


    			   ll_set(this,i,auxJ);
    			   ll_set(this,j,auxI);



    		    }else if(!order && pFunc(auxI,auxJ)==-1){ //DESCENDENTE


    			    ll_set(this,i,auxJ);
    			    ll_set(this,j,auxI);


    			}
    		}
    	}


    	returnAux=0;

    }


    return returnAux;

}

/**
*La funci�n �ll_filter� recibir� una lista y una funci�n criterio �fn�. Se deber� iterar todos los elementos
*de la lista y pasarlos a la funci�n �fn�. La funci�n �fn� devolver� 1 si ese �tem se debe agregar a la
*lista resultado o 0 si no debe agregarse. La funci�n �ll_filter� generar� la nueva lista resultado,
*agregar� a la misma los �tems correspondientes y la devolver�.
**/
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* element)){


	LinkedList* listaFiltrada= ll_newLinkedList();
	void* auxElement=NULL;


	if(this!=NULL && pFunc!=NULL && listaFiltrada!=NULL){


		for(int i=0; i<ll_len(this);i++){
			auxElement=ll_get(this,i); //LE PASO CADA ELEMENTO DE LA LISTA A LA FUNCION FN
			if(pFunc(auxElement)){  //si pasa el filtro, lo agrego a la nueva lista(lista filtrada)
				ll_add(listaFiltrada,auxElement);

			}

		}



	}


	return listaFiltrada;
}


/**
 *
 * La funci�n �ll_count� recibir� una lista y una funci�n criterio �fn�. Se deber� iterar todos los elementos
 * de la lista y pas�rselos a la funcion �fn�. La funci�n �fn� devolver� la cantidad que debe contarse segun
 * el criterio. La funci�n �ll_count� almacenar� un acumulador al cual sumar� el valor de retorno de �fn� en
 * cada iteraci�n. Al finalizar las iteraciones, la funci�n �ll_count� devolver� el valor acumulado.
 *
 */
int ll_count(LinkedList* this, int (*fn)(void* element)){

	int returnAux;
	void* auxElement;
	int acumulador=0;

	if(this!=NULL && fn!=NULL){
		for(int i=0; i<ll_len(this);i++){
			auxElement=ll_get(this,i);   //recorro la lista y me traigo cada elemento para pasarselo a fn
			acumulador+=fn(auxElement);  //fn devuelve 1 si se cuenta dicho elemento, y los voy acumulando hasta terminar el for.
		}

		returnAux=acumulador;
	}


	return returnAux;

}

/*
 * La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem de la lista, de
este modo se realizar�n descuentos a los precios seg�n se detalla:
* PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
*
 */


LinkedList* ll_map (LinkedList* this, int(*pFunc) (void* element)){

	LinkedList* auxLista;
	void* auxElement;

	if(this!=NULL && pFunc!=NULL){

		auxLista=ll_newLinkedList();
		for(int i=0; i<ll_len(this); i++){
			auxElement=ll_get(this,i);


		     if(pFunc(auxElement)){
		    	 ll_add(auxLista,auxElement);
		     }





		}

	}


	return auxLista;

}

