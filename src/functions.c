#include "functions.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void err_exit(char *msg, int err_code){
    printf("%s",msg);
    exit(err_code);
}

int validateId(int num, char *campo){
    if ( num > 0 ) {
        return 1;
    } else {
        char msg[] = "Erro.\nNumero inválido em campo: ";
        strcat(msg, campo);

        err_exit(msg, EXIT_FAILURE);
        return 0;
    }
}

int validateTime(struct tm* time, char *campo){

    if( time->tm_year == 0 &&
        time->tm_mon  == 0 &&
        time->tm_mday == 0 ){

        char msg[] = "Data/Hora não informada no campo: ";
        strcat(msg, campo);

        err_exit(msg, EXIT_FAILURE);
        return 0;
    } 
    return 1;

    printf("%s", asctime(time)); // DELETAR
}

int validateName(const char* name, int id){
    if( strcmp(name, "") == 0 || strcmp(name, " ") == 0){
        char msg[] = "Erro. Não foi possível encontrar o nome do paciente com id: ";
        char *id_string = intToString(id);
        strcat(msg, id_string);

        err_exit(msg, EXIT_FAILURE);
        return 0;
    }
    return 1;
}

char* intToString(int num){
    int tamanho = (int)((ceil(log10(num))+1)*sizeof(char));

    char *str = (char *)malloc(sizeof(char) * tamanho);
    sprintf(str, "%d", num);
    return str;
}