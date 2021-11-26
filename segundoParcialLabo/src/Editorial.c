/*
 * Editorial.c
 *
 *  Created on: 22 nov 2021
 *      Author: Sere
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Editorial.h"
#include "LinkedList.h"

eEditorial* editorial_new(){

	eEditorial* nuevaEditorial=(eEditorial*)malloc(sizeof(eEditorial));
	return nuevaEditorial;
}




eEditorial* editorial_newParametrosStr(char* idStr,char* nombreStr){

	eEditorial* nuevaEditorial = editorial_new();

	if (nuevaEditorial != NULL && idStr != NULL && nombreStr!= NULL) {
		if (!(editorial_setId(nuevaEditorial, atoi(idStr))
				&& editorial_setNombre(nuevaEditorial, nombreStr))) {

			free(nuevaEditorial);
			nuevaEditorial= NULL;
		}

	}

	return nuevaEditorial;

}



eEditorial* editorial_newParametrosNoStr(int id,char* nombre){

	eEditorial* nuevaEditorial = editorial_new();

		if (nuevaEditorial != NULL && nombre!= NULL) {
			if (!(editorial_setId(nuevaEditorial, id)
				&& editorial_setNombre(nuevaEditorial,nombre))) {

				free(nuevaEditorial);
				nuevaEditorial = NULL;
			}

		}

		return nuevaEditorial;

}







int editorial_setId(eEditorial* this,int id){

	int retorno=0;

		if(this!=NULL && id>=500){
			this->id=id;
			retorno=1;
		}

		return retorno;
}



int editorial_setNombre(eEditorial* this,char* nombre){

	int retorno=0;
		if(this!=NULL && nombre!=NULL && strlen(nombre)>0 && strlen(nombre)<100){
			strcpy(this->nombre,nombre);
			retorno=1;
		}

		return retorno;
}


int editorial_getId(eEditorial* this,int* id){

	int retorno=0;
	if(this!=NULL && id!=NULL){

		*id=this ->id;
		retorno=1;
	}

	return retorno;
}



int editorial_getNombre(eEditorial* this,char* nombre){

	int retorno=0;
	if(this!=NULL && nombre!=NULL){

		strcpy(nombre, this->nombre);
		retorno=1;
	}

	return retorno;
}


int editorial_buscarPorId(LinkedList* listaEditoriales, int id){

	int retorno=-1;
	eEditorial* auxEditorial;
	int len;
	int auxId;
	len=ll_len(listaEditoriales);




	if(listaEditoriales!=NULL){

		for(int i=0; i<len; i++){
			auxEditorial=(eEditorial*)ll_get(listaEditoriales,i);
			editorial_getId(auxEditorial,&auxId);

			if(auxEditorial!=NULL && auxId==id)
			 {
			     retorno=i;
			     break;
			 }
		}
	}

	return retorno;
}


int cargarDescripcionEditorial(LinkedList* listaEditoriales,int idEditorial,char* descripcion){

	int retorno=0;
	int len=ll_len(listaEditoriales);

	eEditorial* auxEdit=NULL;

	if(listaEditoriales!=NULL){

		for(int i=0; i<len; i++){
			auxEdit=ll_get(listaEditoriales,i);
			if(auxEdit->id == idEditorial){
				strcpy(descripcion,auxEdit->nombre);
				retorno=1;
				break;
			}
		}
	}

	return retorno;

}
