#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"
#include "docente.h"
#include "materia.h"
#include "carrera.h"



//axiomas: asumo que el usuario no va a ingresar mas de 1000 carreras.
carrera carreras[1000]; //defino un vector de 1000 carreras, global.


struct estructuraCarrera{
char nombreCarrera[40];
char tituloCarrera[40];

materia materias[40]; //son como mucho 40 materias, como maximo.
int cantMaterias;

};





carrera crearCarrera (char nombreCarrera1[40],char tituloCarrera1[40])
{
  carrera c = malloc(sizeof(struct estructuraCarrera));
 fflush(stdin);
  strcpy(c->nombreCarrera,nombreCarrera1); //lleno la estructura con los datos que llegan por parametros
  strcpy(c->tituloCarrera,tituloCarrera1);


  c->cantMaterias=0;

  return c;

}

carrera crearCarreraPorTeclado ()
{
  char nombre_carrera[40];
  char titulo_carrera[40];
  printf("Ingrese el nombre de la carrera!\n");
    fflush(stdin); //para liberar el espacio que no se uso de la cadena de caracteres
  gets(nombre_carrera);

  printf("Ingrese el titulo obtenido con la carrera!\n");
    fflush(stdin); //para liberar el espacio que no se uso de la cadena de caracteres
  gets(titulo_carrera);
printf("\n");
  return crearCarrera(nombre_carrera,titulo_carrera);

}



void agregarMateria(carrera c)
{
    int opcion=3;
     int posicion=0;
     while (opcion!=0)
     {
         printf("\n\nCargar una materia      SI ----- 1        NO ----- 0\n");
         scanf("%d",&opcion);

         if (opcion ==1)
         {
             materia m=crearMateriaPorTeclado();
             //agregarDocente(m);
             //agregarAlumno(m);

             posicion= c->cantMaterias;
             c->materias[posicion]=m;

             c->cantMaterias= (c->cantMaterias) +1;

         }
     }
}



void mostrarCarrera(carrera c)
{
  printf("NOMBRE CARRERA -----> %s            TITULO OBTENIDO -----> %s\n\n",c->nombreCarrera, c->tituloCarrera);

  int i=0;
  for ( i=0;i<c->cantMaterias;i++) //si cantMaterias es 0 no va a entrar al for.
  {
      printf("MATERIA #%d:\n",i+1);
      mostrarMateria(c->materias[i]);
  }

}



void menuCarrera()
{
    system("CLS");
    carrera c;
    int indice=0; //para saber la proxima posicion del vector de alumnos a usar

    enum opc1{cargar=1,borrar,modificar,volver};  //abm. borrar no puedo hacer porque no hacemos con listas, me quedaria una posicion del vector en blanco, y sin listas no puedo correr los valores
    int opc1=3;

              while (opc1!=4)
                  {
                      printf("1.Cargar una carrera\n2.Borrar una carrera\n3.Modificar una carrera\n4.Volver\n\n");
                      scanf("%d",&opc1);
                      switch (opc1)
                      {
                      case cargar:
                            c= crearCarreraPorTeclado();
                            indice=indiceCarrera(); //primera posicion libre del vector
                            carreras[indice]=c; //a la posicion indicada por el indice(funcion que retorna la primer posicion vacia del vector de carreras) le asignamos los datos de la carrera ingresada anteriormente
                            c=0;
                            //agregar para que se inscriba a las materias por codigo de mat


                        break;
                      case borrar: //hacer busqueda binaria por DNI, y llamar a la funcion DESTRUIR ALUMNO. ver como hacer para que no quede en blanco una posicion


                        break;
                      case modificar:


                        break;


                      default: printf("Opcion invalida\n");

                      }

                  }



}


//para mostrar alfabeticamente las carreras ingresadas.
void listadoCarrera()
{

    int i=0;
    int tope=indiceCarrera(); //tope= a la ultima posicion sin carreras del vector

    char senial=' ';
    carrera aux; //una variable auxiliar del tipo de dato carreras  para hacer el intercambio

    while (senial!='n')  //en este while ordeno el vector de carreras  por orden alfabetico
    {
        senial= 'n';
    for (i=0;i<tope-1;i++)
      {
        if (strcmp(carreras[i]->nombreCarrera,carreras[i+1]->nombreCarrera)>0) //si la comparacion es positiva, quiere decir que estan desordenados entones se hace el intercambio
        {
           senial='r';
           aux=carreras[i];
           carreras[i]=carreras[i+1];
           carreras[i+1]=aux;
        }

       }

     }


     i=0;
     for (i=0;i<tope;i++)
      {
       mostrarCarrera(carreras[i]);
      }



}



int indiceCarrera ()
{
    int i=0;
    for (i=0;i<1000;i++)
    {
        if (carreras[i]==0)
        {
            return i; //retornamos la posicion del vector vacia. asi sabemos hasta que posicion tiene carreras cargadas
        }
    }

}







void destruirCarrera(carrera c)
{
 free(c);
}


void setNombreCarrera (carrera c,char nombreCarreraNuevo[30])
{

  strcpy(c->nombreCarrera,nombreCarreraNuevo);

}

void setTituloCarrera (carrera c, char tituloCarreraNuevo[40])
{

    strcpy(c->tituloCarrera,tituloCarreraNuevo);

}



/*
void setMateriasCarrera (carrera c, materia nuevaMateria,int pos)
{
  c->materias[pos]=nuevaMateria;

}
*/
















char *getNombreCarrera (carrera c)
{
  return c->nombreCarrera;
}


char *getTituloCarrera (carrera c)
{
  return c->tituloCarrera;
}


























