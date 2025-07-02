#include <stdio.h>
#include <stdlib.h>
#include "guarani.h"

struct Guarani{
ListaPtr materias;
};

GuaraniPtr crearGuarani(){
GuaraniPtr g = malloc(sizeof(struct Guarani));

g->materias= crearLista();

return g;
}

void mostrarGuarani(GuaraniPtr g){
printf("\n-------BIENVENIDO AL SIU GUARANI--------\n");
system("pause");
system("cls");
mostrarListaGenerica(g->materias,mostrarMateriaVoid);
}

void agregarMateriasGuarani(GuaraniPtr g, MateriaPtr m){
insertarUltimo(g->materias, m);
}

void liberarGuarani(GuaraniPtr g){
liberarLista(g->materias);
free(g);
}

ListaPtr getListaMateriasGuarani(GuaraniPtr g){
return g->materias;
}
void setListaMateriasGuarani(GuaraniPtr g, ListaPtr nuevaLista){
 g->materias = nuevaLista;
}



