#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char title[50];
    char genre[20];
    int duration;
    char description[2000];
    int score;
    char linkImage[1000];
}Movie;

int Movie_Add();

int Movie_Modif();

int Movie_Delete();

int Movie_Print();

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void Movie_HTML(Movie lista[], char nombre[]);

#endif // FUNCIONES_H_INCLUDED
