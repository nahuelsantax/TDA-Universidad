#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"
#include "docente.h"
#include "materia.h"
#include "carrera.h"
#include "departamento.h"
#include "universidad.h"

universidad universidadd; //defino una variable global de tipo de dato universidad


struct estructuraUniversidad
{
  char nombreUniversidad[40];
  char direccionUniversidad[40];
  char telefonoUniversidad[30];
  departamento departamentos[4]; //son 4 departamentos fijos.
};




universidad crearUniversidad (char nombreUniversidad1[40],char direccionUniversidad1[40], char telefonoUniversidad1[30])
{
universidadd= malloc(sizeof(struct estructuraUniversidad));

strcpy(universidadd->nombreUniversidad,nombreUniversidad1);
strcpy(universidadd->direccionUniversidad,direccionUniversidad1);
strcpy(universidadd->telefonoUniversidad,telefonoUniversidad1);

return universidadd;
}



universidad crearUniversidadPorTeclado ()
{
char nombreUniver[40];
char direccionUniver[40];
char telefonoUniver[30];
printf("DATOS UNIVERSIDAD!\nNombre---->");
fflush(stdin);
gets(nombreUniver);

printf("Direccion---->");
fflush(stdin);
gets(direccionUniver);

printf("Telefono----->");
fflush(stdin);
gets(telefonoUniver);


return crearUniversidad(nombreUniver, direccionUniver, telefonoUniver);
}



void mostrarUniversidad()
{

printf("\nUNIVERSIDAD:\n");
printf("nombre ---- %s          direccion ---- %s           telefono ---- %s\n\n",universidadd->nombreUniversidad, universidadd->direccionUniversidad, universidadd->telefonoUniversidad);

}



void agregarDepartamento (universidad u)
{

  int i=0;
  for (i=0;i<4;i++)
  {
      printf("Departamento #%d:\n",i+1);
       departamento d= crearDepartamentoPorTeclado();
       u->departamentos[i]=d;
  }

}



void mostrarTodosLosDepartamentos (universidad u)
{
    system("CLS");

    int i=0;
    for (i=0;i<4;i++)
    {
      printf("Departamento #%d:",i+1);
      mostrarDepartamento(u->departamentos[i]);

    }

}









void menuUniversidad()
{
     char nombreUniversidadNuevo[40];
     char direccionUniversidadNuevo[40];
     char telefonoUniversidadNuevo[30];


    system("CLS");

    enum opc1{modificarNombre=1,modificarDireccion,modificarTelefono,volver};  //abm. borrar no puedo hacer porque no hacemos con listas, me quedaria una posicion del vector en blanco, y sin listas no puedo correr los valores
    int opc1=2;

              while (opc1!=4)
                  {
                      printf("1.Modificar nombre\n2.Modificar direccion\n3.Modificar telefono\n4.Volver\n");
                      scanf("%d",&opc1);
                      switch (opc1)
                      {
                       case modificarNombre:
                                              printf("Ingrese el nombre nuevo!\n");
                                              fflush(stdin);
                                              gets(nombreUniversidadNuevo);
                                              setNombreUniversidad(universidadd,nombreUniversidadNuevo); //procedimiento que le pone un valor nuevo a la estructura. Le paso como parametros la estructura de universidad global y el dato recien ingresado
                        break;
                      case modificarDireccion:

                                              printf("Ingrese la direccion nueva!\n");
                                              fflush(stdin);
                                              gets(direccionUniversidadNuevo);
                                              setDireccionUniversidad(universidadd,direccionUniversidadNuevo);




                        break;

                      case modificarTelefono:

                                              printf("Ingrese el telefono nuevo!\n");
                                              fflush(stdin);
                                              gets(telefonoUniversidadNuevo);
                                              setTelefonoUniversidad(universidadd,telefonoUniversidadNuevo);


                        break;
                      default: printf("Opcion invalida\n");

                      }

                  }


}






char  *getNombreUniversidad(universidad u)
{

   return u->nombreUniversidad;

}



char  *getDireccionUniversidad(universidad u)
{

   return u->direccionUniversidad;

}


char  *getTelefonoUniversidad(universidad u)
{
  return u->telefonoUniversidad;

}


void setNombreUniversidad (universidad u, char nombreUniversidadNuevo[40])
{

       strcpy(u->nombreUniversidad,nombreUniversidadNuevo);

}


void setDireccionUniversidad (universidad u, char direccionUniversidadNuevo[40])
{
    strcpy(u->direccionUniversidad,direccionUniversidadNuevo);
}




void setTelefonoUniversidad (universidad u, char telefonoUniversidad[30])
{
    strcpy(u->telefonoUniversidad,telefonoUniversidad);
}


void destruirUniversidad(universidad u)
{
    free(u);
}






















