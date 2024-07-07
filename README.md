# X-Ray Exams
Este código em C consiste em simular o processo de realização de exames de raio-X de tórax em um hospital, com ênfase na organização da fila para laudo médico.

## Dependências
- **GCC**, posteriormente usado para compilar o código em C.

## Execução

### Compilação
... Após clonar o repositório, ou baixar:
``` bash
$ cd ./xray-exams
$ make
```
Isso irá executar o arquivo Makefile no _root_ do repositório.

### Testando
Para executar o teste basta, após executar o comando abaixo:

``` bash
$ make run
```
ou, opcionalmente, se já estiver executado o comando **make**:
``` bash
$ ./main	
```
Assim, recebendo os outputs do arquivo **main.c**, utilizando os arquivos de cabeçalho e testando-os.

# Arquivos
Aqui especificaremos os conteúdos dos arquivos de cabeçalho e o conteúdo dessas funções criados neste repositório.

## Exam

Define uma struct Exam que consiste de:

### Variáveis

| Variável                        | Tipo          |
| --------------------------------| --------------|
| [id](src/base/p_init.c)         | Inteiro       |
| [patient_id](src/base/p_init.c) | Inteiro       |
| [rx_id](src/base/p_init.c)      | Inteiro       |
| [time](src/base/p_init.c)       | Struct tm *   |

 - id: Armazena o número identificador do exame.
 - patient_id: Armazena o número identificador do paciente vinculado ao exame.
 - rx_id: Armazena o número identificador do exame de raio-x deste exame.
 - time: Armazena a data e hora que o exame foi feito. Consiste em um ponteiro para uma instanciação da struct **tm**, da biblioteca <time.h>.

 ### Funções
 
| Função                                        | Recebe           | Retorna       |
| --------------------------------------------- | ---------------- | ------------- |
| [create_exam(...)](src/base/p_init.c)         | **int**  id,  **int**  patient_id,  **int**  rx_id,  **struct  tm**  *time | Exam *       |
| [destroy_exam(...)](src/base/p_init.c)        | **Exam**  *exam  | void          |
| [get_exam_id(...)](src/base/p_init.c)         | **Exam**  *exam  | Inteiro       |
| [get_exam_patient_id(...)](src/base/p_init.c) | **Exam**  *exam  | Inteiro       |
| [get_exam_rx_id(...)](src/base/p_init.c)      | **Exam**  *exam  | Inteiro       |
| [get_exam_time(...)](src/base/p_init.c)       | **Exam**  *exam  | Inteiro       |

- create_exam(...): Realiza a alocação de memória e atribuições para as variáveis, criando um novo exame. 
- destroy_exam(...): Apaga o registro do exame em questão, desalocando sua memória.
- get_exam_id(...): Retorna o id do paciente passado no argumento.
- get_exam_patient_id(...): Retorna o id do paciente vinculado ao exame.
- get_exam_rx_id(...): Retorna o id do raio x vinculado ao exame.
- get_exam_time(...): Retorna a data e hora que foi realizado o exame.

## Patient

Define a struct **Patient**, que consiste de:

### Variáveis

| Variável                        | Tipo          |
| ------------------------------- | ------------- |
| [id](src/base/p_init.c)         | Inteiro       |
| [name](src/base/p_init.c)       | Char *        |
| [birthdate](src/base/p_init.c)  | struct tm *   |

 - id: Armazena o número identificador do exame.
 - patient_id: Armazena o número identificador do paciente vinculado ao exame.
 - rx_id: Armazena o número identificador do exame de raio-x deste exame.

### Funções
| Função                                          | Recebe                |Retorna         |
| ----------------------------------------------- | --------------------- | -------------- |
| [create_patient(...)](src/base/p_init.c)        | **int**  id,  **char**  *name, ** struct  tm**  *birthdate | Patient *       |
| [destroy_patient(...)](src/base/p_init.c)       | **Patient**  *patient | void           |
| [get_patient_id(...)](src/base/p_init.c)        | **Patient**  *patient | Inteiro        |
| [get_patient_name(...)](src/base/p_init.c)      | **Patient**  *patient | Char *         |
| [get_patient_birthdate(...)](src/base/p_init.c) | **Patient**  *patient | struct tm *    |

- create_patient(...): Realiza a alocação de memória e atribuições para as variáveis, criando um novo paciente.
- destroy_patient(...): Apaga o registro do paciente em questão, desalocando sua memória.
- get_patient_id(...): Retorna o id do paciente passado no argumento.
- get_patient_name(...): Retorna o nome do paciente passado no argumento.
- get_patient_birthdate(...): Retorna a data de aniversário do paciente.


## Funções
Implementada por conter funções úteis para ambas **Exam** e **Patient**.

| Função                                        |  Recebe                                  | Retorna     |
| ----------------------------------------------|----------------------------------------- | ----------- |
| [error_exit(...)](src/base/p_init.c)          | **int** error_code                       | Void        |
| [error_message_id(...)](src/base/p_init.c)    | const  **char**  *msg,  **char**  *campo | Void        |
| [error_message_field(...)](src/base/p_init.c) | const  **char**  *msg,  **int**  id      | Void        |
| [validate_id(...)](src/base/p_init.c)         | **int**  num,  **char**  *campo          | Char *      |
| [validate_time(...)](src/base/p_init.c)       | const  **struct  tm***  time,  **char**  *campo | Inteiro     |
| [validate_name(...)](src/base/p_init.c)       | const  **char**  *name,  **int**  id     | struct tm * |

- error_exit(...): Finaliza o programa com um código de erro, normalmente, EXIT_FAILURE.
- error_message_id(...): Mostra na tela uma mensagem de erro com um id, seja do paciente ou do exame.
- error_message_field(...): Mostra na tela uma mensagem de erro com o campo de onde foi encontrado o erro.
- validate_id(...): Verifica se o número é maior que zero, assim, confirmando se é um número válido. Caso não seja, usa as outras funções para mostrar uma mensagem de erro e terminando a execução.
- validate_time(...): Verifica se o ano, mês e dia, com a variável do tipo struct tm passada como argumento, são iguais a 0. Caso seja, utiliza das outras funções para mostrar uma mensagem de erro e terminar a execução.
- validate_name(...): Verifica se a variável char* passada com argumento é vazia. Caso seja, utiliza as outras funções para mostrar uma mensagem de erro e terminar a execução.
