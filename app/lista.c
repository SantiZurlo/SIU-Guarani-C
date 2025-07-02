#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Lista{

NodoPtr primero;

};

NodoPtr getPrimero(ListaPtr lista){
return lista->primero;
}
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero){
lista->primero=nuevoPrimero;
}

ListaPtr crearLista (){
ListaPtr l= malloc(sizeof(struct Lista));

l->primero=NULL;

return l;
}

void insertarPrimero(ListaPtr lista, DatoPtr dato){
NodoPtr n= crearNodo(dato,lista->primero);

lista->primero= n;

}
void insertarUltimo(ListaPtr lista, DatoPtr dato){

NodoPtr nuevoNodo= crearNodo(dato,NULL);

NodoPtr actual=lista->primero;

if(lista->primero==NULL){

    lista->primero=nuevoNodo;
}
else{
while(getSiguiente(actual)!=NULL){

    actual=getSiguiente(actual);
    }

setSiguiente(actual,nuevoNodo);


}
}
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){

NodoPtr nuevoNodo= crearNodo(dato,NULL);

if(posicion==1){
    setSiguiente(nuevoNodo,lista->primero);
    lista->primero=nuevoNodo;
    return;

}

NodoPtr actual=lista->primero;

for(int i=1;i<posicion && actual!=NULL; i++){
    actual=getSiguiente(actual);
}

if(actual==NULL){

    printf("La posicion excede a la lista");
    return;
}

setSiguiente(nuevoNodo,getSiguiente(actual));
setSiguiente(actual,nuevoNodo);
}



DatoPtr obtenerPrimero(ListaPtr lista){
return getDato(getPrimero(lista));
}

DatoPtr obtenerUltimo(ListaPtr lista){

NodoPtr actual=lista->primero;

while(getSiguiente(actual)!=NULL){

    actual=getSiguiente(actual);
}

return getDato(actual);
}

DatoPtr obtenerPosicion(ListaPtr lista, int posicion){

NodoPtr actual=lista->primero;
int contador=0;

while(actual != NULL && contador<posicion){
    actual=getSiguiente(actual);
    contador++;

}

return getDato(actual);

}


DatoPtr eliminarPrimero(ListaPtr lista){
NodoPtr temp=getPrimero(lista);

setPrimero(lista,getSiguiente(temp));

setSiguiente(temp,NULL);

return getDato(temp);

free(temp);
}


DatoPtr eliminarUltimo(ListaPtr lista){

NodoPtr actual=lista->primero;
NodoPtr anterior= NULL;

while(getSiguiente(actual)!=NULL){

    anterior=actual;
    actual=getSiguiente(actual);

}

if(anterior==NULL){

    lista->primero=NULL;
}
else{

    setSiguiente(anterior,NULL);

}

return getDato(actual);

    free(actual);

}

DatoPtr eliminarPosicion(ListaPtr lista, int posicion){
NodoPtr anterior=NULL;
NodoPtr actual=lista->primero;
int contador=1;

while(actual!=NULL && contador<posicion){
anterior=actual;
actual=getSiguiente(actual);
contador++;
}
if (anterior != NULL) {
setSiguiente(anterior,getSiguiente(actual));
}
else{
    setPrimero(lista,getSiguiente(actual));
}

return getDato(actual);
free(actual);

}


int obtenerTamanio(ListaPtr lista){

int contador=0;
NodoPtr  actual = lista->primero;

while(actual!=NULL){

    contador++;
    actual=getSiguiente(actual);
}

return contador;
}
ListaPtr duplicarLista(ListaPtr lista){

ListaPtr dupli=crearLista();

NodoPtr actualOri=lista->primero;

while(actualOri!=NULL){

    insertarUltimo(dupli,getDato(actualOri));
    actualOri=getSiguiente(actualOri);

}

return dupli;

}

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

NodoPtr actual=lista->primero;

while(actual!=NULL){

    mostrar(getDato(actual));

    actual=getSiguiente(actual);

}

printf("\n\n");

}
void liberarLista(ListaPtr lista){

NodoPtr aux;
NodoPtr actual=lista->primero;

while(actual!=NULL){

    aux=actual;
    actual=getSiguiente(actual);
    free(aux);
}

}
NodoPtr obtenerPosicionNodo(ListaPtr lista, int posicion){
NodoPtr actual=lista->primero;
int cont=0;

while(actual!=NULL && cont<posicion){

    actual=getSiguiente(actual);
    cont++;
}

if(actual==NULL){
    return NULL;
}
else{

    return actual;
}


}
DatoPtr obtenerPosicion2(ListaPtr lista, int posicion) {

NodoPtr nodo=obtenerPosicionNodo(lista,posicion);

if(nodo!=NULL){

    return getDato(nodo);
}else{

return NULL;
}

}


void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

int intercambio=0;
NodoPtr actual;
NodoPtr ultimo=NULL;

do{
    actual=lista->primero;
    intercambio=0;

    while(getSiguiente(actual) != ultimo){
        if(resultadoComparacion(getDato(actual),getDato(getSiguiente(actual)))<0){

            DatoPtr d = getDato(actual);
            setDato(actual,getDato(getSiguiente(actual)));
            setDato(getSiguiente(actual),d);

            intercambio=1;
        }
    actual=getSiguiente(actual);

    }
    ultimo=actual;
}while(intercambio);
}



void ordenarListaPorInsercion(ListaPtr lista, int(*funcionComparar)(DatoPtr, DatoPtr)){
  int j;
  for(int i = 0;i<obtenerTamanio(lista);i++){
    NodoPtr n1Aux = obtenerPosicionNodo(lista, i);
  void * datoN1Aux = getDato(n1Aux);
   j = i - 1;
   while (j>=0 && (funcionComparar(getDato(obtenerPosicionNodo(lista, j)), datoN1Aux)) == 1){
       setDato(obtenerPosicionNodo(lista, j+1), obtenerPosicion(lista, j));
       j--;
  }
  setDato(obtenerPosicionNodo(lista, j+1), datoN1Aux);
}

}
void ordenarPorSeleccion(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

NodoPtr actual=lista->primero;

while(actual != NULL){
    NodoPtr minimo= actual;
    NodoPtr sig= getSiguiente(actual);

while(sig != NULL){
    if(resultadoComparacion(getDato(minimo),getDato(sig))){

       minimo=sig;
    }
    sig = getSiguiente(sig);
}

    if(minimo != actual){

    DatoPtr aux = getDato(actual);
    setDato(actual,getDato(minimo));
    setDato(minimo,aux);

}

actual=getSiguiente(actual);
}
}


int busquedaSecuencial(ListaPtr lista, DatoPtr clave, int (*comparar)(DatoPtr, DatoPtr)){
NodoPtr actual=lista->primero;

for(int i = 0; i<obtenerTamanio(lista);i++){
    if(comparar(getDato(actual),clave)== 0){

        return i;
    }
    else{
        actual=getSiguiente(actual);
    }
}
return -1;
}
int busquedaBinaria(ListaPtr lista, DatoPtr clave, int (*comparar)(DatoPtr, DatoPtr)){
    NodoPtr inicio = lista->primero;
    NodoPtr fin = NULL;
    int tamanio = obtenerTamanio(lista);

    while (tamanio > 0) {
        int paso = tamanio / 2;
        NodoPtr mitad = inicio;
        for (int i = 0; i < paso; i++) {
            mitad = getSiguiente(mitad);
        }

        if (comparar(getDato(mitad), clave) < 0) {
            inicio = getSiguiente(mitad);
            tamanio -= paso + 1;
        } else {
            fin = mitad;
            tamanio = paso;
        }
    }

    if (fin != NULL && comparar(getDato(fin), clave) == 0) {

        int posicion = 0;
        NodoPtr actual = lista->primero;
        while (actual != fin) {
            actual = getSiguiente(actual);
            posicion++;
        }
        return posicion;
    } else {

        return -1;
    }
}






void insertarEnOrden(ListaPtr lista, DatoPtr dato, int (*comparar)(DatoPtr, DatoPtr)){
NodoPtr nuevoNodo = crearNodo(dato,NULL);

NodoPtr actual=lista->primero;
NodoPtr anterior=NULL;


while(actual !=NULL && comparar(getDato(actual),dato)>0){
    anterior=actual;
    actual=getSiguiente(actual);
}

if(anterior==NULL){
    setSiguiente(nuevoNodo,lista->primero);
    lista->primero=nuevoNodo;

}else{

setSiguiente(nuevoNodo,getSiguiente(anterior));
setSiguiente(anterior,nuevoNodo);



}

}
