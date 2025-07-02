#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include "lista.h"
#include "cola.h"


struct Materia;

typedef struct Materia * MateriaPtr;

MateriaPtr crearMateria(int codigo,char nombre[25],int cupo);
void destruirMateria(MateriaPtr materia);


void mostrarMateria(MateriaPtr m);
void mostrarAlumnosInscriptos(ListaPtr l);
void mostrarMateriaVoid(DatoPtr d);

int getCodigo(MateriaPtr m);
char* getNombre(MateriaPtr m);
ColaPtr getColaAlumnos(MateriaPtr m);
int getCupo(MateriaPtr m);
ListaPtr getListaAlumnos(MateriaPtr m);
ListaPtr getMateriasRequeridas(MateriaPtr materia);


void setCodigo(MateriaPtr m,int nuevoCodigo);
void setNombre(MateriaPtr m,char nuevoNombre[25]);
void setColaAlumnos(MateriaPtr m,ColaPtr nuevaCola);
void setCupo(MateriaPtr m, int nuevoCupo);
void setListaAlumnos(MateriaPtr m,ListaPtr nuevaLista);



#endif // MATERIA_H_INCLUDED
