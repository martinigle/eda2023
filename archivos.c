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
    nuevoArchivo->permisos = new char[17];
	strcpy(nuevoArchivo->nombre, nombre);
    strcpy(nuevoArchivo->permisos, "Lectura/Escritura");
    nuevoArchivo->hermano = NULL;
    if (isEmptyArch(location)) {
        location = nuevoArchivo;
    } else {
        archivo aux = new(nodo_archivo);
        aux = location;
        while (aux->hermano != NULL) {
            cout << aux->nombre;
            aux = aux->hermano;
        }
        aux->hermano = nuevoArchivo;
    }
    return nuevoArchivo;
}

archivo getArch(Cadena nombre, archivo location){
    if(isEmptyArch(location)){
        return NULL;
    }
    else {
        archivo aux = new(nodo_archivo);
        aux = location;
        while(strcmp(aux->nombre, nombre) != 0){
            if(isEmptyArch(aux->hermano)){
                return NULL;
            }
            aux = aux->hermano;
        }
        return aux;
    }
}

archivo insertContent(Cadena texto, Cadena nombre, archivo arch){
    //TODO: change strcat because overlaps TEXTO_MAX
    if(archAvailability(nombre, arch) == false && (strcmp(getArch(nombre, arch)->permisos, "Lectura/Escritura") == 0)){
        if(strlen(texto)<TEXTO_MAX){
            getArch(nombre, arch)->contenido = new char[strlen(texto)];
            strcat(getArch(nombre, arch)->contenido, texto);
            return arch;
        } else {
            getArch(nombre, arch)->contenido = new char[TEXTO_MAX];
            strcat(getArch(nombre, arch)->contenido, texto);
            return arch;
        }        
    } 
    return NULL;
}

archivo deleteContent(Cadena nombre, int k, archivo arch){
    //TODO: FIX
    if(archAvailability(nombre, arch) == false && (strcmp(getArch(nombre, arch)->permisos, "Lectura/Escritura") == 0)){
        Cadena aux = new char[strlen(getArch(nombre, arch)->contenido)-k];
        strcpy(aux, getArch(nombre, arch)->contenido);
        getArch(nombre, arch)->contenido = aux;
        return arch;
    }
    return NULL;
}

void printArchContent(Cadena nombre, archivo location){
    if(!isEmptyArch(location) && (archAvailability(nombre, location) == false)){
        cout << getArch(nombre, location)->contenido;
    }
}

archivo head(archivo arch){
    return arch;
}

archivo tail(archivo arch){
    if(arch->hermano != NULL)
        return arch->hermano;
}

void printArchList(archivo location){
    if(!isEmptyArch(location)){
        cout << location->nombre << " " << location->permisos << "\n";
        printArchList(head(tail(location)));
    }
    return;
}

