#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utnEN.h"


/**
 * \brief Ask for a float type number to the user and returns the result
 * \param The message that will be shown
 * \return The number entered by the user
 *
 */
float getFloat(char message[])
    {
        float auxFloat;
        printf("%s",message);
        scanf("%f",&auxFloat);
        return auxFloat;
    }


/**
 * \brief Ask for an int type number to the user and returns the result
 * \param The message that will be shown
 * \return The number entered by the user
 *
 */
int getInt(char message[])
    {
        int auxInt;
        printf("%s",message);
        scanf("%d",&auxInt);
        return auxInt;
    }


/**
 * \brief Ask for a letter to the user and returns the result
 * \param The message that will be shown
 * \return The character entered by the user
 *
 */
char getChar(char message[])
    {
        char auxChar;
        printf("%s",message);
        fflush(stdin);
        scanf("%c",&auxChar);
        return auxChar;
    }


/**
 * \brief Generates a random number
 * \param from Minimal random number
 * \param to Maximal random number
 * \param beginning Indicates if it is the first requested, 1 if it is.
 * \return returns the generated random number
 *
 */
char getRandomNumber(int from , int to, int beginning)
    {
        if(beginning)
            {
                srand (time(NULL));
            }
        return from + (rand() % (to + 1 - from)) ;
    }


/**
 * \brief Ask for a matrix which has the options needed to make a menu
 * \param Row Number of rows of the matrix
 * \param Col Number of columns of the matrix
 * \param Options Matrix with the options that will be used to create the menu
 * \return The option entered by the user, or -1 if it is a invalid value
 *
 */
int menu(int row, int col, char options[row][col])
    {
        int option;
        int i;
        printf("----------Menu------------\n");
        for(i=0;i<row;i++)
            {
                printf("%d-%s\n",i+1,options[i]);
            }
        printf("--------------------------\n");
        scanf("%d",&option);
        if(option<1 || option>row)
            {
                option=-1;
            }
        return option;
    }


/**
 * \brief Verifies if the element it is only numeric, including float numbers
 * \param str The Array to be analyzed
 * \return 1 if it is only numeric, 0 if it is not
 *
 */
int FloatValidation(char str[])
    {
       int i=0;
       int dots=0; //Number of dots found in the str
       int auxReturn = 1;
       while(str[i] != '\0')
           {
               if (str[i] == '.' && dots == 0)
                   {
                        dots++;
                        i++;
                        continue;
                   }
               if(str[i] < '0' || str[i] > '9')
                   {
                       auxReturn = 0;
                       break;
                   }
               i++;
           }
       return auxReturn;
    }


/**
 * \brief Verifies if the element it is only numeric
 * \param str The Array to be analyzed
 * \return 1 if it is only numeric, 0 if it is not
 *
 */
int IntValidation(char str[])
    {
       int i=0;
       int auxReturn = 1;
       while(str[i] != '\0')
           {
               if(str[i] < '0' || str[i] > '9')
                   {
                        auxReturn = 0;
                        break;
                   }
               i++;
           }
       return auxReturn;
    }


/**
 * \brief Verifies if the element has only letters
 * \param str The Array to be analyzed
 * \return 1 if it has only letters, 0 if it has not
 *
 */
int LettersValidation(char str[])
    {
       int i=0;
       int auxReturn = 1;
       while(str[i] != '\0')
           {
               if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
                   {
                        auxReturn = 0;
                        break;
                   }
               i++;
           }
       return auxReturn;
    }


/**
 * \brief Verifies if the element has only letters and numbers
 * \param str The Array to be analyzed
 * \return 1 if it has only letters and numbers, 0 if it has not
 *
 */
int AlphanumericValidation(char str[])
    {
       int i=0;
       int auxReturn = 1;
       while(str[i] != '\0')
           {
               if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
                   {
                        auxReturn = 0;
                        break;
                   }
               i++;
           }
       return auxReturn;
    }


/**
 * \brief Verifies if the element it is only numeric, + and -
 * \param str The Array to be analyzed
 * \return 1 if it is only numeric, a space and a hyphen, 0 if it is not
 *
 */
int TelephoneValidation(char str[])
    {
       int i=0;
       int hyphen=0;
       int auxReturn;
       while(str[i] != '\0')
           {
               if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
                   {
                        auxReturn = 0;
                        break;
                   }
               if(str[i] == '-')
                   {
                        hyphen++;
                   }
               i++;
           }
       if(hyphen==1)
            {// debe tener un guion
                auxReturn = 1;
            }

        return auxReturn;
    }


/**
 * \brief Ask for a Text to the user and saves it in a variable
 * \param message The message that will be shown
 * \param input Array where the message will be saved
 * \return void
 */
void getString(char message[],char input[])
    {
        printf("%s",message);
        scanf ("%s", input);
    }


/**
 * \brief Ask for a Letters String to the user and saves it in a variable
 * \param message The message that will be shown
 * \param input Array where the message will be saved
 * \return 1 if it has only letters, 0 if it has not
 */
int getStringValidation(char message[],char input[])
    {
        char aux[256];
        int auxReturn=0;
        getString(message,aux);
        if(LettersValidation(aux))
            {
                strcpy(input,aux);
                auxReturn = 1;
            }
        return auxReturn;
    }

/**
 * \brief Ask for an Int String to the user and saves it in a variable
 * \param message The message that will be shown
 * \param input Array where the message will be saved
 * \return 1 if it has only numbers, 0 if it has not
 */
int getIntValidation(char message[],char input[])
    {
        char aux[256];
        int auxReturn=0;
        getString(message,aux);
        if(IntValidation(aux))
            {
                strcpy(input,aux);
                auxReturn = 1;
            }
        return auxReturn;
    }


/**
 * \brief Ask for a Float String to the user and saves it in a variable (accepts Float)
 * \param message The message that will be shown
 * \param input Array where the message will be saved
 * \return 1 if it has only numbers, 0 if it has not
 */
int getFloatValidation(char message[],char input[])
    {
        char aux[256];
        int auxReturn=0;
        getString(message,aux);
        if(FloatValidation(aux))
            {
                strcpy(input,aux);
                auxReturn = 1;
            }
        return auxReturn;
    }


/**
 * \brief Ask for an Int value and validates it
 * \param requestMessage The message that will be shown to ask for the value
 * \param requestMessage The message that will be shown in case of error
 * \return The number that was entered by the user
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
    {
        char auxStr[256];
        int auxInt;
        while(1)
            {
                if (!getIntValidation(requestMessage,auxStr))
                    {
                        printf ("%s\n",errorMessage);
                        continue;

                    }
                auxInt = atoi(auxStr);
                if(auxInt < lowLimit || auxInt > hiLimit)
                    {
                        printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
                        continue;
                    }
                return auxInt;
            }
    }


/**
 * \brief Ask for a Float value and validates it
 * \param requestMessage The message that will be shown to ask for the value
 * \param requestMessage The message that will be shown in case of error
 * \return The number that was entered by the user
 *
 */
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
    {
        char auxStr[256];
        float auxFloat;
        while(1)
            {
                if (!getFloatValidation(requestMessage,auxStr))
                    {
                        printf ("%s\n",errorMessage);
                        continue;

                    }
                auxFloat = atof(auxStr);
                if(auxFloat < lowLimit || auxFloat > hiLimit)
                    {
                        printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
                        continue;
                    }
                return auxFloat;
            }
    }


/**
 * \brief Ask for an String value and validates it
 * \param requestMessage The message that will be shown to ask for the value
 * \param requestMessage The message that will be shown in case of error
 * \param input Array where the entered text will be saved
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
    {
        while(1)
            {
                if (!getStringValidation(requestMessage,input))
                    {
                        printf ("%s\n",errorMessage);
                        continue;
                    }
                clean_stdin();
                break;
            }
    }


/**
 * \brief Cleans the stdin, similar to fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
    {
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    }


/**
 * \brief Stops the execution and shows a message
 * \param message Message to be shown
 * \return -
 *
 */
void pause(char message[])
    {
        getChar(message);
        clean_stdin();
    }
