#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "docente.h"

//axiomas: asumo que el usuario no va a ingresar mas de 1000 alumnos.
  //defino un vector de alumnos, global
docente docentes[1000];

docente crearDocente (char nombre1[20],char apellido1[20],char dni1[9])
{
    docente docente1= malloc (sizeof (struct estructuraDocente));
    strcpy(docente1->nombre,nombre1);
    strcpy(docente1->apellido,apellido1);
    strcpy(docente1->dni,dni1);

    return docente1;
}


docente crearDocentePorTeclado()
{
    char nombre[20];
    char apellido[20];
    char dni[20];
    printf("Ingrese nombre del docente porfavor!\n-->");
      fflush(stdin);
    gets(nombre);
    printf("Ingrese apellido del docente porfavor!\n-->");
      fflush(stdin);
    gets(apellido);

    printf("Ingrese dni del docente porfavor!\n-->");
      fflush(stdin);
    gets(dni);


    return crearDocente(nombre,apellido,dni);
}


void mostrarDocente (docente d)
{
    printf("NOMBRE: %s  ------ APELLIDO: %s ------ DNI: %s \n\n",d->nombre, d->apellido, d->dni);
}






void menuDocente()
{
    system("CLS");
    docente d;
    int indice=0; //para saber la proxima posicion del vector de alumnos a usar

    enum opc1{cargar=1,borrar,modificar,volver};
    int opc1=3;

              while (opc1!=4)
                  {
                      printf("1.Cargar un docente\n2.Borrar un docente\n3.Modificar un docente\n4.Volver\n\n");
                      scanf("%d",&opc1);
                      switch (opc1)
                      {
                      case cargar:
                           d=crearDocentePorTeclado();
                           indice=indiceDocente();
                           docentes[indice]=d;
                           d=0; //limpio la estructura


                        break;

                      case borrar: //hacer busqueda binaria por DNI, y llamar a la funcion DESTRUIR ALUMNO. ver como hacer para que no quede en blanco una posicion




                        break;

                      case modificar:




                        break;

                      default: printf("Opcion invalida\n");

                      }

                  }






}



void listadoDocente() //en esta funcion se ordena alfabeticamente y se muestra el listado
{

    int i=0;
    int tope=indiceDocente(); //tope= a la ultima posicion sin docentes del vector

    char senial=' ';
    docente aux; //una variable auxiliar del tipo de dato docente para hacer el intercambio

    while (senial!='n')  //en este while ordeno el vector de docentes por orden alfabetico
    {
        senial= 'n';
    for (i=0;i<tope-1;i++)
      {
        if (strcmp(docentes[i]->nombre,docentes[i+1]->nombre)>0) //si la comparacion es positiva, quiere decir que estan desordenados entones se hace el intercambio
        {
           senial='r';
           aux=docentes[i];
           docentes[i]=docentes[i+1];
           docentes[i+1]=aux;
        }

       }

     }


     i=0;
     for (i=0;i<tope;i++)
      {
       mostrarDocente(docentes[i]);
      }



}


int indiceDocente()
{
    int i=0;

    for (i=0;i<1000;i++)
    {
        if (docentes[i]==0)
        {
            return i;
        }
    }
}








void destruirDocente (docente d)
{
    free(d);
}


char *getNombreDocente (docente d)
{
    return d->nombre;
}

char *getApellidoDocente (docente d)
{
    return d->apellido;
}


char *getDniDocente (docente d)
{
    return d->dni;
}


void setNombreDocente (docente d, char nombreNuevo[20])
{
    strcpy(d->nombre,nombreNuevo);
}


void setApellidoDocente (docente d, char apellidoNuevo[20])
{
    strcpy(d->apellido,apellidoNuevo);
}


void setDniDocente (docente d, char dniNuevo[9])
{
  strcpy(d->dni,dniNuevo);
}





