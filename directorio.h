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

bool isEmpty(directorio dir);

bool isSibiling(directorio dir, Cadena nombre);
//Recorre la lista buscando el nombre del directorio deseado en una misma hoja
#endif
