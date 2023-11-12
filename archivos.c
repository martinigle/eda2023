// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivos.c
// Modulo de Implementacion de archivos.

#include "archivos.h"
#include "directorio.h"
#include <string.h>
#include <iostream>

using namespace std;


struct nodo_archivo{
    Cadena nombre;
    Cadena contenido;
    Cadena permisos;
    directorio padre;
    archivo hermano;
};

bool isEmptyArch(archivo arch){
    return (arch==NULL);
}

bool archAvailability(Cadena nombre, archivo location){
    if(isEmptyArch(location)){
        return true;
    }
    else {
        archivo aux = new(nodo_archivo);
        aux = location;
        while(strcmp(aux->nombre, nombre) != 0){
            if(isEmptyArch(aux->hermano)){
                return true;
            }
            aux = aux->hermano;
        }
        return false;
    }
}

void printArchName(archivo arch){
    cout << arch->nombre;
}

archivo Crear_Archivo(Cadena nombre, archivo location) {
    archivo nuevoArchivo = new(nodo_archivo);
    nuevoArchivo->nombre = new char[MAX_NOMBRE];
    nuevoArchivo->contenido = new char[TEXTO_MAX];
    nuevoArchivo->permisos = new char[17];
	strcpy(nuevoArchivo->nombre, nombre);
    strcpy(nuevoArchivo->contenido, "");
    strcpy(nuevoArchivo->permisos, "Lectura/Escritura");
    nuevoArchivo->hermano = NULL;
    if (isEmptyArch(location)) {
        location = nuevoArchivo;
    } else {
        archivo aux = new(nodo_archivo);
        aux = location;
        while (aux->hermano != NULL) {
            aux = aux->hermano;
        }
        aux->hermano = nuevoArchivo;
    }
    return nuevoArchivo;
}


