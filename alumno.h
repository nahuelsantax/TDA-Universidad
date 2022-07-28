#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED




struct estructuraAlumno{
char nombre[20];
char apellido[20];
char dni[10];
};

typedef struct estructuraAlumno*alumno; //creo un sinonimo de la estructura

//constructores
//AXIOMAS: Asumo que el usuario no va a ingresar LETRAS o CARACTERES en el dni.
alumno crearAlumno (char nombre1[20],char apellido1[20],char dni1[10]); //los nombres pueden ser iguales a los de la estructura,porque son locales de la funcion. Esta funcion retorna un alumno con sus datos
alumno crearAlumnoPorTeclado ();


//funcion para mostrar un alumno
void mostrarAlumno (alumno a);

//funcion para borrar datos de un alumno
void destruirAlumno (alumno a);

//funcion para tener un submenu ABM de alumno
void menuAlumno ();


//para saber cuantos alumnos se ingresaron
int indiceAlumno ();


//para mostrar los alumnos
void listadoAlumnos ();



void leoArchivoAlumnos ();



void menuListados();



/*

//retorna la posicion donde esta el dato. O retorna -1 si no lo encontro.

// tiene que ser un vector ordenado previamente

int busquedaBinaria (int vectorr[], int cant, int dato);
{
    int i=0;
    int inicio=0;
    int centro=0;
    int fin=cant-1;  //posiciones del vector

    while (inicio<=fin)
    {
        centro= (fin+inicio)/2;

        if (vectorr[centro]==dato)
        {
            return centro;
        }
        if (vectorr[centro]>dato)
        {
            fin=centro-1;
        }
        if (vectorr[centro]<dato)
        {
            inicio=centro+1;
        }

    }
    return -1; // si salio del while, quiere decir que no encontro nunca el numero. entonces retornas -1
                // entonces evaluas. int posicion= busquedaBinaria (-----). if (posicion=-1){"no se ingreso bien el dato, o no existe el dato."} else {posicion=posicion del vector en la que se encuentra tu dato}

}
    */










//get
char *getNombreAlumno (alumno a);
char *getApellidoAlumno (alumno a);
char *getDniAlumno (alumno a);


//set
void setNombreAlumno (alumno a, char nombreNuevo[20]);
void setApellidoAlumno (alumno a, char apellidoNuevo[20]);
void setDniAlumno (alumno a, char dniNuevo[10]);


#endif // ALUMNO_H_INCLUDED



