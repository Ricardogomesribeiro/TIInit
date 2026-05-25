#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FIFO
//#define LISTA
//#define OUTROS

#ifdef LISTA

#include "includes/lista.h"
#include "class/lista.c"

/****************** Implementação das funções da lista ******************/
int main(int argc, char const *argv[]) {
    int condition = 0;

    Node* lista = NULL;
    condition = 1; // Iniciar a condição para entrar no loop
    while (condition)
    {
        printf("tecle: \n 1 para incluir um nome \n 2 para excluir um nome \n 3 para alterar um  \n 4 para imprimir a lista \n 0 para sair \n ");
        scanf("%d", &condition);
        getchar(); // Limpar o buffer de entrada para evitar problemas com fgets ou scanf subsequentes
        switch (condition)
        {
        case 1:
            {
                char name[BUFFER_SIZE];
                printf("Digite o nome a ser incluído: ");
                scanf("%[^\n]", name);
                getchar(); // Limpar o buffer de entrada
                if (includeName(&lista, name)) {
                    printf("Nome incluído com sucesso!\n");
                } else {
                    printf("Falha ao incluir o nome. Verifique se o nome é único e se não excede o limite de caracteres.\n");
                }
            }
            break;
        case 2:
            {
                char name[BUFFER_SIZE];
                printf("Digite o nome a ser excluído: ");
                scanf("%[^\n]", name);
                getchar(); // Limpar o buffer de entrada
                if (deleteNameFromList(&lista, name)) {
                    printf("Nome excluído com sucesso!\n");
                } else {
                    printf("Falha ao excluir o nome. Verifique se o nome existe na lista.\n");
                }
            }
            break;
        case 3:
            {
                char name[BUFFER_SIZE];
                char new_name[BUFFER_SIZE];
                printf("Digite o nome a ser alterado: ");
                scanf("%[^\n]", name);
                getchar(); // Limpar o buffer de entrada
                printf("Digite o novo nome: ");
                scanf("%[^\n]", new_name);
                getchar(); // Limpar o buffer de entrada
                if (changeName(lista, name, new_name)) {
                    printf("Nome alterado com sucesso!\n");
                } else {
                    printf("Falha ao alterar o nome. Verifique se o nome existe na lista e se o novo nome é válido.\n");
                }
            }
            break;
        case 4:
            printList(lista);
            break;
        case 0:
            condition = 0; // Sair do loop
            break;
        default:
            printf("Opção inválida. Por favor, tente novamente.\n");
            break;
        } 
    }
    
    return 0;
}
#endif // LISTA
#ifdef FIFO
#include "includes/fifo.h"
#include "class/fifo.c"
int main(int argc, char const *argv[]) {
    FIFO_t fila;
    uint8_t data;
    int result;
    fifo_init(&fila);
    result = fifo_is_full(&fila);
    printf("Fila cheia: %s\n", result ? "Sim" : "Não\n");
    result = fifo_is_empty(&fila);
    printf("Fila vazia: %s\n", result ? "Sim" : "Não\n");
    fifo_push(&fila, 10);
    fifo_push(&fila, 20);
    fifo_pop(&fila, &data);
    printf("Valor removido: %d\n", data);
    fifo_pop(&fila, &data);
    printf("Valor removido: %d\n", data);
    result = fifo_is_full(&fila);
    printf("Fila cheia: %s\n", result ? "Sim" : "Não\n");
    result = fifo_is_empty(&fila);
    printf("Fila vazia: %s\n", result ? "Sim" : "Não\n");
    for (int i = 0; i < SIZE - 1; i++) {
        fifo_push(&fila, i);
    }
    result = fifo_is_full(&fila);
    printf("Fila cheia: %s\n", result ? "Sim" : "Não\n");
    result = fifo_is_empty(&fila);
    printf("Fila vazia: %s\n", result ? "Sim" : "Não\n");
    return 0;
}
#endif // FIFO

#ifdef OUTROS  
#include "includes/struct.h"
typedef struct ficticio_struct cpu_t;
char bufferString[MAX_NAME_LENGTH];

cpu_t* carregar_struct(void) {
    cpu_t* nxp = NULL;
   
    nxp = (cpu_t*)malloc(sizeof(cpu_t));
    if(nxp != NULL) {
        nxp->id = 0; // Asignar un ID
        strcpy(nxp->name, "NXP"); // Asignar el nombre "NXP"
        nxp->flag = 1; // Establecer el flag a 1
        nxp->gpio_b = 0x00; // Establecer gpio_b a 0xFF
        //nxp->ptrDigitos = NULL; // Inicializar el puntero a como NULL
        nxp->ptrA = NULL; // Inicializar el
    }else {
        free(nxp);
        return NULL; // Error: fallo en la asignación de memoria
    }

    return nxp;
}

int iniciarStruct(cpu_t* ptr) {
    if(ptr != NULL) {
        memset(ptr, 0, sizeof(cpu_t));
        return 0; // Éxito  
    }
    return -1; // Error: puntero nulo   
}

void liberar_struct(cpu_t* ptr) {
    if(ptr != NULL) {
        free(ptr);
    }
}

void iniciarBufferString(void) {
   memset(bufferString, 0 , sizeof(bufferString));
}

void papo_array_string(char *ptr){
    char conversation[] = "mensagem de teste";
    strcpy(ptr, conversation); 
}

int main(int argc, char const *argv[]) {
    cpu_t* teste;
     int testeEnum;

    iniciarBufferString();
    printf("Buffer String: %s\n", bufferString); 
    papo_array_string(bufferString);
    printf("Buffer String: %s\n", bufferString);  
    
    teste = carregar_struct();
    printf("sizeof(teste) = %zu\n", sizeof(teste));
    printf("sizeof(*teste) = %zu\n", sizeof(*teste));
    printf("sizeof(teste->name) = %zu\n", sizeof(teste->name));
    printf("nome da cpu: %s\n", teste->name);

    //iniciarStruct(teste);
    //printf("name da cpu após iniciarStruct: %s\n", teste->name);
  //  teste->ptrDigitos = DIGITO_5;
  //  printf("Valor do ponteiro ptrDigitos: %d\n", teste->ptrDigitos);
    teste->id = 99;
   
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(uint32_t) = %zu\n", sizeof(uint32_t));
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("strlen(teste->name) = %zu\n", strlen(teste->name));

 /*   int x = 5;
    printf("%d %d %d\n", x, x++, ++x); */

/*    int arr[] = {10, 20, 30, 40};
    int *p = arr;

    printf("%d\n", *(p + 2)); */

   int arr[] = {5, 10, 15};
   int *p = arr;
   // printf("%d\n", *p++); //acessa imprime e depois avança a posição.
    printf("resultado do ponteiro *p: %d\n", *p);
 //   *p = arr[0];
 //   printf("%d\n", (*p)++);//acessa imprime e depois incrementa o valor.
 //  printf("%d\n", *p);

    printf("resultado do ponteiro *++p: %d\n", *++p);
    printf("resultado do ponteiro *p: %d\n", *p);
    return 0;
}
#endif // OUTROS

