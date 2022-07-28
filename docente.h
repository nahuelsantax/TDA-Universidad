#ifndef DOCENTE_H_INCLUDED
#define DOCENTE_H_INCLUDED


struct estructuraDocente{
char nombre[20];
char apellido[20];
char dni[9];
};

typedef struct estructuraDocente*docente; //creo un sinonimo de la estructura

//constructores
docente crearDocente (char nombre1[20],char apellido1[20],char dni1[9]); //los nombres pueden ser iguales a los de la estructura,porque son locales de la funcion. Esta funcion retorna un alumno con sus datos
docente crearDocentePorTeclado();

void mostrarDocente (docente d);





void menuDocente();


//para mostrar alfabeticamente los docentes ingresadas.
void listadoDocente();



int indiceDocente();





void destruirDocente (docente d);

char *getNombreDocente (docente d);
char *getApellidoDocente (docente d);
char *getDniDocente (docente d);

void setNombreDocente (docente d, char nombreNuevo[20]);
void setApellidoDocente (docente d, char apellidoNuevo[20]);
void setDniDocente (docente d, char dniNuevo[9]);


#endif // DOCENTE_H_INCLUDED
