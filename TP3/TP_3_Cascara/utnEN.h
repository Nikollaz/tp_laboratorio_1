//#define...

int getInt(char message[]);
float getFloat(char message[]);
char getChar(char message[]);

char getRandomNumber(int from , int to, int beginning);

int menu(int row, int col, char options[row][col]);

int FloatValidation(char str[]);
int IntValidation(char str[]);
int LettersValidation(char str[]);
int AlphanumericValidation(char str[]);
int TelephoneValidation(char str[]);

void getString(char message[],char input[]);

//After validation, remember to use "atoi/atof" to the validated value so you can use it

int getStringValidation(char message[],char input[]);
int getIntValidation(char message[],char input[]);
int getFloatValidation(char message[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void clean_stdin(void);
void pause(char message[]);
