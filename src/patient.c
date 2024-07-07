#include "patient.h" // Arquivo header
#include "functions.h" // Arquivo header com funções

#include <stdio.h> // perror
#include <stdlib.h> // malloc
#include <string.h> // strdup

struct patient {
    int id;
    char *name;
    struct tm *birthdate;
} patient;

// Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados passados como parâmetros e retornando um ponteiro para a estrutura criada. 
Patient *create_patient(int id, const char *name, struct tm *birthdate){
    Patient *new_patient = (Patient *)malloc(sizeof(Patient));

    // Caso não seja alocada a memória
    if(new_patient == NULL){
        char msg[] = "Erro. Não foi possível alocar memória para o paciente: ";
        char *id_string = intToString(id);
        strcat(msg, id_string);
        err_exit(msg, EXIT_FAILURE);
    }   

    if( validateId(id, "id paciente") ) new_patient->id = id;
    if( validateName(name, id) ) new_patient->name = strdup(name); // Reserva espaço de armazenamento para uma cópia da string name
    if( validateTime(birthdate, "Data nascimento do paciente") ) new_patient->birthdate = birthdate;

    return new_patient;
}

// Libera a memória alocada para a estrutura do paciente. 
void destroy_patient(Patient *patient){
    free(patient->birthdate);
    free(patient);
}

// Retorna a identificação única do paciente. 
int get_patient_id(const Patient *patient){
    return patient->id;
}

// Retorna o nome do paciente.
const char* get_patient_name(const Patient *patient){
    return patient->name;
}

// Retorna a data de nascimento do paciente. 
struct tm* get_patient_birthdate(const Patient *patient){
    return patient->birthdate;
}