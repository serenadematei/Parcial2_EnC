/*
 * Libro.h
 *
 *  Created on: 21 nov 2021
 *      Author: Sere
 */

#include "LinkedList.h"
#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct{

	int id;
	char titulo[100];
	char autor[100];
	float precio;
	int idEditorial;

}eLibro;


#endif /* LIBRO_H_ */


//CONSTRUCTORES
eLibro* libro_new();
eLibro* libro_newParametrosStr(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* idEditorialStr);
eLibro* libro_newParametrosNoStr(int id,char* titulo,char* autor,float precio, int idEditorial);

//SETTERS
int libro_setId(eLibro* this,int id);
int libro_setTitulo(eLibro* this,char* titulo);
int libro_setAutor(eLibro* this,char* autor);
int libro_setPrecio(eLibro* this,float precio);
int libro_setIdEditorial(eLibro* this,int idEditorial);

//GETTERS
int libro_getId(eLibro* this,int* id);
int libro_getTitulo(eLibro* this,char* titulo);
int libro_getAutor(eLibro* this,char* autor);
int libro_getPrecio(eLibro* this,float* precio);
int libro_getIdEditorial(eLibro* this,int* idEditorial);

//DELETE
void libro_delete(eLibro* this);

//BUSCAR LIBRO POR ID
int libro_buscarPorId(LinkedList* listaLibros, int id);

//COMPARAR
int libro_compararPorAutor(void* libro1, void* libro2);
