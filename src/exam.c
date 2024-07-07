#include "exam.h"
#include "functions.h"

#include <time.h> // struct tm
#include <stdio.h> // perror
#include <stdlib.h> // malloc
#include <string.h>

struct exam {
    int id;
    int patient_id;
    int rx_id;
    struct tm *time;
} exam;


// Cria um novo exame, alocando memória para a estrutura, preenchendo os campos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada.
Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time){

    Exam *new_exam = (Exam *)malloc(sizeof(Exam));

    if(new_exam == NULL) {
        char msg[] = "Nao foi possivel alocar memoria para o exame com id: ";
        char *id_string = intToString(id); 
        strcat(msg, id_string);

        err_exit(msg, EXIT_FAILURE);
    }

    if(validateId(id, "id")) new_exam->id = id;
    if(validateId(patient_id, "id paciente")) new_exam->patient_id = patient_id;
    if(validateId(rx_id, "id raio-x")) new_exam->rx_id = rx_id;
    if(validateTime(time, "exame time")) new_exam->time = time;

    return new_exam;
} 

// Libera a memória alocada para a estrutura de exame.
void destroy_exam(Exam *exam){
    free(exam);
} 

// Retorna a identificação única do exame.
int get_exam_id(const Exam *exam){
    return exam->id;
} 

// Retorna a identificação única do paciente associado ao exame.
int get_exam_patient_id(const Exam *exam){
    return exam->patient_id;
}

// Retorna a identificação única do aparelho de raio-X utilizado no exame.
int get_exam_rx_id(const Exam *exam){
    return exam->rx_id;
}

// Retorna o horário de realização do exame.
struct tm* get_exam_time(const Exam *exam){
    return exam->time;
}