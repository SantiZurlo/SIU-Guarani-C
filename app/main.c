#include <stdio.h>
#include <stdlib.h>
#include "materia.h"
#include "materiaAprobada.h"
#include "guarani.h"
#include "alumno.h"


int main()
{
/// CREAMOS LAS MATERIAS
MateriaPtr m1 = crearMateria(1,"Politica",3);
MateriaPtr m2 = crearMateria(2,"Biologia",3);
MateriaPtr m3 = crearMateria(3,"Geografia",3);
MateriaPtr m4 = crearMateria(4,"Historia",3);
MateriaPtr m5 = crearMateria(5,"Deporte",3);

/// CREAMOS EL SIU GUARANI
GuaraniPtr g = crearGuarani();
agregarMateriasGuarani(g,&m1);
agregarMateriasGuarani(g,&m2);
agregarMateriasGuarani(g,&m3);
agregarMateriasGuarani(g,&m4);
agregarMateriasGuarani(g,&m5);


/// CREAMOS LOS ALUMNOS
AlumnoPtr a1 = crearAlumno("Pepe Lopez",45903281);
AlumnoPtr a2 = crearAlumno("Santiago Zurlo",43324942);
AlumnoPtr a3 = crearAlumno("Nicolas Perez",35678912);
AlumnoPtr a4 = crearAlumno("Carlos Araujo",45768123);
AlumnoPtr a5 = crearAlumno("Matias Lopez",47892134);
AlumnoPtr a6 = crearAlumno("Santino Santucci",45789213);
AlumnoPtr a7 = crearAlumno("Alejo Ochoa",41267953);
AlumnoPtr a8 = crearAlumno("Abril Lopez",40632642);
AlumnoPtr a9 = crearAlumno("Nahuel Pumo",38532214);
AlumnoPtr a10 = crearAlumno("Francisco Tantos",45783423);
AlumnoPtr a11 = crearAlumno("Manuel Alvarez",43658767);
AlumnoPtr a12 = crearAlumno("Ricardo Iorio",25786532);
AlumnoPtr a13 = crearAlumno("Juan Vazquez",33765456);
AlumnoPtr a14 = crearAlumno("Tadeo Juarez",36783234);
AlumnoPtr a15= crearAlumno("Joaquin Muniz",43562323);
AlumnoPtr a16= crearAlumno("Tadeo Allende",37894023);

/// AGREGAMOS MATERIAS APROBADAS A LOS ALUMNOS
agregarMateriaAprobada(a1,"Contabilidad",213,9);
agregarMateriaAprobada(a1,"Marketing",432,7);
agregarMateriaAprobada(a1,"Finanzas Corporativas",645,8);

agregarMateriaAprobada(a2,"Enfermeria Comunitaria",435,6);
agregarMateriaAprobada(a2,"Enfermeria Pediatrica",566,5);

agregarMateriaAprobada(a3,"Teoria Política",133,9);
agregarMateriaAprobada(a3,"Relaciones Internacionales",675,10);
agregarMateriaAprobada(a3,"Politica Comparada",342,9);
agregarMateriaAprobada(a3,"Administracion Publica",654,7);

agregarMateriaAprobada(a4,"Administracion Publica",654,7);
agregarMateriaAprobada(a4,"Quimica General",984,4);
agregarMateriaAprobada(a4,"Etica",893,10);

agregarMateriaAprobada(a5,"Ciberseguridad",444,7);
agregarMateriaAprobada(a5,"Logica",345,5);


agregarMateriaAprobada(a6,"Estetica",757,7);
agregarMateriaAprobada(a6,"Antropologia Cultural",123,7);

agregarMateriaAprobada(a7,"Enfermeria en Urgencias",456,10);
agregarMateriaAprobada(a7,"Enfermeria Quirurgica",789,10);

agregarMateriaAprobada(a8,"Marketing Turistico",897,6);
agregarMateriaAprobada(a8,"Legislacion Turistica",891,8);

agregarMateriaAprobada(a10,"Teoria de la Computacion",321,4);
agregarMateriaAprobada(a10,"Desarrollo de Software",433,7);

agregarMateriaAprobada(a11,"Termodinamica",311,7);
agregarMateriaAprobada(a11,"Dinamica",113,8);
agregarMateriaAprobada(a11,"Diseño de Máquinas",667,8);
agregarMateriaAprobada(a11,"Manufactura",888,6);

agregarMateriaAprobada(a12,"Historia Antigua",999,9);
agregarMateriaAprobada(a12,"Historia Medieval",333,5);

agregarMateriaAprobada(a13,"Ecologia",766,7);
agregarMateriaAprobada(a13,"Gestion Ambiental",111,7);
agregarMateriaAprobada(a13,"Geologia",222,5);

agregarMateriaAprobada(a14,"Geometria",333,6);

agregarMateriaAprobada(a15,"Microprocesadores",777,9);
agregarMateriaAprobada(a15,"Circuitos Electricos",322,10);
agregarMateriaAprobada(a15,"Electronica Digital",566,8);

agregarMateriaAprobada(a16,"Probabilidad y estadisctica",777,4);
agregarMateriaAprobada(a16,"Termodinamica",234,10);
agregarMateriaAprobada(a16,"Dispositivos moviles",533,8);

/// INSCRIBIMOS A LOS ALUMNOS A LAS MATERIAS


inscribirAlumnoEnMateria(&a1,m1);
inscribirAlumnoEnMateria(&a2,m1);
inscribirAlumnoEnMateria(&a3,m1);
inscribirAlumnoEnMateria(&a4,m1);
inscribirAlumnoEnMateria(&a5,m1);
inscribirAlumnoEnMateria(&a6,m2);
inscribirAlumnoEnMateria(&a7,m2);
inscribirAlumnoEnMateria(&a8,m2);
inscribirAlumnoEnMateria(&a9,m3);
inscribirAlumnoEnMateria(&a10,m3);
inscribirAlumnoEnMateria(&a11,m4);
inscribirAlumnoEnMateria(&a12,m5);
inscribirAlumnoEnMateria(&a13,m5);
inscribirAlumnoEnMateria(&a14,m5);
inscribirAlumnoEnMateria(&a15,m5);
inscribirAlumnoEnMateria(&a16,m5);


/// MOSTRAMOS LOS INSCRIPTOS A LAS MATERIAS CON SUS DATOS

mostrarGuarani(g);

    return 0;
}
