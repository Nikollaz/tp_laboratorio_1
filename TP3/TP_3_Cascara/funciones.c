#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "utnEN.h"

/**
 *  Agrega una pelicula al archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int Movie_Add()
{
    Movie auxMovie;

    char auxTitle[50];
    char auxGenre[20];
    int auxDuration;
    char auxDescription[2000];
    int auxScore;
    char auxLinkImage[1000];

    printf("Ingrese titulo: ");
    fflush(stdin);
    gets(auxTitle);
    getValidString("Ingrese genero: ","El genero debe contener solo letras",auxGenre);
    auxDuration = getValidInt("Ingrese duracion en segundos: ","La duracion solo debe tener numeros",1,14400);
    printf("Ingrese descripcion: ");
    fflush(stdin);
    gets(auxDescription);
    auxScore = getValidInt("Ingrese puntaje: ","El puntaje solo debe contener numeros",0,10);
    printf("Ingrese link de la imagen: ");
    fflush(stdin);
    gets(auxLinkImage);

    strcpy(auxMovie.title,auxTitle);
    strcpy(auxMovie.genre,auxGenre);
    auxMovie.duration=auxDuration;
    strcpy(auxMovie.description,auxDescription);
    auxMovie.score=auxScore;
    strcpy(auxMovie.linkImage,auxLinkImage);

    int cantidadEscrita;
    FILE *pArchivo;

    pArchivo = fopen("Movie.bin","ab");
    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        fclose(pArchivo);
        return 0;
    }

    cantidadEscrita=fwrite(&auxMovie, sizeof(Movie), 1, pArchivo);
    if (cantidadEscrita < 1)
    {
        printf("\nError al escribir el archivo");
        fclose(pArchivo);
        return 0;
    }
    fclose(pArchivo);
    pause("\nLa pelicula se grabo con exito!");
    return 1;
}


/**
 *  Borra una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int Movie_Delete()
{
    FILE* pArchivo;
    Movie* movieList = (Movie*)malloc(sizeof(Movie));
    Movie* AuxMovieList = (Movie*)malloc(sizeof(Movie));

    char auxTitleDel[50];

    int cant;
    int cantidadEscrita;
    int index = 0;
    int i = 0;
    int flagDel = 0;

    pArchivo = fopen("Movie.bin","rb");
    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        fclose(pArchivo);
        return 0;
    }

    if(feof(pArchivo))
    {
        pause("No hay peliculas cargadas!");
        return 0;
    }

    while(!feof(pArchivo))
    {
        cant = fread( movieList+index, sizeof(Movie),1,pArchivo);

        if(cant!=1)
        {
            if(feof(pArchivo))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                fclose(pArchivo);
                return 0;
            }
        }

        index++;

        AuxMovieList = (Movie*)realloc(movieList,sizeof(Movie)*(index+1));

        if(AuxMovieList==NULL)
        {
            pause("Se acabo la memoria\n");
            fclose(pArchivo);
            return 0;
        }
        else
        {
            movieList = AuxMovieList;
        }
    }
    fclose(pArchivo);

    printf("Ingrese titulo de pelicula que desee borrar: ");
    fflush(stdin);
    gets(auxTitleDel);

    for(i=0; i<=index; i++)
    {
        if(strcmp( (movieList+i)->title, auxTitleDel)==0)
        {
            strcpy((movieList+i)->title,"-51654657576");
            flagDel=1;
            break;
        }
    }
    if(flagDel==0)
    {
        pause("\nNo se encontro la pelicula");
        return 0;
    }

    pArchivo = fopen("Movie.bin","wb");

    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        fclose(pArchivo);
        return 0;
    }
    for(i=0; i<index; i++)
    {
        if(strcmp( (movieList+i)->title, "-51654657576")> 0 || strcmp( (movieList+i)->title, "-51654657576")< 0)
        {
            fflush(stdin);
            cantidadEscrita=fwrite(movieList+i, sizeof(Movie), 1, pArchivo);
            if (cantidadEscrita < 1)
            {
                printf("\nError al escribir el archivo");
                fclose(pArchivo);
                return 0;
            }
        }
    }
    fclose(pArchivo);
    pause("\nLa pelicula se borro con exito!");
    return 1;
}


/**
 *  Modifica una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int Movie_Modif()
{
    FILE* pArchivo;
    Movie* movieList = (Movie*)malloc(sizeof(Movie));
    Movie* AuxMovieList = (Movie*)malloc(sizeof(Movie));

    char auxTitleModif[50];

    char auxTitle[50];
    char auxGenre[20];
    int auxDuration;
    char auxDescription[2000];
    int auxScore;
    char auxLinkImage[1000];

    int cant;
    int cantidadEscrita;
    int index = 0;
    int i = 0;
    int flagModif = 0;

    pArchivo = fopen("Movie.bin","rb");
    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        fclose(pArchivo);
        return 0;
    }

    if(feof(pArchivo))
    {
        pause("No hay peliculas cargadas!");
        return 0;
    }

    while(!feof(pArchivo))
    {
        cant = fread( movieList+index, sizeof(Movie),1,pArchivo);

        if(cant!=1)
        {
            if(feof(pArchivo))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                fclose(pArchivo);
                return 0;
            }
        }
        index++;
        AuxMovieList = (Movie*)realloc(movieList,sizeof(Movie)*(index+1));

        if(AuxMovieList==NULL)
        {
            pause("Se acabo la memoria\n");
            fclose(pArchivo);
            return 0;
        }
        else
        {
            movieList = AuxMovieList;
        }
    }

    fclose(pArchivo);
    /* for(i=0;i<index;i++)
         {
             printf("\n%s\t%s\t%d\t%s\t%d\t%s\n",(movieList+i)->title,(movieList+i)->genre,(movieList+i)->duration,(movieList+i)->description,(movieList+i)->score,(movieList+i)->linkImage);
         }

     getch();*/
    printf("Ingrese titulo de pelicula que desee borrar: ");
    fflush(stdin);
    gets(auxTitleModif);

    for(i=0; i<=index; i++)
    {
        if(strcmp( (movieList+i)->title, auxTitleModif)==0)
        {
            printf("Ingrese titulo: ");
            fflush(stdin);
            gets(auxTitle);
            getValidString("Ingrese genero: ","El genero debe contener solo letras",auxGenre);
            auxDuration = getValidInt("Ingrese duracion en segundos: ","La duracion solo debe tener numeros",1,14400);
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(auxDescription);
            auxScore = getValidInt("Ingrese puntaje: ","El puntaje solo debe contener numeros",0,10);
            printf("Ingrese link de la imagen: ");
            fflush(stdin);
            gets(auxLinkImage);

            strcpy((movieList+i)->title,auxTitle);
            strcpy((movieList+i)->genre,auxGenre);
            (movieList+i)->duration=auxDuration;
            strcpy((movieList+i)->description,auxDescription);
            (movieList+i)->score=auxScore;
            strcpy((movieList+i)->linkImage,auxLinkImage);
            flagModif = 1;
            break;
        }
    }
    if(flagModif==0)
    {
        pause("\nNo se encontro la pelicula");
        return 0;
    }

    pArchivo = fopen("Movie.bin","wb");
    if (pArchivo == NULL)
    {
        printf("\nError de Apertura");
        fclose(pArchivo);
        return 0;
    }
    for(i=0; i<index; i++)
    {
        fflush(stdin);
        cantidadEscrita=fwrite(movieList+i, sizeof(Movie), 1, pArchivo);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(pArchivo);
            return 0;
        }
    }
    fclose(pArchivo);
    pause("\nLa pelicula se modifico con exito!");
    return 1;
}


/**
 *  Imprime las peliculas del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si pudo imprimir las peliculas o no
 */
int Movie_Print()
{
    FILE* bin;
    int cant;
    Movie movie;

    bin = fopen("Movie.bin","rb");
    if (bin==NULL)
    {
        pause("File error");
        fclose(bin);
        return 0;
    }

    while(!feof(bin))
    {
        cant = fread(&movie,sizeof(Movie),1,bin);

        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                pause("No leyo el ultimo registro");
                fclose(bin);
                return 0;
            }
        }

        printf("\n%s\t%s\t%d\t%s\t%d\t%s\n",movie.title,movie.genre,movie.duration,movie.description,movie.score,movie.linkImage);
    }
    getch();
    fclose(bin);
    return 1;
}

void Movie_HTML(Movie lista[], char nombre[])
{
    FILE* bin;
    FILE* html;
    Movie* AuxMovieList = (Movie*)malloc(sizeof(Movie));

    int cant;
    int cantidadEscrita;
    int index = 0;
    int i = 0;

    /**-----------------------Pasaje de archivo binario a array en memoria------------------------------*/

    bin = fopen("Movie.bin","rb");
    if (bin == NULL)
    {
        printf("\nError de Apertura");
        fclose(bin);
        return;
    }

    while(!feof(bin))
    {
        cant = fread( lista+index, sizeof(Movie),1,bin);

        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                fclose(bin);
                return;
            }
        }

        AuxMovieList = (Movie*)realloc(AuxMovieList,sizeof(Movie));

        if(AuxMovieList==NULL)
        {
            pause("Se acabo la memoria\n");
            fclose(bin);
            return;
        }
        else
        {
            AuxMovieList = lista;
        }

        index++;
    }

    fclose(bin);

    /**--------------------------------Trabajo con archivo html------------------------------*/

    html = fopen(nombre,"w");
    if (html == NULL)
    {
        pause("\nError de Apertura");
        fclose(html);
        return;
    }

    fputs("<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>",html);
    for(i=0; i<index; i++)
    {
        fputs("<article class='col-md-4 article-intro'>  <a href='#'> <img class='img-responsive img-rounded' src='",html);
        cantidadEscrita = fprintf(html,"%s",(lista+i)->linkImage);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(html);
            return;
        }
        fputs("'alt=''> </a> <h3> <a href='#'>",html);

        cantidadEscrita = fprintf(html,"%s",(lista+i)->title);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(html);
            return;
        }
        fputs("</a></h3><ul><li>Genero:",html);

        cantidadEscrita = fprintf(html,"%s",(lista+i)->genre);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(html);
            return;
        }
        fputs("</li><li>Puntaje:",html);

        cantidadEscrita = fprintf(html, "%d", (lista+i)->score);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(html);
            return;
        }
        fputs("</li><li>Duracion:",html);

        cantidadEscrita = fprintf(html, "%d", (lista+i)->duration);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(html);
            return;
        }
        fputs("</li></ul><p>",html);
        cantidadEscrita = fprintf(html,"%s",(lista+i)->description);
        if (cantidadEscrita < 1)
        {
            printf("\nError al escribir el archivo");
            fclose(html);
            return;
        }
        fputs("</p></article>",html);
    }
    fputs("</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --<script src='js/holder.min.js'></script></body></html>",html);
    pause("Archivo generado con exito!");
    fclose(html);
    return;
}
