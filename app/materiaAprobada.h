#ifndef MATERIAAPROBADA_H_INCLUDED
#define MATERIAAPROBADA_H_INCLUDED
#include "lista.h"
#include "cola.h"

struct MateriaAprobada;

typedef struct MateriaAprobada * MateriaAprobadaPtr;

MateriaAprobadaPtr crearMateriaAprobada(int codigo,char nombre[25],int nota);
void mostrarMateriaAprobada(MateriaAprobadaPtr m);
void mostrarMateriaAprobadaDatoPtr(DatoPtr d);



int getCodigoMateriaAprobada(MateriaAprobadaPtr materia);
char *  getNombreMateriaAprobada(MateriaAprobadaPtr materia);
int getNotaMateriaAprobada(MateriaAprobadaPtr materia);

void setCodigoMateriaAprobada(MateriaAprobadaPtr materia,int nuevoCodigo);
void  setNombreMateriaAprobada(MateriaAprobadaPtr materia,char nuevoNombre[25]);
void setNotaMateriaAprobada(MateriaAprobadaPtr materia,int nuevaNota);

#endif // MATERIAAPROBADA_H_INCLUDED
