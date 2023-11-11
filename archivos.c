// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// sistema.c
// Modulo de Implementacion de archivos.

#include "archivos.h"
#include "directorio.h"
#include "archivos.c"

struct nodo_archivo{
    Cadena nombre;
    Cadena contenido;
    Cadena permisos;
    directorio padre;
    archivo hermano;
};

archivo Crear_Archivo(Cadena nombre, directorio location) {
    archivo nuevoArchivo = new(archivo);
    nuevoArchivo->nombre = new(Cadena[MAX_NOMBRE]);
	strcpy(nuevoArchivo->nombre, nombre);
    nuevoArchivo->contenido = "";
    nuevoArchivo->permisos = "Lectura/Escritura";
    nuevoArchivo->hermano = NULL;
    if (location->archivos == NULL) {
        location->archivos = nuevoArchivo;
    } else {
        archivo aux = location->archivos;
        while (aux->hermano != NULL) {
            aux = aux->hermano;
        }
        aux->hermano = nuevoArchivo;
    }
    return nuevoArchivo;
}