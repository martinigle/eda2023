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
    archivo archivos;
	Cadena nombre;
    directorio padre;
    directorio hermano;
    directorio subdirectorio;
};

bool isEmptyDir(directorio dir){
    return (dir == NULL);
}

bool isSubdir(directorio dir, Cadena nombre){
    if(isEmptyDir(dir->subdirectorio)){
        return false;
    } 
    else {
        directorio aux = new(nodo_directorio);
        aux = dir->subdirectorio;
        while(strcmp(aux->nombre, nombre) != 0){
            if (isEmptyDir(aux->hermano)){
                return false;            
            }
            aux = aux->hermano;
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
        d->archivos = NULL;
    } 
    else {
	    strcpy(d->nombre, nombre);
        d->padre = location;
        if(isEmptyDir(location->subdirectorio)){
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
    cout << "\nYa estas en root!";
    return dir;
}

directorio getSubdir(directorio dir, Cadena nombre){
    if(isEmptyDir(dir->subdirectorio)){
        return NULL;
    }
    else {
        directorio aux = new(nodo_directorio);
        aux = dir->subdirectorio;
        while(strcmp(aux->nombre, nombre) != 0){
            if (isEmptyDir(aux->hermano)){
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

bool hasArchs(directorio location){
    if(location->archivos == NULL){
        return false;    
    }
    return true;
}

directorio insertFile(Cadena nombre, directorio location){
    if(hasArchs(location)){
        cout<< "HASARCHS";
        if(archAvailability(nombre, location->archivos)){
            Crear_Archivo(nombre, location->archivos);
            printArchName(location->archivos);
            return location;
        }
        else {
            return NULL;    
        }   
    }
    location->archivos = Crear_Archivo(nombre, NULL);
    return location;
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
