#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

struct estructuraDepartamento;


typedef struct estructuraDepartamento* departamento;

departamento crearDepartamento (char nombreDepartamento1[40], char descripcionDepartamento1[70]);
departamento crearDepartamentoPorTeclado ();


void menuDepartamento();


//para mostrar alfabeticamente los docentes ingresadas.
void listadoDepartamento();



int indiceDepartamento();






void destruirDepartamento(departamento d);
void mostrarDepartamento (departamento d);

//axiomas: Asumo que el usuario no va a ingresar una opcion distinta a 0 o 1. Y que no va a agregar mas de 10 carreras por departamento.
void agregarCarrera (departamento d);

void setNombreDepartamento (departamento d, char nombreDepartamentoNuevo[40]);
void setDescripcionDepartamento (departamento d, char descripcionDepartamentoNuevo[70]);

char *getNombreDepartamento (departamento d);
char *getDescripcionDepartamento (departamento d);




#endif // DEPARTAMENTO_H_INCLUDED
