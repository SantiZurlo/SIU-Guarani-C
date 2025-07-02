#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"




struct Nodo{
DatoPtr Dato;
NodoPtr siguiente;
};


DatoPtr getDato(NodoPtr n){
return n->Dato;
}

NodoPtr getSiguiente(NodoPtr n){
return n->siguiente;
}

void setDato(NodoPtr n, DatoPtr nuevoDato){
 n->Dato=nuevoDato;
}

void setSiguiente(NodoPtr n,NodoPtr nuevoSiguiente){
 n->siguiente=nuevoSiguiente;
}

NodoPtr crearNodo(DatoPtr d, NodoPtr s){
NodoPtr n= (NodoPtr) malloc(sizeof(struct Nodo));

n->Dato=d;
n->siguiente=s;

return n;
}

void liberarNodo(NodoPtr n){

free(n);
}
