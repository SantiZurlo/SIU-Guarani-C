#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"


struct Alumno{
int dni;
char nombre[25];
float promedio;
int cantidadMateriaAprobadas;
ListaPtr materiasAprobadas;
};


AlumnoPtr crearAlumno(char nombre[25],int dni){
AlumnoPtr a=(AlumnoPtr)malloc(sizeof(struct Alumno));
a->dni=dni;
strcpy(a->nombre,nombre);
a->promedio=0;
a->cantidadMateriaAprobadas=0;
a->materiasAprobadas=crearLista();

return a;
}

void mostrarAlumno(AlumnoPtr a){
printf("\n----ALUMNO----\n");
printf("\nNombre: %s\n",a->nombre);
printf("\nDNI: %d\n",a->dni);
printf("\nPromedio: %.2f\n",a->promedio);
printf("\nCantidad de materias aprobadas: %d\n",a->cantidadMateriaAprobadas);
printf("\nLista de Materias Aprobadas\n");
if (getPrimero(a->materiasAprobadas) != NULL) {
mostrarListaGenerica(a->materiasAprobadas, mostrarMateriaAprobadaDatoPtr);
}else{
printf("No hay materias aprobadas\n");
    }
}


void agregarMateriaAprobada(AlumnoPtr a, char nombre[25], int codigo, int nota) {
    MateriaAprobadaPtr m = crearMateriaAprobada(codigo, nombre, nota);
    insertarUltimo(a->materiasAprobadas, m);
    a->cantidadMateriaAprobadas++;

    calcularPromedio(a);
}

void calcularPromedio(AlumnoPtr a) {
    int sumaNotas = 0;
    int cantidadMaterias = 0;
    NodoPtr actual = getPrimero(a->materiasAprobadas);
    while (actual != NULL) {
        MateriaAprobadaPtr materia = (MateriaAprobadaPtr)getDato(actual);
        sumaNotas += getNotaMateriaAprobada(materia);
        cantidadMaterias++;
        actual = getSiguiente(actual);
    }
    if (cantidadMaterias > 0) {
        a->promedio = (float)sumaNotas / cantidadMaterias;
    } else {
        a->promedio = 0;
    }
}


void mostrarAlumnoVoid(void * d){
    AlumnoPtr a = *(AlumnoPtr*) d;

    mostrarAlumno(a);
}

int comparar(void* a, void* b) {
AlumnoPtr a1 = *(AlumnoPtr*)a;
AlumnoPtr a2 = *(AlumnoPtr*)b;

if (a1->cantidadMateriaAprobadas > a2->cantidadMateriaAprobadas) {
        return 1;
    } else if (a1->cantidadMateriaAprobadas < a2->cantidadMateriaAprobadas) {
        return -1;
    } else {
        if (a1->promedio > a2->promedio) {
            return 1;
        } else if (a1->promedio < a2->promedio) {
            return -1;
        } else {
            return 0;
        }
    }
}



void inscribirAlumnoEnMateria(AlumnoPtr alumno, MateriaPtr materia) {

if (getCupo(materia) > 0) {
    insertarEnOrden(getListaAlumnos(materia), alumno,comparar);
    setCupo(materia,getCupo(materia)-1);
}else{
ListaPtr l = crearLista();
insertarEnOrden(l, alumno,comparar);
NodoPtr actual = getPrimero(l);
    while (actual != NULL) {
    encolar(getColaAlumnos(materia), getDato(actual));
    actual = getSiguiente(actual);
}
    liberarLista(l);
};
}



ListaPtr getListaMatAprobadas(AlumnoPtr a){
return a->materiasAprobadas;
}
char* getNombreAlumno(AlumnoPtr a){
return a->nombre;
}
int getCantAprobadasAlumno(AlumnoPtr a){
return a->cantidadMateriaAprobadas;
}
float getPromedioAlumno(AlumnoPtr a){
return a->promedio;
}
int getDNIAlumno(AlumnoPtr a){
return a->dni;
}

void setListaMatAprobadas(AlumnoPtr a,ListaPtr nuevaLista){
a->materiasAprobadas=nuevaLista;
}
void setNombreAlumno(AlumnoPtr a,char nuevoNombre[25]){
strcpy(a->nombre,nuevoNombre);
}
void setCantAprobadasAlumno(AlumnoPtr a,int nuevaCant){
a->cantidadMateriaAprobadas=nuevaCant;
}
void setPromedioAlumno(AlumnoPtr a,float nuevoProm){
a->promedio=nuevoProm;
}
void setDNIAlumno(AlumnoPtr a,int nuevoDni){
a->dni=nuevoDni;
}



