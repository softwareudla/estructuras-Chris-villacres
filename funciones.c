
#include "funciones.h"
#include <stdio.h>
#include <string.h>

void Biblioteca(struct Libro biblioteca[], int *contador) {
    *contador = 0;
}

int agregarLibro(struct Libro biblioteca[], int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("No se pueden agregar mas libros.\n");
        return 0;
    }

    struct Libro nuevoLibro;

    do {
        printf("Ingrese el ID del libro: ");
        scanf("%d", &nuevoLibro.id);
        if (nuevoLibro.id < 0) {
            printf("El ID no puede ser negativo. Intente nuevamente.\n");
        }
    } while (nuevoLibro.id < 0);

    
    for (int i = 0; i < *contador; i++) {
        if (biblioteca[i].id == nuevoLibro.id) {
            printf("El ID ya existe.\n");
            return 0;
        }
    }

    
    do {
        printf("Ingrese el anio de publicacion: ");
        scanf("%d", &nuevoLibro.anio_publicacion);
        if (nuevoLibro.anio_publicacion < 0) {
            printf("El anio de publicacion no puede ser negativo. Intente nuevamente.\n");
        }
    } while (nuevoLibro.anio_publicacion < 0);

    printf("Ingrese el titulo del libro: ");
    getchar(); 
    fgets(nuevoLibro.titulo, 101, stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = 0;

    printf("Ingrese el autor del libro: ");
    fgets(nuevoLibro.autor, 51, stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = 0;

    strcpy(nuevoLibro.estado, "Disponible");

    biblioteca[*contador] = nuevoLibro;
    (*contador)++;

    printf("Libro agregado exitosamente.\n");
    return 1;
}

void listadeLibros(const struct Libro biblioteca[], int contador) {
    printf("\n%-5s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%-5d %-30s %-20s %-10d %-15s\n", biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio_publicacion, biblioteca[i].estado);
    }
}

int buscarporID(const struct Libro biblioteca[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (biblioteca[i].id == id) {
            return i;
        }
    }
    return -1;
}

int buscarporTitulo(const struct Libro biblioteca[], int contador, const char *titulo) {
    for (int i = 0; i < contador; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            return i;
        }
    }
    return -1;
}

void Estado(struct Libro biblioteca[], int contador, int id) {
    int indice = buscarporID(biblioteca, contador, id);
    if (indice == -1) {
        printf("Libro no encontrado.\n");
        return;
    }

    if (strcmp(biblioteca[indice].estado, "Disponible") == 0) {
        strcpy(biblioteca[indice].estado, "Prestado");
    } else {
        strcpy(biblioteca[indice].estado, "Disponible");
    }

    printf("Estado actualizado exitosamente.\n");
}

void eliminar(struct Libro biblioteca[], int *contador, int id) {
    int indice = buscarporID(biblioteca, *contador, id);
    if (indice == -1) {
        printf("Libro no encontrado.\n");
        return;
    }

    for (int i = indice; i < *contador - 1; i++) {
        biblioteca[i] = biblioteca[i + 1];
    }

    (*contador)--;
    printf("Libro eliminado exitosamente.\n");
}
