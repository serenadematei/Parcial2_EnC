/*
 * Editorial.h
 *
 *  Created on: 21 nov 2021
 *      Author: Sere
 */
#include "LinkedList.h"

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct{

	int id;
	char nombre[100];

}eEditorial;


#endif /* EDITORIAL_H_ */


//CONSTRUCTORES
eEditorial* editorial_new();
eEditorial* editorial_newParametrosStr(char* idStr,char* nombreStr);
eEditorial* editorial_newParametrosNoStr(int id,char* nombre);

//SETTERS
int editorial_setId(eEditorial* this,int id);
int editorial_setNombre(eEditorial* this,char* nombre);

//GETTERS
int editorial_getId(eEditorial* this,int* id);
int editorial_getNombre(eEditorial* this,char* nombre);

//BUSCAR EDITORIAL POR ID
int editorial_buscarPorId(LinkedList* listaEditoriales, int id);

int cargarDescripcionEditorial(LinkedList* listaEditoriales,int idEditorial,char* descripcion);
