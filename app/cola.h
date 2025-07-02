#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodo.h"

struct Cola;

typedef struct Cola * ColaPtr;


NodoPtr getPrimeroCola(ColaPtr c);
void setPrimeroCola(ColaPtr c,NodoPtr nuevoPrimero);

NodoPtr getUltimo(ColaPtr c);
void setUltimo(ColaPtr c, NodoPtr nuevoUltimo);


ColaPtr crearCola();
void encolar(ColaPtr c, DatoPtr d);
DatoPtr desencolar(ColaPtr c);
ColaPtr duplicarCola(ColaPtr c);
void liberarCola(ColaPtr c);
void liberarColaMostrar(ColaPtr c,void (*mostrar)(void *));

#endif // COLA_H_INCLUDED
