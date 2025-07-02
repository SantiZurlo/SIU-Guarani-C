#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"
#include "cola.h"

struct Cola{
NodoPtr primero;
NodoPtr ultimo;

};




NodoPtr getPrimeroCola(ColaPtr c){
return c->primero;
}
void setPrimeroCola(ColaPtr c,NodoPtr nuevoPrimero){
c->primero=nuevoPrimero;
}

NodoPtr getUltimo(ColaPtr c){
return c->ultimo;
}
void setUltimo(ColaPtr c, NodoPtr nuevoUltimo){
c->ultimo=nuevoUltimo;
}


ColaPtr crearCola(){
ColaPtr cola= malloc(sizeof(struct Cola));

cola->primero=NULL;
cola->ultimo=NULL;

return cola;

}
void encolar(ColaPtr c, DatoPtr d){

NodoPtr nuevoNodo= crearNodo(d,NULL);
NodoPtr actual= c->primero;

if(actual==NULL){

  c->primero=nuevoNodo;
  c->ultimo=nuevoNodo;
}
else{
    setSiguiente(c->ultimo,nuevoNodo);
    c->ultimo=nuevoNodo;
}

}




DatoPtr desencolar(ColaPtr c){

NodoPtr actual=c->primero;
DatoPtr dato=getDato(actual);

c->primero=getSiguiente(actual);

if(c->primero==NULL){
   c->ultimo=NULL;
}

liberarNodo(actual);
return dato;

}




ColaPtr duplicarCola(ColaPtr c){
ColaPtr dupli= crearCola();
ColaPtr aux= crearCola();


while(c->primero !=NULL){
 DatoPtr d=desencolar(c);
 encolar(aux,d);
 encolar(dupli,d);

}

while(aux->primero!=NULL){
 DatoPtr d=desencolar(aux);
 encolar(c,d);
}

liberarCola(aux);
return dupli;

}







void liberarCola(ColaPtr c){

while(c->primero!=NULL){

desencolar(c);

    }
    free(c);

}

void liberarColaMostrar(ColaPtr c,void (*mostrar)(void *)){

while(c->primero !=NULL){

DatoPtr d= desencolar(c);
mostrar(d);
}
free(c);
}


