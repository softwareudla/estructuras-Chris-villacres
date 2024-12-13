
#include "funciones.h"
#include <stdio.h>
#include <string.h>

int main() {
    struct Libro biblioteca[MAX_LIBROS];
    int contador;
    Biblioteca(biblioteca, &contador);

    int opcion;
    do {
        printf("\nBiblioteca\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro por ID\n");
        printf("4. Buscar libro por titulo\n");
        printf("5. Actualizar estado de un libro\n");
        printf("6. Eliminar libro\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarLibro(biblioteca, &contador);
                break;
            case 2:
                listadeLibros(biblioteca, contador);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro: ");
                scanf("%d", &id);
                int indice = buscarporID(biblioteca, contador, id);
                if (indice != -1) {
                    printf("\nID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n", 
                           biblioteca[indice].id, biblioteca[indice].titulo, 
                           biblioteca[indice].autor, biblioteca[indice].anio_publicacion, 
                           biblioteca[indice].estado);
                } else {
                    printf("Libro no encontrado.\n");
                }
                break;
            }
            case 4: {
                char titulo[101];
                printf("Ingrese el titulo del libro: ");
                getchar(); 
                fgets(titulo, 101, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                int indice = buscarporTitulo(biblioteca, contador, titulo);
                if (indice != -1) {
                    printf("\nID: %d\nTitulo: %s\nAutor: %s\nAnioo: %d\nEstado: %s\n", 
                           biblioteca[indice].id, biblioteca[indice].titulo, 
                           biblioteca[indice].autor, biblioteca[indice].anio_publicacion, 
                           biblioteca[indice].estado);
                } else {
                    printf("Libro no encontrado.\n");
                }
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el ID del libro a actualizar: ");
                scanf("%d", &id);
                Estado(biblioteca, contador, id);
                break;
            }
            case 6: {
                int id;
                printf("Ingrese el ID del libro a eliminar: ");
                scanf("%d", &id);
                eliminar(biblioteca, &contador, id);
                break;
            }
            case 7:
                printf("Salir\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}