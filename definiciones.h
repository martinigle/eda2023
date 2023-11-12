#ifndef DEFINICIONES_H
#define DEFINICIONES_H

// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// definiciones.h
// Definiciones generales del proyecto (constantes, etc).

#define MAX_COMANDO 50
#define MAX_NOMBRE 15

enum _retorno{ OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;

enum tipoArchivo{ Lectura, Lectura_Escritura};
typedef enum tipoArchivo privilegio;

typedef char* Cadena;

#endif
