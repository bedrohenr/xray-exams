// Arquivo de cabeçalho criado localmente
#include "functions.h"

// Arquivos de cabeçalho
#include <stdlib.h> // malloc, EXIT_FAILURE
#include <string.h> // strcmp
#include <stdio.h> // printf, sprintf
#include <math.h> // ceil

// Mostra uma mensagem de erro e para o programa com o código de erro
void errExit(int err_code){
    exit(err_code);
}

void errMessageId(const char *msg, int id){
    printf("%s: %d.", msg, id);
}

void errMessageField(const char *msg, char *campo){
    printf("%s: %s.", msg, campo);
}

// Verifica se o inteiro id é válido, maior que zero
int validateId(int num, char *campo){
    if ( num > 0 ) {
        return 1;
    } else {
        // Mensagem de erro
        errMessageField("Erro.\nNumero inválido em campo", campo);
        // Função para mostrar o erro e finaliza execução
        errExit(EXIT_FAILURE);
        return 0;
    }
}

// Verifica se o Dia, Mês e Ano é igual a zero  
int validateTime(const struct tm* time, char *campo){

    if( time->tm_year == 0 &&
        time->tm_mon  == 0 &&
        time->tm_mday == 0 ){

        char msg[] = "Data/Hora não informada no campo: ";
        strcat(msg, campo);

        // Mensagem de erro
        errMessageField("Erro.\nData/Hora não informada no campo", campo);
        // Função para mostrar o erro e finaliza execução
        errExit(EXIT_FAILURE);
        return 0;
    } 
    return 1;
}

// Verifica se o a variável string está vazia
int validateName(const char* name, int id){
    if( strcmp(name, "") == 0 || strcmp(name, " ") == 0){
        // Mensagem de erro
        errMessageId("Erro.\nNão foi possível encontrar o nome do paciente com id", id);
        // Função para mostrar o erro e finaliza execução
        errExit(EXIT_FAILURE);
        return 0;
    }
    return 1;
}

// Recebe um número inteiro e o retorna em char *, ou string
char* intToString(int num){
    // Calcula a quantidade de caracteres em um número com um a mais
    int tamanho = (int)((ceil(log10(num))+1)*sizeof(char));

    // Aloca memória para o valor ser acessível fora da função
    char *str = (char *)malloc(sizeof(char) * tamanho);

    // Transforma de int em char *
    sprintf(str, "%d", num);

    return str;
}