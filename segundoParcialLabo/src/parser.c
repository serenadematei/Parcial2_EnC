#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "parser.h"


/** \brief Parsea los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_librosFromText(FILE* pFile , LinkedList* lista)
{
	int retorno=0;

	eLibro* auxLibro=NULL;
	char encabezado[200];
	char buffer[5][100];//declaro una matriz, de 5 filas (cant de campos) y 100 cada una(maximo total de los array)
	int cant;

    if(pFile!=NULL && lista!=NULL){

    	fscanf(pFile,"%s",encabezado);

    	do{

    		cant = fscanf(pFile,"%[^,],%[^,], %[^,], %[^,], %[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
          //guardo los datos de manera temporal en el buffer
    		if(cant<5){
    		   break;
    		 }


    		auxLibro= libro_newParametrosStr(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]); //se los cargo a un nuevo libro
    		if(auxLibro!=NULL){
    		    ll_add(lista,auxLibro); //agrego el nuevo libro a la lista
    		    retorno=1;
    		}


    		auxLibro=NULL;


    	}while(!feof(pFile));


    }

    return retorno;
}





int parser_editorialesFromText(FILE* pFile , LinkedList* lista)
{
	int retorno=0;

	eEditorial* auxEditorial=NULL;
	char encabezado[200];
	char buffer[2][100];
	int cant;

    if(pFile!=NULL && lista!=NULL){

    	fscanf(pFile,"%s",encabezado);

    	do{

    		cant = fscanf(pFile,"%[^,], %[^\n]\n",buffer[0],buffer[1]);

    		if(cant<2){
    		   break;
    		 }

    		auxEditorial= editorial_newParametrosStr(buffer[0],buffer[1]);
    		if(auxEditorial!=NULL){
    			ll_add(lista,auxEditorial);
    			retorno=1;
    		}


    		auxEditorial=NULL;


    	}while(!feof(pFile));


    }

    return retorno;
}
