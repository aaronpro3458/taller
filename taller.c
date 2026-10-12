#include <stdio.h>
#include <string.h>

int main()
{
    int maxProductos = 10;
    char nombres[10][50];
    float precios[10];
    int cantidad = 0;
    int opcion;

    do
    {
        printf("\nGESTION DE INVENTARIO\n");
        printf("1. Registrar producto\n");
        printf("2. Mostrar inventario y precio total\n");
        printf("3. Mostrar producto mas caro y mas barato\n");
        printf("4. Calcular precio promedio\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (cantidad < maxProductos)
            {
                printf("Ingrese el nombre del producto: ");
                scanf("%s", nombres[cantidad]);
                printf("Ingrese el precio del producto: ");
                scanf("%f", &precios[cantidad]);
                cantidad++;
                printf("¡Producto registrado con exito!\n");
            }
            else
            {
                printf("Inventario lleno. No se pueden agregar mas productos.\n");
            }
            break;

        case 2:
            if (cantidad == 0)
            {
                printf("No hay productos registrados.\n");
            }
            else
            {
                float total = 0;
                printf("\n--- LISTA DE PRODUCTOS ---\n");
                for (int i = 0; i < cantidad; i++)
                {
                    printf("- %s: $%.2f\n", nombres[i], precios[i]);
                    total += precios[i];
                }
                printf("Precio total del inventario: $%.2f\n", total);
            }
            break;

        case 3:
            if (cantidad == 0)
            {
                printf("No hay productos registrados.\n");
            }
            else
            {
                int posCaro = 0, posBarato = 0;
                for (int i = 1; i < cantidad; i++)
                {
                    if (precios[i] > precios[posCaro])
                    {
                        posCaro = i;
                    }
                    if (precios[i] < precios[posBarato])
                    {
                        posBarato = i;
                    }
                }
                printf("Producto mas caro: %s con $%.2f\n", nombres[posCaro], precios[posCaro]);
                printf("Producto mas barato: %s con $%.2f\n", nombres[posBarato], precios[posBarato]);
            }
            break;

        case 4:
            if (cantidad == 0)
            {
                printf("No hay productos registrados.\n");
            }
            else
            {
                float suma = 0;
                for (int i = 0; i < cantidad; i++)
                {
                    suma += precios[i];
                }
                float promedio = suma / cantidad;
                printf("El precio promedio de los productos es: $%.2f\n", promedio);
            }
            break;

        case 5:
            if (cantidad == 0)
            {
                printf("No hay productos registrados.\n");
            }
            else
            {
                char busqueda[50];
                int encontrado = 0;
                printf("Ingrese el nombre del producto a buscar: ");
                scanf("%s", busqueda);
                for (int i = 0; i < cantidad; i++)
                {
                    if (strcmp(nombres[i], busqueda) == 0)
                    {
                        printf("¡Encontrado! El producto '%s' cuesta $%.2f\n", nombres[i], precios[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado)
                {
                    printf("Producto no encontrado en el inventario.\n");
                }
            }
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}