#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "definiciones.h"

#include "directorio.h"

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// archivo.h
// Modulo de Definición de archivo.

typedef struct nodo_archivos * archs;


archs crearArchivo(Cadena nombre, directorio location);

#endif
