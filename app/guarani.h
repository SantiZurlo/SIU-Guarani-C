#ifndef GUARANI_H_INCLUDED
#define GUARANI_H_INCLUDED
#include "lista.h"
#include "cola.h"
#include "materia.h"

struct Guarani;

typedef struct Guarani * GuaraniPtr;

GuaraniPtr crearGuarani();
void mostrarGuarani(GuaraniPtr g);
void agregarMateriasGuarani(GuaraniPtr g, MateriaPtr m);

void liberarGuarani(GuaraniPtr g);

ListaPtr getListaMateriasGuarani(GuaraniPtr g);
void setListaMateriasGuarani(GuaraniPtr g, ListaPtr nuevaLista);


#endif // GUARANI_H_INCLUDED
