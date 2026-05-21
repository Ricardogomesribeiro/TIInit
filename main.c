#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTA

int main(int argc, char const *argv[]) {
    printf("Hello, World!\n");
    return 0;
}

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

