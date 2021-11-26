/*
 ============================================================================
 Name        : segundoParcialLabo.c
 Author      : Serena Dematei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "get.h"
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "controller.h"
#include "parser.h"




int main(void) {


	setbuf(stdout,NULL);
	int opcion;
	char salida='n';
	char path[30];


	LinkedList* listaLibros = ll_newLinkedList();
	if(listaLibros==NULL){
	   printf("Ocurrio un problema al crear la LinkedList de libros\n");
	    exit(1);
	 }


	LinkedList* listaEditoriales = ll_newLinkedList();
	if(listaEditoriales==NULL){
		printf("Ocurrio un problema al crear la LinkedList de editoriales\n");
		exit(1);
	}






	 do{

			   opcion=menu();

		    	switch(opcion){
		    	    case 1:
                        if(ll_isEmpty(listaLibros)){
                        	getString(path,sizeof(path),"Ingrese nombre del archivo, sin extension:","Opcion invalida.\n");
                        	strcat(path,".csv");
                        	if(controller_cargarLibrosArchivoCsv(path,listaLibros)){

                        	 printf("Libros cargados desde el archivo de texto con exito.\n");


                        	 }
                        	 else
                        	 {
                        	    printf("Problemas al cargar los libros desde el archivo de texto.\n");
                        	 }
                        }
                        else
                        {
                        	printf("La lista de libros ya fue cargada.\n");
                        }
		    	    	system("pause");
		    	        break;
		    	    case 2:
		    	    	if(ll_isEmpty(listaEditoriales)){
		    	    	  getString(path,sizeof(path),"Ingrese nombre del archivo, sin extension:","Opcion invalida.\n");
		    	    	  strcat(path,".csv");

		    	    	    if(controller_cargarEditorialesArchivoCsv(path,listaEditoriales)){

		    	    	         printf("Editoriales cargadas desde el archivo de texto con exito.\n");


		    	    	    }
		    	    	    else
		    	    	    {
		    	    	         printf("Problemas al cargar las editoriales desde el archivo de texto.\n");
		    	    	    }
		    	    	}
		    	    	else
		    	    	{
		    	    		printf("La lista de editoriales ya fue cargada.\n");
		    	    	}
		    	    	system("pause");
		    	        break;
		    	    case 3:
                        if( !ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales) ){
                        	if(controller_ordenarLibros(listaLibros)){
                        		printf("Libros ordenados por autor ascendente con exito.\n");
                        	}
                        	else
                        	{
                        		printf("Ocurrio un problema al intentar ordenar los libros.\n");
                        	}

                       }
                       else
                        {
                       	  printf("Antes de ordenar, se deben cargar los libros y las editoriales desde los archivos.\n");
                        }
		    	    	system("pause");
		    	    	break;
		    	    case 4:
		    	    	if(!ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales) ){
		    	    	   if(!(controller_listarLibros(listaLibros,listaEditoriales))){
		    	    		   printf("Ocurrio un problema al listar los libros.\n");
		    	    	   }

		    	    	}
		    	    	else
		    	    	{
		    	    		printf("Antes de listar, se deben cargar los libros y las editoriales desde los archivos.\n");
		    	    	}

		    	    	system("pause");

		    	    	break;
		    	    case 5:
		    	    	if(!ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales)){

                           controller_filtrarEditorialMinotauro(listaLibros,listaEditoriales);

		    	    	}
		    	    	else
		    	    	{
		    	    		printf("Antes de listar, se deben cargar los libros y las editoriales desde los archivos.\n");
		    	    	}
		    	    	system("pause");
		    	    	break;


		    	    case 6:
                        if(!ll_isEmpty(listaLibros) && !ll_isEmpty(listaEditoriales)){

                        	if(controller_realizarDescuentos(listaLibros)){
                        		printf("Se creo el archivo.\n");
                        	}
                        	else
                        	{
                        		printf("problema");
                        	}
                        }

		    	    	system("pause");
		    	    	break;


		    	    case 7:
		    	    	verificarSalida(&salida);
		    	    	break;


		    	}

		    }while(salida=='n');






	return EXIT_SUCCESS;
}



/*
 *eLibro libro0 = {111, "Divina Comedia", "Dante Alighieri",3500,501};
	eLibro libro1 = {112, "Orgullo y prejuicio", "Jane Austen",1000,504};
	eLibro libro2 = {113, "Rayuela","Julio Cortazar",1200,505};
	eLibro libro3 = {114, "El extranjero","Albert Camus",2350,505};
	eLibro libro4 = {115, "El idiota","Fiodor Dostoievski",1156,502};
	eLibro libro5 = {116, "Mariposas negras","Nina Ferrari",1450,504};
	eLibro libro6 = {117, "El castillo","Fran Kafka",3210,501};
	eLibro libro7 = {118, "La montaña magica","Thomas Mann",2366,502};
	eLibro libro8 = {119, "Hamlet","William Shakespeare",5600,500};
	eLibro libro9 = {120, "Guerra y paz","Lev Tolstoi",4100, 504};
	eLibro libro10 = {121, "La señora Dalloway","Virgina Woolf",4800,500};
	eLibro libro11 = {122, "Antes del fin","Ernesto Sabato",2200,500};
	eLibro libro12 = {123, "El perdon","Florencia Bonelli",1640,503};
	eLibro libro13 = {124, "La historia","Elsa Morante",1890, 502};
	eLibro libro14 = {125, "El amante japones","Isabel Allende",3010,503};
	eLibro libro15 = {126, "Ulises","James Joyce",4999, 503};
	eLibro libro16 = {127, "El viejo y el mar","Ernest Hemingway",2645,503};
	eLibro libro17 = {128, "Almas muertas","Nikolai Gogol",1980,500};
	eLibro libro18 = {129, "Relatos de poder","Carlos Castaneda",2000,504};
	eLibro libro19 = {130, "La rosa de los vientos","Paula Bombara",1760,501};
	eLibro libro20 = {131, "El rey de la milonga","Roberto Fontanarrosa",2430,505};
*/

