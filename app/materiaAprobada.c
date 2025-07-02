#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materiaAprobada.h"

struct MateriaAprobada{
int codigo;
char nombre[25];
int nota;
};


MateriaAprobadaPtr crearMateriaAprobada(int codigo,  char nombre[25], int nota) {
    MateriaAprobadaPtr materiaAprobada = malloc(sizeof(struct MateriaAprobada));
    materiaAprobada->codigo = codigo;
    strcpy(materiaAprobada->nombre, nombre);
    materiaAprobada->nota = nota;
    return materiaAprobada;
}
void mostrarMateriaAprobada(MateriaAprobadaPtr m){
printf("\n----MATERIA APROBADA----\n");
printf("\nNombre:%s\n",m->nombre);
printf("\nCodigo: %d\n",m->codigo);
printf("\nNota: %d\n",m->nota);

}


void mostrarMateriaAprobadaDatoPtr(DatoPtr d) {
    MateriaAprobadaPtr m = (MateriaAprobadaPtr)d;

    printf("Materia: %s, Codigo: %d, Nota: %d\n", m->nombre, m->codigo, m->nota);
}

int getCodigoMateriaAprobada(MateriaAprobadaPtr materia) {
    return materia->codigo;
}

char *  getNombreMateriaAprobada(MateriaAprobadaPtr materia){
    return materia->nombre;
}
int getNotaMateriaAprobada(MateriaAprobadaPtr materia){
    return materia->nota;
}

void setCodigoMateriaAprobada(MateriaAprobadaPtr materia,int nuevoCodigo){
     materia->codigo=nuevoCodigo;
}
void  setNombreMateriaAprobada(MateriaAprobadaPtr materia,char nuevoNombre[25]){
strcpy(materia->nombre,nuevoNombre);
}
void setNotaMateriaAprobada(MateriaAprobadaPtr materia,int nuevaNota){
materia->nota=nuevaNota;
}
