
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Libro.h"
#include "LinkedList.h"

eLibro* libro_new(){

	eLibro* nuevoLibro=(eLibro*)malloc(sizeof(eLibro));
	return nuevoLibro;
}




eLibro* libro_newParametrosStr(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* idEditorialStr){

	eLibro* nuevoLibro = libro_new();

	if (nuevoLibro != NULL && idStr != NULL && tituloStr!= NULL
			&& autorStr != NULL && precioStr != NULL && idEditorialStr!=NULL) {
		if (!(libro_setId(nuevoLibro, atoi(idStr))
				&& libro_setTitulo(nuevoLibro, tituloStr)
				&& libro_setAutor(nuevoLibro,autorStr)
				&& libro_setPrecio(nuevoLibro, atof(precioStr))
				&& libro_setIdEditorial(nuevoLibro, atoi(idEditorialStr)))) {

			free(nuevoLibro);
			nuevoLibro= NULL;
		}

	}

	return nuevoLibro;

}



eLibro* libro_newParametrosNoStr(int id,char* titulo,char* autor,float precio, int idEditorial){

	eLibro* nuevoLibro = libro_new();

		if (nuevoLibro != NULL && titulo!= NULL && autor!=NULL) {
			if (!(libro_setId(nuevoLibro, id)
				&& libro_setTitulo(nuevoLibro,titulo)
				&& libro_setAutor(nuevoLibro,autor)
				&& libro_setPrecio(nuevoLibro,precio)
			    && libro_setIdEditorial(nuevoLibro,idEditorial))) {

				free(nuevoLibro);
				nuevoLibro = NULL;
			}

		}

		return nuevoLibro;

}







int libro_setId(eLibro* this,int id){

	int retorno=0;

		if(this!=NULL && id>=110){
			this->id=id;
			retorno=1;
		}

		return retorno;
}



int libro_setTitulo(eLibro* this,char* titulo){

	int retorno=0;
		if(this!=NULL && titulo!=NULL && strlen(titulo)>0 && strlen(titulo)<100){
			strcpy(this->titulo,titulo);
			retorno=1;
		}

		return retorno;
}

int libro_setAutor(eLibro* this,char* autor){

	int retorno=0;
		if(this!=NULL && autor!=NULL && strlen(autor)>0 && strlen(autor)<100){
			strcpy(this->autor,autor);
			retorno=1;
		}

		return retorno;
}





int libro_setPrecio(eLibro* this,float precio){

	int retorno = 0;
	if (this != NULL && precio>=0) {
		this-> precio = precio;
		retorno = 1;
	}

	return retorno;
}


int libro_setIdEditorial(eLibro* this,int idEditorial){

	int retorno = 0;
	if (this != NULL && idEditorial >= 500) {
		this-> idEditorial= idEditorial;
		retorno = 1;
	}

	return retorno;
}





int libro_getId(eLibro* this,int* id){

	int retorno=0;
	if(this!=NULL && id!=NULL){

		*id=this ->id;
		retorno=1;
	}

	return retorno;
}



int libro_getTitulo(eLibro* this,char* titulo){

	int retorno=0;
	if(this!=NULL && titulo!=NULL){

		strcpy(titulo, this->titulo);
		retorno=1;
	}

	return retorno;
}

int libro_getAutor(eLibro* this,char* autor){

	int retorno=0;
	if(this!=NULL && autor!=NULL){

		strcpy(autor, this->autor);
		retorno=1;
	}

	return retorno;
}


int libro_getPrecio(eLibro* this,float* precio){

	int retorno=0;
		if(this!=NULL && precio!=NULL){

			*precio=this->precio;
			retorno=1;
		}

		return retorno;
}


int libro_getIdEditorial(eLibro* this,int* idEditorial){

	int retorno=0;
		if(this!=NULL && idEditorial!=NULL){

			*idEditorial=this->idEditorial;
			retorno=1;
		}

		return retorno;
}



void libro_delete(eLibro* this){

	if (this != NULL) {
		free(this);
		this=NULL;
	}

}


int libro_buscarPorId(LinkedList* listaLibros, int id){

	int retorno=-1;
	eLibro* auxLibro;
	int len;
	int auxId;
	len=ll_len(listaLibros);




	if(listaLibros!=NULL){

		for(int i=0; i<len; i++){
			auxLibro=(eLibro*)ll_get(listaLibros,i);
			libro_getId(auxLibro,&auxId);

			if(auxLibro!=NULL && auxId==id)
			 {
			     retorno=i;
			     break;
			 }
		}
	}

	return retorno;
}

int libro_compararPorAutor(void* libro1, void* libro2){

	int retorno = 0;
	eLibro* libroA = NULL;
	eLibro* libroB = NULL;

	if(libro1 != NULL && libro2 !=NULL)
	{
		libroA  = (eLibro*) libro1;
	    libroB = (eLibro*)  libro2;

	        if(strcmp(libroA->autor,libroB->autor)==1)
	        {
	            retorno = 1;
	        }

	}

	    return retorno;
}

