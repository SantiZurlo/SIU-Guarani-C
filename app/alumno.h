#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "lista.h"
#include "cola.h"
#include "materia.h"
#include "materiaAprobada.h"

struct Alumno;

typedef struct Alumno * AlumnoPtr;


AlumnoPtr crearAlumno(char nombre[25],int dni);
void mostrarAlumno(AlumnoPtr a);
void agregarMateriaAprobada(AlumnoPtr a, char nombre[25],int codigo, int nota);

void calcularPromedio(AlumnoPtr a);
void mostrarAlumnoVoid(void * d);
int comparar(void* a, void* b);

void inscribirAlumnoEnMateria(AlumnoPtr alumno, MateriaPtr materia);



ListaPtr getListaMatAprobadas(AlumnoPtr a);
char* getNombreAlumno(AlumnoPtr a);
int getCantAprobadasAlumno(AlumnoPtr a);
float getPromedioAlumno(AlumnoPtr a);
int getDNIAlumno(AlumnoPtr a);

void setListaMatAprobadas(AlumnoPtr a,ListaPtr nuevaLista);
void setNombreAlumno(AlumnoPtr a,char nuevoNombre[25]);
void setCantAprobadasAlumno(AlumnoPtr a,int nuevaCant);
void setPromedioAlumno(AlumnoPtr a,float nuevoProm);
void setDNIAlumno(AlumnoPtr a,int nuevoDni);
#endif // ALUMNO_H_INCLUDED
