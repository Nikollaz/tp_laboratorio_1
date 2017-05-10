/****************************************************************************************************
*                                                                                                   *
*   * Programa: Trabajo Practico N2                                                                 *
*                                                                                                   *
*   * Objetivo:                                                                                     *
*                                                                                                   *
*      Definir una estructura que represente una persona, con los campos nombre, edad, dni y un     *
*      flag de estado.                                                                              *
*      Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el   *
*      siguiente:                                                                                   *
*      1. Agregar una persona                                                                       *
*      2. Borrar una persona                                                                        *
*      3. Imprimir lista ordenada por nombre                                                        *
*      4. Imprimir gráfico de edades                                                                *
*      Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.         *
*      El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:                   *
*      • Menores de 18                                                                              *
*      • De 19 a 35                                                                                 *
*      • Mayores de 35.                                                                             *
*      En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo          *
*                                                                                                   *
*   * Version:0.1 del 20 septiembre de 2016                                                         *
*                                                                                                   *
*   * Autor: Nicolas Saavedra                                                                       *
*                                                                                                   *
*                                                                                                   *
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX_PERSONAS 20

int main()
    {
        int opcion = 0;
        EPersona per[MAX_PERSONAS];

        inicializar(per, MAX_PERSONAS);

        while(opcion!=5)
            {
                opcion = menu();

                switch(opcion)
                    {
                        case 1:
                                printf("---------------------------------------------\n");
                                alta(per, MAX_PERSONAS);
                                break;
                        case 2:
                                printf("---------------------------------------------\n");
                                baja(per, MAX_PERSONAS);
                                break;
                        case 3:
                                printf("---------------------------------------------\n");
                                listar(per, MAX_PERSONAS);
                                break;
                        case 4:
                                printf("---------------------------------------------\n");
                                grafico(per, MAX_PERSONAS);
                                break;
                        case 5:
                                printf("---------------------------------------------\n");
                                printf("Gracias por utilizar el programa del TP2!\n");
                                printf("---------------------------------------------\n");
                                break;
                    }
            }

        return 0;
    }
