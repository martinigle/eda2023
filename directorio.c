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
        directorio aux = dir->subdirectorio;
        while(strcmp(aux->nombre, nombre) != 0){
            if (isEmptyDir(aux->hermano)){
                return false;            
            }
            aux = aux->hermano;
        }
        return true; 
    }
}

bool hasArchs(directorio location){
    if(location->archivos == NULL){
        return false;    
    }
    return true;
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
            directorio aux = location->subdirectorio;
            while(aux->hermano != NULL){
               aux = aux->hermano;
            }
            aux->hermano = d;
            d->hermano = NULL;
        }
    }
	return d;
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
            aux = aux->hermano;
        }
        return aux; 
    }
}

directorio insertFile(Cadena nombre, directorio location){
    if(hasArchs(location)){
        if(archAvailability(nombre, location->archivos)){
            Crear_Archivo(nombre, location->archivos);
            return location;
        }
        else {
            return NULL;    
        }   
    }
    location->archivos = Crear_Archivo(nombre, NULL);
    return location;
}

directorio changePrivileges(directorio location, Cadena nombre, Cadena parametro){
    if(hasArchs(location)){
        changeArchPrivileges(nombre, parametro, location->archivos);
        return location;
    }
    return NULL; 
}

directorio insertText(Cadena nombre, Cadena texto, directorio location){
    if(hasArchs(location) && (insertContent(texto, nombre, location->archivos) != NULL)){
        return location;
    }
    if(!hasArchs(location)){
        cout<< "Ese archivo no existe!";
        return NULL;
    } 
    return NULL;    
}

directorio deleteText(Cadena nombre, int k, directorio location){
    if(hasArchs(location)){
        deleteContent(nombre, k, location->archivos);
        return location;
    }
    return NULL;
}

directorio printContent(Cadena nombre, directorio location){
    if(hasArchs(location)){
        printArchContent(nombre, location->archivos);
        return location;
    }
    return NULL;
}

directorio printDir(directorio location){
    directorio aux = location;
    Cadena path = new char[50];
    Cadena auxStr = new char[50];
    strcpy(path, location->nombre);
    while(strcmp(aux->nombre, "RAIZ") != 0){
        strcpy(auxStr, path);        
        aux = moveToParent(aux);
        strcpy(path, aux->nombre);
        strcat(path, "/");
        strcat(path, auxStr);
    }
    cout << path << ":\n";
    free(path);
    free(auxStr);
    if(isEmptyDir(location->subdirectorio)){
        if(hasArchs(location)){
            printArchList(location->archivos);
            return location; 
        }
        return NULL;
    }
    aux = location->subdirectorio;
    while(aux->hermano != NULL){
       cout << aux->nombre << "\n";
       aux = aux->hermano;
    }
    cout << aux->nombre << "\n";
    if(hasArchs(location)){
      printArchList(location->archivos);
      return location;     
    }
    return location;
}
