#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "alumno.h"
#include "materia.h"
#include "universidad.h"



//axiomas: asumo que el usuario no va a ingresar mas de 1000 alumnos.
alumno alumnos[1000];  //defino un vector de alumnos, global
//int contadorAlumnosGlobal=0;



alumno crearAlumno (char nombre1[20],char apellido1[20],char dni1[10])
{
  alumno alumno1= malloc (sizeof(struct estructuraAlumno));  //defino una variable del tipo de dato ALUMNO, y mido el espacio que ocupa la estructura
  strcpy (alumno1->nombre,nombre1);
  strcpy (alumno1->apellido,apellido1);
  strcpy(alumno1->dni,dni1);

  return alumno1;

}


alumno crearAlumnoPorTeclado ()  //esto, llamado del main, seria:   alumno a=crearAlumnoPorTeclado();
{
  char nombre[20];
  char apellido[20];
  char dni[10];

  printf("\nIngrese el nombre del alumno por favor!\n-->");
    fflush(stdin);
  gets (nombre);
  printf("Ingrese el apellido del alumno por favor!\n-->");
    fflush(stdin);
  gets (apellido);

  printf("Ingrese el dni del alumno por favor!\n-->");
  fflush(stdin);
  gets(dni);


  return crearAlumno(nombre,apellido,dni);


}

void mostrarAlumno (alumno a)
{
  printf("NOMBRE: %s  ------ APELLIDO: %s ------ DNI: %s \n\n",a->nombre, a->apellido, a->dni);
}


int indiceAlumno ()  //funcion que retorna la primer posicion vacia del vector de alumnos
{
    int i=0;
    for (i=0;i<1000;i++)
    {
      if (alumnos[i]==0)
      {
          return i;
      }

    }
}



void listadoAlumnos () //en esta funcion se ordena alfabeticamente y se muestra el listado
{
    int i=0;
    int tope=indiceAlumno(); //tope= a la ultima posicion sin alumnos del vector

    char senial=' ';
    alumno aux; //una variable auxiliar del tipo de dato alumnos pra hacer el intercambio

    while (senial!='n')  //en este while ordeno el vector de alumnos por orden alfabetico
    {
        senial= 'n';
    for (i=0;i<tope-1;i++)
      {
        if (strcmp(alumnos[i]->nombre,alumnos[i+1]->nombre)>0) //si la comparacion es positiva, quiere decir que estan desordenados entones se hace el intercambio
        {
           senial='r';
           aux=alumnos[i];
           alumnos[i]=alumnos[i+1];
           alumnos[i+1]=aux;
        }

       }

     }

     i=0;
     for (i=0;i<tope;i++)
      {
       mostrarAlumno(alumnos[i]);
      }

}





void menuAlumno ()  //funcion para tener un submenu de alumnos.       IDENTICO TAMBIEN PARA DOCENTESS !! ! ! ! ! !
{
    system("CLS");
    alumno a;
    int indice=0; //para saber la proxima posicion del vector de alumnos a usar

    enum opc1{cargar=1,borrar,modificarNombre,modificarApellido,volver};
    int opc1=3;

              while (opc1!=5)
                  {
                      printf("1.Cargar un alumno\n2.Borrar un alumno\n3.Modificar nombre\n4.Modificar apellido\n5.Volver\n\n");
                      scanf("%d",&opc1);
                      switch (opc1)
                      {
                      case cargar:
                           a= crearAlumnoPorTeclado();
                            indice=indiceAlumno(); //primera posicion libre del vector
                            alumnos[indice]=a;
                            a=0;
                            //agregar para que se inscriba a las materias por codigo de mat


                        break;
                      case borrar: //hacer busqueda binaria por DNI, y llamar a la funcion DESTRUIR ALUMNO. ver como hacer para que no quede en blanco una posicion


                        break;
                      case modificarNombre:


                        break;


                      case modificarApellido:


                        break;


                      default: printf("Opcion invalida\n");

                      }

                  }




}







void destruirAlumno (alumno a)
{
 free (a);
}


char *getNombreAlumno (alumno a)
{
  return a->nombre;
}



char *getApellidoAlumno (alumno a)
{

return a->apellido;

}



char *getDniAlumno (alumno a)
{
   return a->dni;
}



void setNombreAlumno (alumno a, char nombreNuevo[20])
{
  strcpy (a->nombre,nombreNuevo);
}

void setApellidoAlumno (alumno a, char apellidoNuevo[20])
{
 strcpy (a->apellido, apellidoNuevo);
}

void setDniAlumno (alumno a, char dniNuevo[10])
{

strcpy(a->dni,dniNuevo);

}






/*
void leoArchivoAlumnos ()
{
    FILE*archivo;
    archivo= fopen("alumnos.txt","r"); //abro el archivo en modo lectura

    int fila=0;
    alumno a; //inicializo una variable del tipo de dato alumno, es una estructura que tiene nombre apellido y dni
    int i=0;
    int delimitador=0;

    char auxiliar[20]; //variable en la que vamos a concatenar los datos de la linea

    char linea[300]; //variable para almacenar la linea del archivo

    int indice=0; // para saber que posicion del vector global esta libre

    while (!feof(archivo))
    {
       fgets(linea,300,archivo); //almaceno la primer linea del archivo a la variable "linea"
       while (delimitador<3) //delimitador es 0, entra al while
       {


           if (linea[i]==';') //si encuentra una posicion de la cadena linea con un ";",
           {
               switch (delimitador)
               {
              case 0: strcpy(a->nombre,auxiliar);
              break;
              case 1: strcpy(a->apellido,auxiliar);
              break;
              case 2: strcpy(a->dni,auxiliar);
              break;

               }

               delimitador ++;
               strcpy(auxiliar," ");
           }
           else
            {
             strcat(auxiliar,linea[i]);

              //printf("%s ",auxiliar);
            }

           i++;
       } //cierra while
       indice=indiceAlumno();
       alumnos[indice]=a;
       contadorAlumnosGlobal++; //aumento 1 al contador global de alumnos

    } //cierra while

    fclose(archivo);
}//cierra funcion
*/
