#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int obtenerEspacioLibre(EPersona lista[], int);

int buscarPorDni(EPersona lista[], int dni, int);

int menu();

void alta(EPersona lista[], int);

void baja(EPersona lista[], int);

void listar(EPersona lista[], int);

void inicializar(EPersona lista[], int);

void grafico(EPersona lista[],int);
#endif // FUNCIONES_H_INCLUDED
