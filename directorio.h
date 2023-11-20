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

directorio getSubdir(directorio dir, Cadena nombre);
//Recorre la lista de subdirectorios de un directorio hasta encontrar el deseado y retorna el directorio en caso de encontrarlo

directorio moveToParent(directorio dir);
//Retorna el directorio padre del directorio actual, en caso de ser raiz retorna null

directorio changePrivileges(directorio location, Cadena nombre, Cadena parametro);
//Cambia los privilegios de un archivo "nombre" en la lista de archivos segun el parametro, retorna NULL si el archivo no existe

directorio insertFile(Cadena nombre, directorio dir);
//Inserta un archivo en la lista de archivos

directorio insertText(Cadena nombre, Cadena texto, directorio location);
//Inserta "texto" en el archivo con el nombre "nombre" dentro del directorio actual

directorio deleteText(Cadena nombre, int k, directorio location);
//Elimina una cantidad k de caracteres de un archivo de nombre "nombre"

directorio printContent(Cadena nombre, directorio location);
//Imprime el contenido de un archivo de nombre "nombre" en el directorio actual

directorio printDir(directorio location);
//Imprime la lista de contenido del directorio actual "location"

bool isSubdir(directorio dir, Cadena nombre);
//Recorre la lista de subdirectorios de un directorio hasta encontrar el deseado y retorna true/false en caso de encontrarlo o no

bool isEmptyDir(directorio dir);
//Retorna true si la lista esta vacia, false en el caso contrario

void printDirName(directorio dir);
//Imprime el nombre del directorio parametro

#endif
