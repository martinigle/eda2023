// Estructuras de Datos y Algoritmos - Curso 2023
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// sistema.c
// Modulo de Implementacion del File System.

#include "sistema.h"
#include "directorio.h"
#include <string.h>

#include <iostream>

using namespace std;

struct _sistema{
	directorio raiz;
	directorio actual;
};


TipoRet CREARSISTEMA(Sistema &s){
// Inicializa el sistema para que contenga únicamente al directorio RAIZ, sin subdirectorios ni archivos.
// Para mas detalles ver letra.
cout << "CREANDO SISTEMA\n";
	s = new(_sistema);
cout << "1\n";
	Cadena nombre = new char[MAX_NOMBRE];
cout << "2\n";
	strcpy(nombre, "RAIZ");
cout << "3\n";
	s->raiz = Crear_Directorio(nombre, NULL);
cout << "4\n";
	s->actual = s->raiz;
cout << "5\n";
	return OK;
}

TipoRet DESTRUIRSISTEMA(Sistema &s){
// Destruye el sistema, liberando la memoria asignada a las estructuras que datos que constituyen el file system.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet CD (Sistema &s, Cadena nombreDirectorio){
// Cambia directorio. 
    if(strcmp(nombreDirectorio, "..") == 0){
        s->actual = moveToParent(s->actual);
        cout << "ACTUAL: ";
        printDirName(s->actual);
        return OK;    
    }
    else if(isSubdir(s->actual, nombreDirectorio) == false){
        cout << "Ese subdirectorio no existe!";
        return ERROR;    
    }
    s->actual = getSubdir(s->actual, nombreDirectorio);
    cout << "ACTUAL: ";
    printDirName(s->actual);
    return OK;
}
	
TipoRet MKDIR (Sistema &s, Cadena nombreDirectorio){
// Crea un nuevo directorio. 
// Para mas detalles ver letra.
    if(strcmp(nombreDirectorio, "RAIZ") == 0){
        cout << "\nNo se puede crear un directorio de nombre raiz!" ; 
        return ERROR;    
    }
    else if(isSubdir(s->actual, nombreDirectorio)){
        cout << "\nYa existe un subdirectorio con ese nombre!" ;
        return ERROR;    
    }
    Crear_Directorio(nombreDirectorio, s->actual);
	return OK;
}

TipoRet RMDIR (Sistema &s, Cadena nombreDirectorio){
// Elimina un directorio.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet MOVE (Sistema &s, Cadena nombre, Cadena directorioDestino){
// mueve un directorio o archivo desde su directorio origen hacia un nuevo directorio destino.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DIR (Sistema &s, Cadena parametro){
// Muestra el contenido del directorio actual.
// Para mas detalles ver letra.

    if(strcmp(parametro, "/S") == 0){
	    return NO_IMPLEMENTADA;
    }
    else if (strcmp(parametro, "a") == 0  && printDir(s->actual) != NULL){
        return OK;
    }   
    cout << "Al parecer el subdirectorio esta vacio!";
    return ERROR;
}

TipoRet CREATEFILE(Sistema &s, Cadena nombreArchivo) {
    // Crea un nuevo archivo en el directorio actual.
    if(insertFile(nombreArchivo, s->actual) != NULL){
        return OK;
    }
    cout << "\nYa existe un archivo con ese nombre";
    return ERROR;
}


TipoRet DELETE (Sistema &s, Cadena nombreArchivo){
// Elimina un archivo del directorio actual, siempre y cuando no sea de sólo lectura.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet ATTRIB (Sistema &s, Cadena nombreArchivo, Cadena parametro){
// Agrega un texto al comienzo del archivo NombreArchivo.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet IC (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet IF (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Agrega un texto al final del archivo NombreArchivo.
// Para mas detalles ver letra.
    if(insertText(nombreArchivo, texto, s->actual) != NULL){
        return OK;
    }
    
	return ERROR;
}

TipoRet DC (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K primeros caracteres del archivo parámetro.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet DF (Sistema &s, Cadena nombreArchivo, int k){
// Elimina los a lo sumo K últimos caracteres del archivo parámetro.
// Para mas detalles ver letra.
	if(deleteText(nombreArchivo, k, s->actual) != NULL){
        return OK;
    }
    
	return ERROR;
}

TipoRet TYPE (Sistema &s, Cadena nombreArchivo){
// Imprime el contenido del archivo parámetro.
// Para mas detalles ver letra.
    if(printContent(nombreArchivo, s->actual)!=NULL){
        return OK;    
    }
	return ERROR;
}

TipoRet SEARCH (Sistema &s, Cadena nombreArchivo, Cadena texto){
// Busca dentro del archivo la existencia del texto.
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}

TipoRet REPLACE (Sistema &s, Cadena nombreArchivo, Cadena texto1, Cadena texto2){
// Busca y reemplaza dentro del archivo la existencia del texto1 por el texto2. 
// Para mas detalles ver letra.
	return NO_IMPLEMENTADA;
}
