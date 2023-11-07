// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "directorio.h"
#include "definiciones.h"


#include <string.h>
#include <iostream>

using namespace std;

struct nodo_directorio{
	//TODO: IMPLEMENT archivos archs ;
    //archs archivos;
	Cadena nombre;
    directorio padre;
    directorio hermano;
    directorio subdirectorio;
};

bool isEmpty(directorio dir){
    return (dir == NULL);
}

void printDirName(directorio dir){
    cout << dir->nombre << "\n";
}

directorio Crear_Directorio(Cadena nombre, directorio location){
// Retorna un directorio de nombre "nombre".
	directorio d = new(nodo_directorio);
	d->nombre = new char[MAX_NOMBRE];
    if((strcmp(nombre, "RAIZ") == 0) && location == NULL){
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

directorio moveToParent(directorio dir){
    if(dir->padre != NULL){
        dir = dir->padre;
        return dir;    
    }
    cout << "Ya estas en root!";
    return dir;
}

directorio isSubdir(directorio dir, Cadena nombre){
    if(isEmpty(dir->subdirectorio)){
        return NULL;
    }
    else if(head(dir->subdirectorio)->nombre == nombre){
        return dir;    
    } 
    else {
        return isSubdir(tail(dir->subdirectorio), nombre);
    }
}


//directorio findByName(Sistema &s, Cadena nombre){   
//TODO: IMPLEMENTATION
//    return found;
//}

