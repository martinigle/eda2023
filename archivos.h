#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "definiciones.h"


// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivo.h
// Modulo de Definición de archivos.

typedef struct nodo_archivo * archivo;

bool archAvailability(Cadena nombre, archivo location);

bool isEmptyArch(archivo location);

void printArchName(archivo arch);

void printArchContent(Cadena nombre, archivo location);

archivo insertContent(Cadena texto, Cadena nombre, archivo arch);

archivo getArch(Cadena nombre, archivo location);

archivo Crear_Archivo(Cadena nombre, archivo location);


#endif

