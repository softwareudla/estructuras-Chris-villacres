
#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_LIBROS 20

struct Libro {
    int id;
    char titulo[101];
    char autor[51];
    int anio_publicacion;
    char estado[11]; 
};

void Biblioteca(struct Libro biblioteca[], int *contador);
int agregarLibro(struct Libro biblioteca[], int *contador);
void listadeLibros(const struct Libro biblioteca[], int contador);
int buscarporID(const struct Libro biblioteca[], int contador, int id);
int buscarporTitulo(const struct Libro biblioteca[], int contador, const char *titulo);
void Estado(struct Libro biblioteca[], int contador, int id);
void eliminar(struct Libro biblioteca[], int *contador, int id);

#endif

