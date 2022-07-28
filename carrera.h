#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED


struct estructuraCarrera;


typedef struct estructuraCarrera* carrera;


carrera crearCarrera (char nombreCarrera1[30],char tituloCarrera1[40]);

carrera crearCarreraPorTeclado ();


//axiomas: asumo que el usuario no va a ingresar una opcion distinta a 0 o 1.
void agregarMateria(carrera c);


void mostrarCarrera(carrera c);






void menuCarrera();


//para mostrar alfabeticamente las carreras ingresadas.
void listadoCarrera();



int indiceCarrera ();





void destruirCarrera(carrera c);
void setNombreCarrera (carrera c,char nombreCarreraNuevo[30]);
void setTituloCarrera (carrera c, char tituloCarreraNuevo[40]);

void setMateriasCarrera (carrera c, materia nuevaMateria,int pos);



char *getNombreCarrera (carrera c);
char *getTituloCarrera (carrera c);






#endif // CARRERA_H_INCLUDED
