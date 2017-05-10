#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param cantidad de elementos en el array
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int max)
    {
        int i;
        for(i=0;i<max;i++)
            {
                if(lista[i].estado==0)
                    {
                        return i;
                    }
            }
        return -1;
    }

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param cantidad de elementos en el array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int max)
    {
        int i;

        for(i=0;i<max;i++)
            {
                if(lista[i].dni==dni)
                    {
                        return i;
                    }
            }
        return -1;
    }

/**
 * Muestra un menu para manejar un array de estructuras
 * @return la opcion escojida
 */
int menu()
    {
        int opcion=0;

        system("cls");
        printf("---------------------------------------------\n");
        printf("-           1- Agregar persona              -\n");
        printf("-           2- Borrar persona               -\n");
        printf("-   3- Imprimir lista ordenada por nombre   -\n");
        printf("-       4- Imprimir grafico de edades       -\n");
        printf("-               5- Salir                    -\n");
        printf("---------------------------------------------\n");
        scanf("%d",&opcion);

        return opcion;
    }

/**
 * Agrega una estructura persona a una lista de personas
 * @param lista el array se pasa como parametro.
 * @param cantidad de elementos en el array
 */
void alta(EPersona lista[], int max)
    {
        int i, auxDni;

        int aux=obtenerEspacioLibre(lista, max);

        if(aux==-1)
            {
                printf("No hay mas lugares disponibles");
                getch();
                return;
            }
        else
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(lista[aux].nombre);
                printf("Ingrese edad: ");
                scanf("%d",&lista[aux].edad);
                printf("Ingrese dni: ");
                scanf("%d",&auxDni);
                for(i=0;i<max;i++)
                    {
                        if (auxDni==lista[i].dni)
                            {
                                printf("\nEse DNI ya existe");
                                getch();
                                return;
                            }
                    }
                lista[aux].dni = auxDni;
                lista[aux].estado=1;

                printf("Datos ingresados con exito!");
                getch();
            }
        return;
    }

/**
 * Borra una estructura persona a una lista de personas
 * @param lista el array se pasa como parametro.
 * @param cantidad de elementos en el array
 */
void baja(EPersona lista[], int max)
    {
        int dni, aux;

        printf("Ingrese dni de la persona a borrar: ");
        scanf("%d",&dni);
        aux = buscarPorDni(lista, dni, max);
        if(aux==-1)
            {
                printf("No se encontro el DNI");
                getch();
                return;
            }
        else
            {
                if(lista[aux].estado==1)
                    {
                        lista[aux].estado=0;
                        printf("Los datos han sido borrados con exito!");
                        getch();
                        return;
                    }
                else
                    {
                        printf("El DNI ya ha sido dado de baja");
                        getch();
                        return;
                    }
            }
        return;
    }

/**
 * Ordena y muestra una lista de personas ordenadas por nombre
 * @param lista a ordenar
 * @param cantidad de elementos en el array
 */
void listar(EPersona lista[], int max)
    {
        int i,j;
        EPersona aux;

        for(i=0;i<max-1;i++)
            {
                for(j=i+1;j<max;j++)
                    {
                        if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                            {
                                aux=lista[i];
                                lista[i]=lista[j];
                                lista[j]=aux;
                            }
                    }
            }
        printf("Nombre\t\tEdad\t\tDNI\t\t\n\n");
        for(i=0;i<max;i++)
            {
                if(lista[i].estado==1)
                    {
                        printf("%s\t\t%d\t\t%d\t\t\n",lista[i].nombre,lista[i].edad,lista[i].dni);
                    }
            }
        getch();
        return;
    }

/**
 * Inicializa el estado de todas las personas de la lista a 0 (no hay datos cargados)
 * @param lista a inicializar
 * @param cantidad de elementos en el array
 */
void inicializar(EPersona lista[], int max)
    {
        int i;

        for(i=0;i<max;i++)
            {
                lista[i].estado=0;
            }

        return;
    }

/**
 * Imprime un grafico de edades, dividido entre menores de 18, de edad entre 19 a 35, y mayores a 35                                                                                   *
 *
 * @param lista de la cual se obtendran los datos
 * @param cantidad de elementos en el array
 */
void grafico(EPersona lista[],int max)
    {
        int i;

        int menor18=0, entre19y35=0, mayor35=0, flag=0, mayor;

        for(i=0;i<max;i++)
            {
                 if(lista[i].estado==1)
                    {
                        if (lista[i].edad<=18)
                            {
                                menor18++;
                            }
                        else
                            {
                                if(lista[i].edad>=19 && lista[i].edad<=35)
                                    {
                                        entre19y35++;
                                    }
                                else
                                    {
                                        mayor35++;
                                    }
                            }
                    }
            }

        if(menor18 >= entre19y35 && menor18 >= mayor35)
            {
                mayor = menor18;
            }
        else
            {
                if(entre19y35 >= menor18 && entre19y35 >= mayor35)
                    {
                        mayor = entre19y35;
                    }
                else
                    {
                        mayor = mayor35;
                    }
            }

        for(i=mayor; i>0; i--)
            {
                printf("%02d|",i);

                if(i<= menor18)
                    {
                        printf("*");
                    }
                if(i<= entre19y35)
                    {
                        flag=1;
                        printf("\t*");
                    }
                if(i<= mayor35)
                    {
                        if(flag==0)
                            {
                                printf("\t\t*");
                            }
                        if(flag==1)
                            {
                                printf("\t*");
                            }
                    }
                printf("\n");
            }

        printf("--+-----------------");
        printf("\n  |<18\t19-35\t>35");
        getch();

        return;;
    }
