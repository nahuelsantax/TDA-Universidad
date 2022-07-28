#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"
#include "docente.h"
#include "materia.h"
#include "carrera.h"
#include "departamento.h"
#include "universidad.h"


void menuListados();


//axiomas: Asumo que el usuario no va a ingresar letras como opcion en los menus.
int main()
{

  universidad u= crearUniversidadPorTeclado();
  system("CLS");


   enum opcion{universidad=1,departamento,carrera,materia,docente,alumno,listados,salir};  // AGREGAR LISTADOS, DE ALUMNOS EN GENERAL, POR MATERIA Y CARRERA
  int opcion=0;


   while (opcion!=8)
   {

       printf("<<<<<<<<<<---Sistema de administracion universitaria--->>>>>>>>>>\n1.Universidad\n2.Departamentos\n3.Carreras\n4.Materias\n5.Docentes\n6.Alumnos\n7.Listados\n8.SALIR\n\n--->");
       scanf("%d",&opcion);

       switch (opcion)
       {

       case universidad:
          menuUniversidad();
          system("CLS");

       break;




       case departamento:

              menuDepartamento();
              system("CLS");

       break;






       case carrera:

              menuCarrera();
              system("CLS");

        break;




       case materia:

            menuMateria();
            system("CLS");

        break;



       case docente:

           menuDocente();
           system("CLS");


        break;

       case alumno:

           menuAlumno ();
           system("CLS");



        break;



     case listados:

            menuListados();
            system("CLS");

        break;


     default: printf("La opcion ingresada es incorrecta\n");


       }
   }
return 0;

}



// el submenu de la opcion LISTADOS del menu principal, esta desarrollado aca.
void menuListados()
{

    system("CLS");
    enum opcion{universidad=1,departamentos,carreras,materias,docentes,alumnos,salir};
    int opcion=2;


    while (opcion!=7)
    {
        printf("Listados por orden alfabetico.\n\n1.Mostrar datos universidad\n2.Listado departamento\n3.Listado carreras\n4.Listado materias\n5.Listado docentes\n6.Listado alumnos\n7.Volver\n");
        scanf("%d",&opcion);
        switch (opcion)
        {

        case universidad:


                mostrarUniversidad();





        break;




        case departamentos:

                listadoDepartamento();






            break;

        case carreras:

            listadoCarrera();


            break;

        case materias:

            listadoMateria();




            break;

        case docentes: listadoDocente();



            break;

        case alumnos:
                      listadoAlumnos();


            break;

            default: printf("Opcion incorrecta\n");
            break;

        }

    }



}












