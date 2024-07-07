// Arquivos de cabeçalho criados localmente
#include "exam.h"
#include "functions.h"

// Arquivos de cabeçalho
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
    // Alocação de memória
    Exam *new_exam = (Exam *)malloc(sizeof(Exam)); 

    // Verifica se falha na alocação de memória
    if(new_exam == NULL) {
        // Mensagem de erro
        errMessageId("\nErro.\nNao foi possível alocar memória para o exame com id", id);
        // Função para mostrar o erro e finaliza execução
        errExit(EXIT_FAILURE);
    }

    // Verificações das variáveis antes das atribuições
    if(validateId(id, "id exame")) new_exam->id = id;
    if(validateId(patient_id, "exame, id paciente")) new_exam->patient_id = patient_id;
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