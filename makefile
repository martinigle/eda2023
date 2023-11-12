todo: main.o sistema.o archivos.o directorio.o 
	g++ -o main.exe main.o sistema.o archivos.o directorio.o 
main.o: main.c
	g++ -c main.c
sistema.o: sistema.h sistema.c
	g++ -c sistema.c
directorio.o: directorio.h directorio.c
	g++ -c directorio.c
archivos.o: archivos.h archivos.c
	g++ -c archivos.c
limpiar:
	rm *.o
	rm main.exe

