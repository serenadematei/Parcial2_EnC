
#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */

/** \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_cargarLibrosArchivoCsv(char* path , LinkedList* lista);




/** \brief Carga los datos de las editoriales desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_cargarEditorialesArchivoCsv(char* path , LinkedList* lista);



int controller_listarLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);
int controller_listarUnLibro(eLibro* this, LinkedList* listaEditoriales);
int controller_listarEditoriales(LinkedList* listaEditoriales);
int controller_listarUnaEditorial(eEditorial* this);



int controller_ordenarLibros(LinkedList* listaLibros);
int controller_guardarListaFiltradaArchivoCsv(char* path , LinkedList* lista);


//contadores
int controller_contadorLibrosEditorialMinotauro(LinkedList* listaLibros);

//filtros
int controller_filtrarEditorialMinotauro(LinkedList* listaLibros,LinkedList* listaEditoriales);

//pFUNC de Filtros
int esEditorialMinotauro(void* pElement);


int realizarDescuento(void* pElement);
int controller_realizarDescuentos(LinkedList* listaLibros);
int esEditorialPlaneta(void* pElement);
int precioMayorATrescientos(void* pElement);

int precioMenorADoscientos(void* pElement);
int esEditorialSigloXXI(void* pElement);


/*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_ListOneEmployee(Employee* this);

int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
*/
