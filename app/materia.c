#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "alumno.h"

struct Materia{
int codigo;
char nombre[25];
int cupo;
ListaPtr alumnosInscriptos;
ColaPtr alumnosEspera;
};


MateriaPtr crearMateria(int codigo,char nombre[25],int cupo){
MateriaPtr m = (MateriaPtr)malloc(sizeof(struct Materia));

m->codigo=codigo;
strcpy(m->nombre,nombre);
m->cupo=cupo;
m->alumnosInscriptos=crearLista();
m->alumnosEspera=crearCola();


return m;
}

void destruirMateria(MateriaPtr materia){
    liberarLista(materia->alumnosInscriptos);
    liberarCola(materia->alumnosEspera);
    free(materia);
}

void mostrarMateria(MateriaPtr m){
printf("\n----MATERIA----\n");
printf("\nNombre:%s\n",m->nombre);
printf("\nCodigo: %d\n",m->codigo);
system("pause");
system("cls");
printf("\n---ALUMNOS INSCRIPTOS EN LA MATERIA----\n");
if(getPrimero(m->alumnosInscriptos)!=NULL){
mostrarListaGenerica(m->alumnosInscriptos,mostrarAlumnoVoid);
}else{
printf("\n No hay alumnos inscriptos\n");
}
system("pause");
system("cls");

if(getPrimeroCola(m->alumnosEspera)!=NULL){
printf("\n-----ALUMNOS EN COLA PARA INSCRIBIRSE------\n");
 liberarColaMostrar(m->alumnosEspera,mostrarAlumnoVoid);
}else{

printf("\n-----NO HAY COLA DE ESPERA------\n");
}
system("pause");
system("cls");
}



void mostrarMateriaVoid(DatoPtr m){
MateriaPtr mat = *(MateriaPtr*)m;
mostrarMateria(mat);
}




int getCodigo(MateriaPtr m){
return m->codigo;
}
char* getNombre(MateriaPtr m){
return m->nombre;
}
ColaPtr getColaAlumnos(MateriaPtr m){
return m->alumnosEspera;
}
int getCupo(MateriaPtr m){
return m->cupo;
}
ListaPtr getListaAlumnos(MateriaPtr m){
return m->alumnosInscriptos;
}



void setCodigo(MateriaPtr m,int nuevoCodigo){
m->codigo=nuevoCodigo;
}
void setNombre(MateriaPtr m,char nuevoNombre[25]){
strcpy(m->nombre,nuevoNombre);
}
void setColaAlumnos(MateriaPtr m,ColaPtr nuevaCola){
m->alumnosEspera=nuevaCola;
}
void setCupo(MateriaPtr m, int nuevoCupo){
m->cupo=nuevoCupo;
}
void setListaAlumnos(MateriaPtr m,ListaPtr nuevaLista){
m->alumnosInscriptos=nuevaLista;
}

