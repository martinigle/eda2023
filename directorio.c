// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "directorio.h"
#include "definiciones.h"


#include <string.h>

struct nodo_directorio{
	//TODO: IMPLEMENT archivos archs ;
    //archs archivos;
	Cadena nombre;
    directorio padre;
    directorio hermano;
    directorio subdirectorio;
};

directorio Crear_Directorio(Cadena nombre, directorio location){
// Retorna un directorio de nombre "nombre".
	directorio d = new(nodo_directorio);
    if(strcmp(nombre, "RAIZ") && location == NULL){
	    d->nombre = new char[MAX_NOMBRE];
        strcpy(d->nombre, nombre);
        d->padre = NULL;
        d->hermano = NULL;
    } 
    else {
	    strcpy(d->nombre, nombre);
        d->padre = location;
        if(location->subdirectorio == NULL){
            location->subdirectorio = d;
            d->hermano = NULL;
        } 
        else {
            directorio aux = new(nodo_directorio);
            aux = location->subdirectorio;
            while(aux->hermano != NULL){
               aux = aux->hermano;
            }
            aux->hermano = d;
        }
    }
	return d;
}

directorio head(directorio dir){
    return dir;
}

directorio tail(directorio dir){
    return dir->hermano;
}

bool isEmpty(directorio dir){
    return (dir == NULL);
}

bool isSibiling(directorio dir, Cadena nombre){
    if(isEmpty(dir)){
        return false;
    }
    else if(head(dir)->nombre == nombre){
        return true;    
    } 
    else {
        isSibiling(tail(dir), nombre);
    }
    return false;
}


//directorio findByName(Sistema &s, Cadena nombre){   
//TODO: IMPLEMENTATION
//    return found;
//}

