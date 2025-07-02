#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila.h"


struct Pila{
NodoPtr ultimo;
};



NodoPtr getUltimoPila(PilaPtr p){
return p->ultimo;
}
void setUlrimoPila(PilaPtr p, NodoPtr nuevoUltimo){
p->ultimo=nuevoUltimo;
}

PilaPtr crearPila(){
 PilaPtr p= malloc(sizeof(struct Pila));
 p->ultimo=NULL;

  return p;
}



void apilar(PilaPtr p, DatoPtr d){

NodoPtr nuevoNodo=crearNodo(d,NULL);

if(p->ultimo==NULL){

    p->ultimo=nuevoNodo;
}
else{



setSiguiente(nuevoNodo,p->ultimo);
p->ultimo=nuevoNodo;

}

}



DatoPtr desapilar (PilaPtr p){
 if (p == NULL || p->ultimo == NULL) {
        return NULL;
    }

    NodoPtr nodoAEliminar = p->ultimo;
    DatoPtr dato = getDato(nodoAEliminar);
    p->ultimo = getSiguiente(nodoAEliminar);
    liberarNodo(nodoAEliminar);

return dato;
}

PilaPtr duplicarPila(PilaPtr p){

PilaPtr dupli=crearPila();
PilaPtr aux=crearPila();

while(p->ultimo!=NULL){
    DatoPtr d= desapilar(p);
    apilar(dupli,d);
    apilar(aux,d);
}

while(aux->ultimo!=NULL){
    DatoPtr d= desapilar(aux);
    apilar(p,d);
}

free(aux);
return dupli;
}

void liberarPila(PilaPtr p){

while(p->ultimo!=NULL){

desapilar(p);
}
free(p);

}


void liberarPilaMostrar(PilaPtr p, void (*mostrar)(void*)){

while(p->ultimo!=NULL){

DatoPtr d=desapilar(p);
mostrar(d);
}
free(p);

}
