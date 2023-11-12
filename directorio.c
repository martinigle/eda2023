// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// directorio.c
// Modulo de Implementacion de directorio.

#include "directorio.h"
#include "definiciones.h"
#include "archivos.h"

#include <string.h>
#include <iostream>

using namespace std;

struct nodo_directorio{
    archs archivos;
	Cadena nombre;
    directorio padre;
    directorio hermano;
    directorio subdirectorio;
};

bool isEmpty(directorio dir){
    return (dir == NULL);
}

bool isSubdir(directorio dir, Cadena nombre){
    if(isEmpty(dir->subdirectorio)){
        return false;
    } 
    else {
        directorio aux = new(nodo_directorio);
        aux = dir->subdirectorio;
        while(strcmp(aux->nombre, nombre) != 0){
            if (isEmpty(aux->hermano)){
                return false;            
            }
            else if(strcmp(aux->nombre, nombre) == 0){
                return true;        
            }
            aux = aux->hermano;
            cout << aux->nombre;    
        }
        return true; 
    }
}

void printDirName(directorio dir){
    cout << dir->nombre;
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
        if(isEmpty(location->subdirectorio)){
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
            d->hermano = NULL;
        }
    }
	return d;
}

directorio head(directorio dir){
    return dir;
}

directorio tail(directorio dir){
    if(dir->hermano != NULL)
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

directorio getSubdir(directorio dir, Cadena nombre){
    if(isEmpty(dir->subdirectorio)){
        return NULL;
    }
    else {
        directorio aux = new(nodo_directorio);
        aux = dir->subdirectorio;
        while(strcmp(aux->nombre, nombre) != 0){
            if (isEmpty(aux->hermano)){
                return dir;            
            }
            else if(strcmp(aux->nombre, nombre) == 0){
                return aux;        
            }
            aux = aux->hermano;
            cout << aux->nombre;    
        }
        return aux; 
    }
}

//TODO: IMPLEMENTATION OF ARCHS (needs deleteArch to be able to complete this function)
//directorio deleteDir(directorio location, Cadena nombre){
//  if(strcmp(nombre, "RAIZ") == 0){
//      cout << "Este directorio no se puede eliminar!"        
//      return;   
//  }

//  if else(location->archs == NULL){}
//  if else(isEmpty(location->subdirectorio)){}

//  if else(isSubdir(location, nombre)){
//      directorio aux = new(nodo_directorio);        
//  }
//}


//directorio findByName(Sistema &s, Cadena nombre){   
//TODO: IMPLEMENTATION
//    return found;
//}

