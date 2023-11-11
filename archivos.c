#include "archivos.h"
#include "definiciones.h"
#include "directorio.h"

#include <string.h>


struct nodo_archivos{
	Cadena nombre;
    char* contenido;
    privilegio tipo;
    directorio padre;
    archs hermano;
};


archs crearArchivo(Cadena nombre, directorio location){
//Retorna un Archivo de nombre "nombre"
    archs a = new(nodo_archivos);
	a->nombre = new char[MAX_NOMBRE];
    strcpy(a->nombre, nombre);
    a->tipo = Lectura_Escritura;
    return a;      
}
