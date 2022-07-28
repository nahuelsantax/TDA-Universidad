#ifndef UNIVERSIDAD_H_INCLUDED
#define UNIVERSIDAD_H_INCLUDED


struct estructuraUniversidad;


typedef struct estructuraUniversidad* universidad;

universidad crearUniversidad (char nombreUniversidad1[40],char direccionUniversidad1[40], char telefonoUniversidad1[30]);

universidad crearUniversidadPorTeclado ();


void mostrarUniversidad();

void agregarDepartamento (universidad u);

void mostrarTodosLosDepartamentos (universidad u); //procedimiento para mostrar los 4 departamentos.



void menuUniversidad();



char  *getNombreUniversidad(universidad u);
char  *getDireccionUniversidad(universidad u);
char  *getTelefonoUniversidad(universidad u);

void setNombreUniversidad (universidad u, char nombreUniversidadNuevo[40]);
void setDireccionUniversidad (universidad u, char direccionUniversidadNuevo[40]);
void setTelefonoUniversidad (universidad u, char telefonoUniversidad[30]);


void destruirUniversidad(universidad u);








#endif // UNIVERSIDAD_H_INCLUDED
