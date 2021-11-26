#include <stdio.h>
#include <stdlib.h>
#include "Get.h"
#include "menu.h"


int menu(){

	int opcion;

	        printf("\n\n\n");
	        printf("            **** MENU DE OPCIONES ****\n");
			printf("1. Cargar los datos de los libros desde el archivo csv.\n");
			printf("2. Cargar los datos de las editoriales desde el archivo csv.\n");
			printf("3. Ordenar libros por autor\n");
			printf("4. Listar libros\n");
			printf("5. Listar libros de editorial Minotauro\n");
			printf("6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.\n");
			printf("7. Salir\n");
			opcion=getOnlyInt("Ingrese opcion (1-7):","Opcion invalida.\n");


	return opcion;
}


int menuModificaciones(){

	int opcion;

	printf("\n\n  ***MENU MODIFICACIONES***\n");
	printf("1-\tModificar titulo\n");
	printf("2-\tModificar autor\n");
	printf("3-\tModificar precio\n");
	printf("4-\tModificar editorial\n");
	printf("5-\tCancelar cambios y salir\n");
	printf("6-\tGuardar cambios y salir\n");


	utn_getNumero(&opcion,"Enter option:","Error.\n",1,6,10);
	return opcion;

}


int menuOrdenamiento(){

	int opcion;


	printf("\n\n  ***MENU ORDENAMIENTO DE LIBROS***\n");
	printf("1-\tOrdenar por autor\n");
	printf("2-\tOrdenar por titulo\n");
	printf("3-\tOrdenar por id\n");
	printf("4-\tOrdenar por precio\n");
	printf("5-\tOrdenar por editorial\n");
	printf("6-\tVolver al menu principal\n");


	opcion=getOnlyInt("Ingrese opcion (1-6):","Opcion invalida.\n");


	return opcion;

}

char verificarSalida(char *pSalida) {
	int todoOk = 0;
	char opcion;

	if (pSalida != NULL) {

		fflush(stdin);
		utn_getCaracter(&opcion,"Confirma salida? (s/n):","Opcion invalida.\n",'s','n',10);

		*pSalida = opcion;
		todoOk = 1;
	}

	return todoOk;

}
