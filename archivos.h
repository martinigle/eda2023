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
//Recorre la lista de archivos "location", retorna true si el nombre esta disponible, false en el caso contrario

bool isEmptyArch(archivo location);
//Retorna true si la lista de archivos esta vacia, false en el caso contrario;

void printArchName(archivo arch);
//Imprime el nombre del archivo parametro

void printArchList(archivo arch);
//Imprime los nombres de la lista de archivos

void printArchContent(Cadena nombre, archivo location);
//Imprime el contenido del archivo de nombre "nombre" en el directorio parametro

archivo changeArchPrivileges(Cadena nombre, Cadena parametro, archivo location);
//Retorna el archivo de nombre "nombre" luego de cambiar los privilegios segun "parametro", retorna NULL si no existe el archivo  

archivo head(archivo arch);
//Retorna el primer elemento de la lista de archivos

archivo tail(archivo arch);
//Retorna la lista de archivos sin el primer elemento

archivo insertContent(Cadena texto, Cadena nombre, archivo arch);
//Retorna el archivo de nombre "nombre" luego de insertar el contenido si es posible, retorna NULL si no existe el archivo

archivo deleteContent(Cadena nombre, int k, archivo arch);
//Retorna el archivo de nombre "nombre" luego de eliminar k caracteres de su contenido, retorna NULL si no existe el archivo

archivo getArch(Cadena nombre, archivo location);
//Retorna el archivo de nombre "nombre" en el directorio parametro

archivo Crear_Archivo(Cadena nombre, archivo location);
//Retorna un nuevo archivo de nombre "nombre"

#endif

