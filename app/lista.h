#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

ListaPtr crearLista ();

void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);


DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);

DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

int obtenerTamanio(ListaPtr lista);
ListaPtr duplicarLista(ListaPtr lista);
void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));
void liberarLista(ListaPtr lista);
NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion);
DatoPtr obtenerPosicion2(ListaPtr lista, int posicion) ;

void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
void ordenarListaPorInsercion(ListaPtr lista, int(*funcionComparar)(DatoPtr, DatoPtr));
void ordenarPorSeleccion(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr));
int busquedaSecuencial(ListaPtr lista, DatoPtr clave, int (*comparar)(DatoPtr, DatoPtr));
int busquedaBinaria(ListaPtr lista, DatoPtr clave, int (*comparar)(DatoPtr, DatoPtr));
void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr));

#endif // LISTA_H_INCLUDED
