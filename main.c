#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// #define FIFO
// #define LISTA
#define OUTROS
// #define PONTEIROS

#ifdef LISTA

#include "includes/lista.h"
#include "class/lista.c"

/****************** Implementação das funções da lista ******************/
int main(int argc, char const *argv[])
{
    int condition = 0;

    Node *lista = NULL;
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
            if (includeName(&lista, name))
            {
                printf("Nome incluído com sucesso!\n");
            }
            else
            {
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
            if (deleteNameFromList(&lista, name))
            {
                printf("Nome excluído com sucesso!\n");
            }
            else
            {
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
            if (changeName(lista, name, new_name))
            {
                printf("Nome alterado com sucesso!\n");
            }
            else
            {
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
int main(int argc, char const *argv[])
{
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
    for (int i = 0; i < SIZE - 1; i++)
    {
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

// Teste exemplos estaticos e dinâmicos
/*
void exEstaticoErrado(int *p) { // função errada, pq quando acaba a função o ponteiro desaparece.
    int x = 50;
    p = &x;
}


int main() {
    int a = 10;
    exEstaticoErrado(&a);
    printf("%d\n", a);
}*/

int *exEstaticoCerto()
{ // função certa, inclui o static na variável.
    static int x = 100;
    return &x;
}

typedef struct cpu_str cpu_t;
char bufferString[MAX_NAME_LENGTH];

void papo_array_string(char *ptr)
{
    char conversation[] = "mensagem de teste";
    strcpy(ptr, conversation);
}

cpu_t *carregar_struct()
{
    cpu_t *cpu = (cpu_t *)malloc(sizeof(cpu_t));
    if (cpu == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para a estrutura cpu_t\n");
        return NULL;
    }
    cpu->id = 1;
    strcpy(cpu->name, "NXP i.MX RT1170");
    cpu->flag = 0xFF;          // Exemplo de valor para o campo flag
    cpu->gpio_b = (GPIO_B){0}; // Inicializando a estrutura gpio_b
    cpu->gpio_a = (GPIO_A){0}; // Inicializando a estrutura gpio_a
    return cpu;
}

int main(int argc, char const *argv[])
{
    cpu_t *nxp;
    int nxpEnum;

    papo_array_string(bufferString);
    printf("Buffer String: %s\n", bufferString);

    nxp = carregar_struct();
    printf("sizeof(nxp) = %zu\n", sizeof(nxp));
    printf("sizeof(*nxp) = %zu\n", sizeof(*nxp));
    printf("sizeof(nxp->name) = %zu\n", sizeof(nxp->name));
    printf("nome da cpu: %s\n", nxp->name);

    nxp->id = 99;

    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(uint32_t) = %zu\n", sizeof(uint32_t));
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("strlen(nxp->name) = %zu\n", strlen(nxp->name));

    return 0;
}
#endif // OUTROS

#ifdef PONTEIROS

#endif // PONTEIROS
