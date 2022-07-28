#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"
#include "docente.h"
#include "materia.h"

materia materias [1000];
//para crear una materia, llamas a la funcion CREAR MATERIA POR TECLADO. si queres agregarles sus docentes y alummnos, tenes que llamar a la funcion de AGREGAR ALUMNO y AGREGAR DOCENTE.

struct estructuraMateria{
int codigoMateria;
char nombreMateria[40];


alumno alumnos[20];
docente docentes[5];
int cantAlumnos;
int cantDocentes;


};




void agregarDocente (materia m)
{
int opcion =3;
int posicion=0;
while (opcion!=0)
{
opcion=0;
    printf("Cargar un docente  SI -----1     NO -----0 \n");
    scanf("%d",&opcion);
    if (opcion == 1)
    {
      docente d= crearDocentePorTeclado();   //creo un docente
      posicion= m->cantDocentes;  //la posicion empíeza en 0, porque cantDocentes lo inicialize en 0 en la funcion crearMateria
      m->docentes[posicion]= d;  //a la primer posicion del vector de docentes de la estructura, le asigno el primer docente creado

       m->cantDocentes= (m->cantDocentes) +1;  //aumento uno en el contador  de docentes, entonces en la proxima POSICION =1.
    }
}
}




void agregarAlumno (materia m)
{
int opcion=3;
int posicion=0;
while (opcion!=0)
{

    printf("\nCargar un alumno     SI---- 1       NO----0\n");  //pregunto si quiere seguir ingresando alumnos
    scanf("%d",&opcion);

    if (opcion ==1)
    {
        alumno a=crearAlumnoPorTeclado(); //creo un alumno y lo guardo en A
        posicion= m->cantAlumnos; //la posicion va a ser igual al contador de alumnos que empieza en 0
        m->alumnos[posicion]=a; //a la primer posicion del vector de alumnos de la estructura materia, la igualo al alumno creado arriba
            m->cantAlumnos= (m->cantAlumnos) +1;  //aumento el contador, para poder completar el vector de alumnos, y despues poder mostrarlo en un for con este contador.
    }
}

}





materia crearMateria (int codigoMateria1, char nombreMateria1[40])
{
materia m= malloc(sizeof(struct estructuraMateria));

m->codigoMateria =codigoMateria1;
strcpy(m->nombreMateria,nombreMateria1);


m->cantAlumnos =0;
m->cantDocentes=0;


return m;
}


materia crearMateriaPorTeclado ()  // en el main:  materia m= crearMateriaPorTeclado();
{
int codigo=0;
char nombMateria[40];
printf("Ingrese el codigo de la materia!\n");
  fflush(stdin);
scanf("%d",&codigo);
printf("Ingrese el nombre de la materia!\n");
  fflush(stdin);
gets (nombMateria);


return crearMateria(codigo,nombMateria);


}


void mostrarMateria (materia m)
{
printf("NOMBRE MATERIA ---- %s          CODIGO MATERIA---- %d\n\n", m->nombreMateria, m->codigoMateria);


int i=0;
int j=0;
  for ( i=0;i<m->cantAlumnos;i++)
{
   printf("Alumno #%d:\n",i+1);
   mostrarAlumno(m->alumnos[i]);
}

for ( j=0;j<m->cantDocentes;j++)
{
   printf("Docente #%d:\n",j+1);
   mostrarDocente(m->docentes[j]);
}

}



int indiceMateria ()
{
    int i=0;
    for (i=0;i<1000;i++)
    {
        if (materias[i]==0)
        {
            return i;
        }
    }
}






void menuMateria()
{
    system("CLS");
    materia m;
    int indice=0; //para saber la proxima posicion del vector de alumnos a usar

    enum opc1{cargar=1,borrar,modificar,volver};
    int opc1=3;

              while (opc1!=4)
                  {
                      printf("1.Cargar una materia\n2.Borrar una materia\n3.Modificar una materia\n4.Volver\n\n");
                      scanf("%d",&opc1);
                      switch (opc1)
                      {
                      case cargar:
                           m=crearMateriaPorTeclado();
                           indice=indiceMateria();
                           materias[indice]=m;
                           m=0;


                        break;

                      case borrar: //hacer busqueda binaria por DNI, y llamar a la funcion DESTRUIR ALUMNO. ver como hacer para que no quede en blanco una posicion




                        break;

                      case modificar:




                        break;

                      default: printf("Opcion invalida\n");

                      }

                  }




}



void listadoMateria() //en esta funcion se ordena alfabeticamente y se muestra el listado
{
    int i=0;
    int tope=indiceMateria(); //tope= a la ultima posicion sin materias del vector

    char senial=' ';
    materia aux; //una variable auxiliar del tipo de dato materia para hacer el intercambio

    while (senial!='n')  //en este while ordeno el vector de materias por orden alfabetico
    {
        senial= 'n';
    for (i=0;i<tope-1;i++)
      {
        if (strcmp(materias[i]->nombreMateria,materias[i+1]->nombreMateria)>0) //si la comparacion es positiva, quiere decir que estan desordenados entones se hace el intercambio
        {
           senial='r';
           aux=materias[i];
           materias[i]=materias[i+1];
           materias[i+1]=aux;
        }

       }

     }


     i=0;
     for (i=0;i<tope;i++)
      {
       mostrarMateria(materias[i]);
      }



}




void destruirMateria (materia m)
{
   free(m);
}




void setCodigoMateria (materia m, int codigoMateriaNuevo)
{

m->codigoMateria = codigoMateriaNuevo;

}



void setNombreMateria (materia m, char nombreMateriaNuevo[40])
{
  strcpy (m->nombreMateria,nombreMateriaNuevo);
}




int getCodigoMateria (materia m)
{

  return m->codigoMateria;

}



char *getNombreMateria (materia m)
{

   return m->nombreMateria;

}


