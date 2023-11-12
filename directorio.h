#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include "definiciones.h"


// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.h
// Modulo de Definición de directorio.

typedef struct nodo_directorio * directorio;

directorio Crear_Directorio(Cadena nombre, directorio location);
// Retorna un directorio de nombre "nombre".

//TODO Write function descriptions
directorio head(directorio dir);

directorio tail(directorio dir);

directorio getSubdir(directorio dir, Cadena nombre);
//Recorre la lista de subdirectorios de un directorio hasta encontrar el deseado y retorna el directorio en caso de encontrarlo

directorio moveToParent(directorio dir);

directorio deleteDir(directorio dir);

directorio insertFile(Cadena nombre, directorio dir);

bool isSubdir(directorio dir, Cadena nombre);
//Recorre la lista de subdirectorios de un directorio hasta encontrar el deseado y retorna true/false en caso de encontrarlo o no

bool isEmptyDir(directorio dir);

void printDirName(directorio dir);

#endif
