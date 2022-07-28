#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"
#include "docente.h"
#include "materia.h"
#include "carrera.h"
#include "departamento.h"


departamento departamentos[5]; //vector global de 4 departamentos fijos lo hago de 5 posiciones porque sino no anda.



//axiomas: Asumo que el usuario no va a ingresar ni nombre ni descripcion mas grande que la longitud del char.
struct estructuraDepartamento{
char nombreDepartamento[40];
char descripcionDepartamento[70];


int cantCarreras;
carrera carreras[10]; //Un vector de 10 carreras, porque puede tener a lo sumo 10 carreras cada departamento

};

departamento crearDepartamentoPorTeclado ()
{
  char nombreDepto[40];
  char descripcionDepto[70];

   printf("Ingrese nombre del departamento!\n--->");
      fflush(stdin);
   gets(nombreDepto);
   printf("Escriba la descripcion del departamento!\n--->");
      fflush(stdin);
   gets(descripcionDepto);

   printf("\n");
   return crearDepartamento(nombreDepto,descripcionDepto);
}



departamento crearDepartamento (char nombreDepartamento1[40], char descripcionDepartamento1[70])
{
 departamento d= malloc(sizeof (struct estructuraDepartamento));

 strcpy(d->nombreDepartamento,nombreDepartamento1);
 strcpy(d->descripcionDepartamento,descripcionDepartamento1);

 d->cantCarreras=0;

return d;




}



void mostrarDepartamento (departamento d)
{

printf("\nNOMBRE DEPARTAMENTO ---- %s           DESCRIPCION ----- %s\n\n",d->nombreDepartamento, d->descripcionDepartamento);

int i=0;
for (i=0;i<d->cantCarreras;i++)
{
    printf("CARRERA #%d:\n",i+1);
    mostrarCarrera(d->carreras[i]);
}



}


void agregarCarrera (departamento d)
{
  int opcion=4; //lo inicializo en cualquier numero distinto a 0, para que entre al while
  int posicion=0;

  while (opcion!=0)
  {
      printf("\nCargar una carrera    SI ----- 1        NO ----- 0\n");
      scanf("%d",&opcion);

      if (opcion==1)
      {
          carrera c= crearCarreraPorTeclado(); //creo una carrera
          agregarMateria(c);    //--> Lo pongo en comentario, porque no quiero mostrar todas las materias que tiene cada carrera
          posicion=d->cantCarreras;
          d->carreras[posicion]=c;

          d->cantCarreras= (d->cantCarreras)+1;

        }


  }


}

void listadoDepartamento()
{

    int i=0;
    int tope=indiceDepartamento(); //tope= a la ultima posicion sin docentes del vector

    char senial=' ';
    departamento aux; //una variable auxiliar del tipo de dato docente para hacer el intercambio

    while (senial!='n')  //en este while ordeno el vector de docentes por orden alfabetico
    {
        senial= 'n';
    for (i=0;i<tope-1;i++)
      {
        if (strcmp(departamentos[i]->nombreDepartamento,departamentos[i+1]->nombreDepartamento)>0) //si la comparacion es positiva, quiere decir que estan desordenados entones se hace el intercambio
        {
           senial='r';
           aux=departamentos[i];
           departamentos[i]=departamentos[i+1];
           departamentos[i+1]=aux;
        }

       }

     }


     i=0;
     for (i=0;i<tope;i++)
      {
       mostrarDepartamento(departamentos[i]);
      }


}



int indiceDepartamento()
{
    int i=0;

    for (i=0;i<5;i++)
    {
        if (departamentos[i]==0)
        {
            return i;
        }
    }
}




void menuDepartamento()
{
    system("CLS");


    departamento d;
    int indice=0;

    enum opc1{cargar=1,modificarNombre,modificarDescripcion,volver};  //abm. borrar no puedo hacer porque no hacemos con listas, me quedaria una posicion del vector en blanco, y sin listas no puedo correr los valores
    int opc1=2;

              while (opc1!=4)
                  {
                      printf("1.Cargar departamento\n2.Modificar nombre\n3.Modificar descripcion\n4.Volver\n");
                      scanf("%d",&opc1);
                      switch (opc1)
                      {
                      case cargar:

                          indice=indiceDepartamento();
                          if (indice<4)   //lo hago, para que solo puede ingresar 4 departamentos.
                          {
                             d=crearDepartamentoPorTeclado();
                             departamentos[indice]=d;
                             d=0;
                          }
                          else
                          {
                              printf("No puede ingresar mas de 4 departamentos!\n");
                          }

                        break;



                      case modificarNombre:




                        break;

                      case modificarDescripcion:




                        break;


                      default: printf("Opcion invalida\n");

                      }

                  }

}









void destruirDepartamento(departamento d)
{

free(d);

}



void setNombreDepartamento (departamento d, char nombreDepartamentoNuevo[40])
{

   strcpy (d->nombreDepartamento,nombreDepartamentoNuevo);

}


void setDescripcionDepartamento (departamento d, char descripcionDepartamentoNuevo[70])
{
   strcpy (d->descripcionDepartamento,descripcionDepartamentoNuevo);

}


char *getNombreDepartamento (departamento d)
{

  return d->nombreDepartamento;


}


char *getDescripcionDepartamento (departamento d)
{

   return d->descripcionDepartamento;

}

































