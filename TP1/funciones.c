#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Calcula la sumatoria de 2 numeros
 * \param Los dos numeros ingresados por el usuario para realizar la suma
 * \return El resultado de la suma
 *
 */

float sumar (float num1, float num2)
    {
        return num1+num2;
    }

/**
 * \brief Calcula la resta de 2 numeros
 * \param Los dos numeros ingresados por el usuario para realizar la resta
 * \return El resultado de la resta
 *
 */

float restar(float num1, float num2)
    {
        return num1-num2;
    }

/**
 * \brief Calcula la division de 2 numeros
 * \param Los dos numeros ingresados por el usuario para realizar la division
 * \return El resultado de la division en caso de no dividir por 0, sino, un mensaje de error
 *
 */

float dividir(float num1, float num2)
    {
        if (num2==0)
            {
                return printf("\nError, no se puede dividir por 0\n\n");
            }
        else
            {
                return printf("\nLa division %.2f / %.2f es %.2f\n\n",num1,num2,num1/num2);
            }
    }

/**
 * \brief Calcula la multiplicacion de 2 numeros
 * \param Los dos numeros ingresados por el usuario para realizar la multiplicacion
 * \return El resultado de la multiplicacion
 *
 */

float multiplicar(float num1, float num2)
    {
        return num1*num2;
    }

/**
 * \brief Calcula el factorial de 1 numero
 * \param El numero ingresado por el usuario para realizar el factorial
 * \return El resultado del factorial
 *
 */

float factorial(float num1)
    {
        int num = num1;
        if (num==1)
            {
                return 1;
            }
        else
            {
                return num*factorial(num-1);
            }
    }
