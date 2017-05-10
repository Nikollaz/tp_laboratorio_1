#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
    {
        int opcion=0, flag1=0, flag2=0;
        float A=0, B=0;

        while(opcion!=9)
            {
                printf("------------------------------------------------------------\n");
                printf("1- Ingresar 1er operando (A = %.2f)                    \n",A);
                printf("2- Ingresar 2do operando (B = %.2f)                    \n",B);
                printf("3- Calcular la suma (%.2f + %.2f)                      \n",A,B);
                printf("4- Calcular la resta (%.2f - %.2f)                     \n",A,B);
                printf("5- Calcular la division (%.2f / %.2f)                  \n",A,B);
                printf("6- Calcular la multiplicacion (%.2f * %.2f)            \n",A,B);
                printf("7- Calcular el factorial (%.2f !)                      \n",A);
                printf("8- Calcular todas las operaciones                      \n");
                printf("9- Salir                                               \n");
                printf("------------------------------------------------------------\n");
                printf("\n");

                scanf("%d",&opcion);

                switch(opcion)
                    {
                        case 1:
                                printf("\nA = ");
                                scanf("%f",&A);
                                flag1=1;
                                printf("\n");
                                break;
                        case 2:
                                printf("\nB = ");
                                scanf("%f",&B);
                                flag2=1;
                                printf("\n");
                                break;
                        case 3:
                                if (flag1 == 1 && flag2 == 1)
                                    {
                                        printf("\nLa suma %.2f + %.2f es %.2f\n\n",A,B,sumar(A,B));
                                    }
                                else
                                    {
                                        if(flag1==0)
                                            {
                                                printf("\nIngrese el 1er operando\n");
                                            }
                                        if(flag2==0)
                                            {
                                                printf("\nIngrese el 2do operando\n\n");
                                            }
                                    }
                                break;
                        case 4:
                                if (flag1 == 1 && flag2 == 1)
                                    {
                                        printf("\nLa resta %.2f - %.2f es %.2f\n\n",A,B,restar(A,B));
                                    }
                                else
                                    {
                                        if(flag1==0)
                                            {
                                                printf("\nIngrese el 1er operando\n");
                                            }
                                        if(flag2==0)
                                            {
                                                printf("\nIngrese el 2do operando\n\n");
                                            }
                                    }
                                break;
                        case 5:
                                if (flag1 == 1 && flag2 == 1)
                                    {
                                        dividir(A,B);
                                    }
                                else
                                    {
                                        if(flag1==0)
                                            {
                                                printf("\nIngrese el 1er operando\n");
                                            }
                                        if(flag2==0)
                                            {
                                                printf("\nIngrese el 2do operando\n\n");
                                            }
                                    }
                                break;
                        case 6:
                                if (flag1 == 1 && flag2 == 1)
                                    {
                                        printf("\nLa multiplicacion %.2f * %.2f es %.2f\n\n",A,B,multiplicar(A,B));
                                    }
                                else
                                    {
                                        if(flag1==0)
                                            {
                                                printf("\nIngrese el 1er operando\n");
                                            }
                                        if(flag2==0)
                                            {
                                                printf("\nIngrese el 2do operando\n\n");
                                            }
                                    }
                                break;
                        case 7:
                                if (flag1 == 1)
                                    {
                                        printf("\nEl factorial %.2f ! es %.2f\n\n",A,factorial(A));
                                    }
                                else
                                    {
                                        if(flag1==0)
                                            {
                                                printf("\nIngrese el 1er operando\n");
                                            }
                                    }
                                break;
                        case 8:
                                if (flag1 == 1 && flag2 == 1)
                                    {
                                        printf("\nLa suma %.2f + %.2f es %.2f\n\n",A,B,sumar(A,B));
                                        printf("\nLa resta %.2f - %.2f es %.2f\n\n",A,B,restar(A,B));
                                        dividir(A,B);
                                        printf("\nLa multiplicacion %.2f * %.2f es %.2f\n\n",A,B,multiplicar(A,B));
                                        printf("\nEl factorial %.2f ! es %.2f\n\n",A,factorial(A));
                                    }
                                else
                                    {
                                        if(flag1==0)
                                            {
                                                printf("\nIngrese el 1er operando\n");
                                            }
                                        if(flag2==0)
                                            {
                                                printf("\nIngrese el 2do operando\n\n");
                                            }
                                    }
                                break;
                        case 9:
                                break;
                        default:
                                printf("\nIngrese un valor valido\n\n");
                    }
            }
        return 0;
    }
