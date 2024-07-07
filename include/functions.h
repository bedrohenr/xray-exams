#ifndef FUNCTIONS
#define FUNCTIONS

#include <time.h> // struct tm

// Para o programa com o código de erro
void errExit(int err_code);

// Mostra a mensagem de erro com especificação do campo
void errMessageField(const char *msg, char *campo);

// Mostra a mensagem de erro com especificação do id
void errMessageId(const char *msg, int id);

// Verifica se o inteiro id é válido, maior que zero
int validateId(int num, char *campo);

// Verifica se o Dia, Mês e Ano é igual a zero  
int validateTime(const struct tm* time, char *campo);

// Verifica se o a variável string está vazia
int validateName(const char* name, int id);

// Recebe um número inteiro e o retorna em char *, ou string
char* intToString(int num);

#endif