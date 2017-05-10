#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utnEN.h"
int main()
    {
        Movie* listMovie = (Movie*) malloc(sizeof(Movie));

        int opcion=0;

        while(opcion!=6)
            {
                system("cls");
                printf("1- Agregar pelicula\n");
                printf("2- Borrar pelicula\n");
                printf("3- Modificar pelicula\n");
                printf("4- Generar pagina web\n");
                printf("5- Imprimir lista de peliculas\n");
                printf("6- Salir\n");

                scanf("%d",&opcion);

                switch(opcion)
                    {
                        case 1:
                            if(Movie_Add()==0)
                                {
                                    pause("\nNo se pudo cargar la pelicula\n");
                                }
                            break;
                        case 2:
                            if(Movie_Delete()==0)
                                {
                                    pause("\nNo se pudo borrar pelicula\n");
                                }
                            break;
                        case 3:
                             if(Movie_Modif()==0)
                                {
                                    pause("\nNo se pudo modificar pelicula\n");
                                }
                            break;
                        case 4:
                            Movie_HTML(listMovie,"index.html");
                            break;
                        case 5:
                            if(Movie_Print()==0)
                                {
                                    pause("No se pudo imprimir las peliculas\n");
                                }
                            break;
                        case 6:
                            break;
                        default:
                            pause("Ingrese una opcion valida\n");
                    }
            }

        return 0;
    }
