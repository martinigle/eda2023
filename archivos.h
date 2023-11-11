#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "definiciones.h"
#include "directorio.h"
#include "directorio.c"

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivo.h
// Modulo de Definición de archivos.

typedef struct nodo_archivo * archivo;

archivo Crear_Archivo(Cadena nombre, directorio location);

#endif