#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "Get.h"
#include "parser.h"
#include "menu.h"
#include "controller.h"


int controller_cargarLibrosArchivoCsv(char* path , LinkedList* lista)
{
	int retorno=0;
    FILE* pFile;

	if(path!=NULL && lista!=NULL){

		pFile= fopen(path,"r");

		if(pFile != NULL){

		  if(parser_librosFromText(pFile,lista))
			{
			  retorno=1;
			}

			fclose(pFile);

		}
		else
		{
			printf("El archivo de texto no existe. \n");

		}


	}
    return retorno;
}


int controller_cargarEditorialesArchivoCsv(char* path , LinkedList* lista)
{
	int retorno=0;
    FILE* pFile;

	if(path!=NULL && lista!=NULL){

		pFile= fopen(path,"r");

		if(pFile != NULL){

		  if(parser_editorialesFromText(pFile,lista))
			{
			  retorno=1;
			}

			fclose(pFile);

		}
		else
		{
			printf("El archivo de texto no existe.\n");

		}


	}
    return retorno;
}


int controller_listarLibros(LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	int retorno=0;
	int len;

	if(listaLibros!=NULL && listaEditoriales!=NULL){

	len= ll_len(listaLibros);
	printf("Id                 Titulo                             Autor                            Precio                     Editorial\n");
	for(int i=0; i<len; i++){
		controller_listarUnLibro((eLibro*)ll_get(listaLibros,i),listaEditoriales);
	}
	    printf("\n\n");
	    retorno=1;
	}

   return retorno;

}



int controller_listarUnLibro(eLibro* this, LinkedList* listaEditoriales){

	int retorno=0;

	int id;
	char titulo[100];
	char autor[100];
	float precio;
	int idEditorial;

	char descripcion[100];


	if(this!=NULL
	&& libro_getId(this,&id)
	&& libro_getTitulo(this,titulo)
	&& libro_getAutor(this,autor)
	&& libro_getPrecio(this,&precio)
	&& libro_getIdEditorial(this ,&idEditorial)){


       if(cargarDescripcionEditorial(listaEditoriales,idEditorial,descripcion)){

    	   printf("%d            %15s                      %15s                    %5.2f                 %15s\n",
    	   				id,
    	   				titulo,
    	   				autor,
    	   				precio,
    	   				descripcion);
    	   		retorno=1;

       }

	}

	return retorno;
}




int controller_ordenarLibros(LinkedList* listaLibros)
{
	int retorno= 0;
	int criterio=1; //1 ascendente   0 descendente


	    if(listaLibros != NULL)
	    {

	    	 if(!(ll_sort(listaLibros,libro_compararPorAutor,criterio))){


	    		 retorno=1;
	    	 }


	    }


	    return retorno;

}



int controller_guardarListaFiltradaArchivoCsv(char* path , LinkedList* lista){

	int retorno=0;
	eLibro* auxLibro;
	FILE* pFile;


	int id;
	char titulo[100];
	char autor[100];
	float precio;
	int idEditorial;


		if(path!=NULL && lista!=NULL){

			pFile= fopen(path,"w");
			if (pFile == NULL) {

				printf("No se pudo abrir el archivo\n");
				exit(1);

			}

			fprintf(pFile,"ID,Titulo,Autor,Precio,Id Editorial\n");

			for(int i=0; i<ll_len(lista); i++){

				auxLibro=ll_get(lista,i);
				if(auxLibro!=NULL &&
						libro_getId(auxLibro,&id) &&
						libro_getTitulo(auxLibro,titulo) &&
						libro_getAutor(auxLibro,autor) &&
						libro_getPrecio(auxLibro,&precio) &&
					    libro_getIdEditorial(auxLibro,&idEditorial)){

					fprintf(pFile,"%d,%s,%s,%.2f,%d\n",id,titulo,autor,precio,idEditorial);



					retorno=1;
				}



			}

			fclose(pFile);
			auxLibro=NULL;

		}


	    return retorno;
}








int controller_filtrarEditorialMinotauro(LinkedList* listaLibros,LinkedList* listaEditoriales){

	int retorno=0;
	LinkedList* listaFiltrada=NULL;
	eLibro* auxLibro=NULL;

	if(listaLibros!=NULL){

		listaFiltrada=ll_filter(listaLibros,esEditorialMinotauro);
		if(listaFiltrada!=NULL){

			controller_guardarListaFiltradaArchivoCsv("editorialMinotauro.csv",listaFiltrada);


			for(int i=0; i<ll_len(listaFiltrada);i++){
				auxLibro=ll_get(listaFiltrada,i);
				controller_listarUnLibro(auxLibro,listaEditoriales);
			}
			retorno=1;
		}

	}


	return retorno;
}



int realizarDescuento(void* pElement){

	int retorno=-1;

	eLibro* auxLibro=NULL;
	int descuento;
	float precio;
	float precioFinal;



			if(pElement!=NULL){

				auxLibro=(eLibro*)pElement;
				libro_getPrecio(auxLibro,&precio);



					if( (esEditorialPlaneta(pElement) && precioMayorATrescientos(pElement))){


						descuento=precio*0.20;
						precioFinal= precio-descuento;
						libro_setPrecio(auxLibro,precioFinal);


                       retorno=1;


					}
				  else if( (esEditorialSigloXXI(pElement) && precioMenorADoscientos(pElement)) ){


						descuento=precio*0.10;
						precioFinal= precio-descuento;
						libro_setPrecio(auxLibro,precioFinal);


                        retorno=1;

				  }




			}




	return retorno;
}






int precioMayorATrescientos(void* pElement){

	int retorno=0;
	eLibro* auxLibro=NULL;
	float precio;


			if(pElement!=NULL){

				auxLibro=(eLibro*)pElement;
				libro_getPrecio(auxLibro,&precio);
		        if(precio>=300){
		        	retorno=1;
		        }
			}

			return retorno;


}

int precioMenorADoscientos(void* pElement){

	int retorno=0;
	eLibro* auxLibro=NULL;
	float precio;


			if(pElement!=NULL){

				auxLibro=(eLibro*)pElement;
				libro_getPrecio(auxLibro,&precio);
		        if(precio<=200){
		        	retorno=1;
		        }
			}

			return retorno;


}



int esEditorialPlaneta(void* pElement){

	int retorno=0;
	eLibro* auxLibro=NULL;
	int idEditorial;


		if(pElement!=NULL){

			auxLibro=(eLibro*)pElement;
			libro_getIdEditorial(auxLibro,&idEditorial);
	        if(idEditorial==500){
	        	retorno=1;
	        }
		}

		return retorno;
}


int esEditorialSigloXXI(void* pElement){

	int retorno=0;
	eLibro* auxLibro=NULL;
	int idEditorial;


		if(pElement!=NULL){

			auxLibro=(eLibro*)pElement;
			libro_getIdEditorial(auxLibro,&idEditorial);
	        if(idEditorial==501){
	        	retorno=1;
	        }
		}

		return retorno;
}





int esEditorialMinotauro(void* pElement){

	int retorno=0;
	eLibro* auxLibro=NULL;
	int idEditorial;


		if(pElement!=NULL){

			auxLibro=(eLibro*)pElement;
			libro_getIdEditorial(auxLibro,&idEditorial);
	        if(idEditorial==503){
	        	retorno=1;
	        }
		}

		return retorno;
}


int controller_contadorLibrosEditorialMinotauro(LinkedList* listaLibros){


	int contador=0;

	if(listaLibros!=NULL){

		contador=ll_count(listaLibros,esEditorialMinotauro);

	}

	return contador;
}


int controller_realizarDescuentos(LinkedList* listaLibros){

	int retorno=0;
	LinkedList* pLista=NULL;

	if(listaLibros!=NULL){

	   pLista=ll_map (listaLibros,realizarDescuento);
	   if(pLista!=NULL){

		  controller_guardarListaFiltradaArchivoCsv("mapeado.csv",pLista);
		  retorno=1;
	   }
	}

	return retorno;
}

