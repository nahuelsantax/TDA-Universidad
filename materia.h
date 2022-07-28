#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED


struct estructuraMateria;

typedef struct estructuraMateria*materia;

materia crearMateria (int codigoMateria1, char nombreMateria1[40]);

//axiomas: Espero que el usuario no ingrese letras en la variable CODIGO.
materia crearMateriaPorTeclado ();


void mostrarMateria (materia m);



//submenu de la opcion materias.
void menuMateria();


//para mostrar alfabeticamente las materias ingresadas.
void listadoMateria();



int indiceMateria ();


void destruirMateria (materia m);

void setCodigoMateria (materia m, int codigoMateriaNuevo);
void setNombreMateria (materia m, char nombreMateriaNuevo[40]);

int getCodigoMateria (materia m);
char *getNombreMateria (materia m);

//axiomas: El usuario no va a ingresar como opcion algo distinto a 0 o 1. El usuario no va a ingresar mas de 5 docentes   (lo limito a 5 docentes ya que no uso listas, y se supone que si funciona con 5 docentes funciona con 100)
//axiomas: asumo tambien, que la materia tiene MINIMO 1 docente
void agregarDocente (materia m);

//aciomas: El usuario no va a ingresar como opcion algo distinto a 0 o 1. El usuario no va a ingresar mas de 20 alumnos. (lo limito a 20 alumnos nomas, ya que no uso listas. y se supone que si anda con 20 alumnos, anda tambien con 2000. Simplemente habria que poner el vector de alumnos de 2000
//axiomas: asumo tambien, que la materia tiene MINIMO, ALMENOS un alumno.
void agregarAlumno (materia m);



#endif // MATERIA_H_INCLUDED






























