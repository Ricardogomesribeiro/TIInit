
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../includes/struct.h"

/*
| Expressão | Resultado              |
| --------- | ---------------------- |
| `*p++`    | usa valor, depois anda |
| `(*p)++`  | incrementa valor       |
| `*++p`    | anda, depois usa       | 
| *(p +2)	| avança 2 posições no array e imprime |
*/



void exEstaticoPonteiro(int **p) { //função funciona.
    static int x = 30; //não está na stack .persiste durante toda a execução
    *p = &x; //faz o ponteiro apontar para x
}

/*
int main() {  //continuação da função anteiorfunciona. 
    int *ptr = NULL;
    exEstaticoPonteiro(&ptr);
    printf("%d\n", *ptr);
}*/

void set_bit(uint8_t *reg, uint8_t bit) {
    *reg |= (1 << bit);
}

void clear_bit(uint8_t *reg, uint8_t bit) {
    *reg &= ~(1 << bit);
}

int test_bit(uint8_t *reg, uint8_t bit) {
    return (*reg & (1 << bit)) != 0;
}

/*
int main() {
    uint8_t reg = 0b00000000;

    set_bit(&reg, 2); // Define o bit 2
    printf("Registro após set_bit: 0b%08b\n", reg);

    clear_bit(&reg, 2); // Limpa o bit 2
    printf("Registro após clear_bit: 0b%08b\n", reg);

    set_bit(&reg, 3); // Define o bit 3
    printf("Registro após set_bit: 0b%08b\n", reg);

    int bit_status = test_bit(&reg, 3); // Testa o bit 3
    printf("Status do bit 3: %s\n", bit_status ? "Definido" : "Limpo");

    return 0;
}
*/

int main(int argc, char const *argv[]) {

    GPIO_A gpioa;
    GPIO_B gpiob;

    gpioa.reg = 0; // Inicializa o registro com 0
    gpiob.reg = 0; // Inicializa o registro com 0

    gpioa.bits.pin_1 = 0;
    gpioa.bits.pin_2 = 1;
    gpioa.bits.pin_3 = 0;
    gpioa.bits.pin_4 = 1;
    gpioa.bits.pin_5 = 0;
    gpioa.bits.pin_6 = 1;
    gpioa.bits.pin_7 = 0;
    gpioa.bits.pin_8 = 1;
    printf("%u %u %u %u %u %u %u %u\n", gpioa.bits.pin_8, gpioa.bits.pin_7, gpioa.bits.pin_6, gpioa.bits.pin_5, gpioa.bits.pin_4, gpioa.bits.pin_3, gpioa.bits.pin_2, gpioa.bits.pin_1);
    printf("0x%02X\n", gpioa.reg);
    printf("sizeof(gpioa) = %zu\n", sizeof(gpioa));

    // Bit-fields cannot have their address taken. Operate on the underlying
    // register byte instead. pin_1 maps to bit 0, pin_3 maps to bit 2.
    set_bit(&gpiob.reg, 0); // Define o bit correspondente a pin_1 do GPIOB
    set_bit(&gpiob.reg, 2); // Define o bit correspondente a pin_3 do GPIOB
    printf("%u %u %u %u %u %u %u %u\n", gpiob.bits.pin_8, gpiob.bits.pin_7, gpiob.bits.pin_6, gpiob.bits.pin_5, gpiob.bits.pin_4, gpiob.bits.pin_3, gpiob.bits.pin_2, gpiob.bits.pin_1);
    printf("0x%02X\n", gpiob.reg);
   

    /*       indefinido
    int x = 5;
    printf("%d %d %d\n", x, x++, ++x);
    */

    /* indefinido
    int arr1[] = {10, 20, 30, 40};
    int *pt = arr1;
    printf("%d\n", *(pt + 2));
    */

    /*ponteiro para ponteiro*/
    int x = 10;
    int *pg = &x;
    int **pp = &pg;

    **pp = 50;

    printf("%d\n", x);


    /* aritmética de ponteiros  */
   int arr[] = {5, 10, 15};

   int *p1 = arr;
   int *p = arr;

   // printf("%d\n", *p++); //acessa imprime e depois avança a posição.
    printf("resultado do ponteiro *p: %d\n", *p);
 //   *p = arr[0];
    printf("%d\n", (*p)++);//acessa imprime e depois incrementa o valor.
    printf("%d\n", *p);

    printf("resultado do ponteiro *++p: %d\n", *++p);
    printf("resultado do ponteiro *p: %d\n", *p);
    printf("resultado do ponteiro *p * 2: %d\n", *p * 2);
    printf("resultado do ponteiro *p * 2: %d\n", (*p)*2);

    return 0;
}

/*
#define DEBOUNCE_TIME 50 // ms

uint8_t last_state = 0;
uint32_t last_time = 0;

void check_button(uint32_t current_time, uint8_t read_pin) {
    if (read_pin != last_state) {
        last_time = current_time;
    }

    if ((current_time - last_time) > DEBOUNCE_TIME) {
        last_state = read_pin;
        if (last_state) {
            // botão pressionado
        }
    }
}
*/



/*
//classe do objeto
typedef struct {
	//parametros
	int Valor1;
	int Valor2;
	int Valor3;

	//metodos
	int (*ptrMetodo)(int,int,int);
}TClasse;

//prototypes
int MediaValores(int v1, int v2, int v3);
int FuncaoConstrutora(TClasse * ObjetoAlvo);

//funcao construtora
int FuncaoConstrutora(TClasse * ObjetoAlvo) {
        if(ObjetoAlvo == NULL) 	
             return 0;

        ObjetoAlvo->Valor1 = 0;
	ObjetoAlvo->Valor2 = 0;
	ObjetoAlvo->Valor3 = 0;
	ObjetoAlvo->ptrMetodo = MediaValores;
        return 1;
}

//função a ser referenciada no ponteiro de funcao do metodo
int MediaValores(int v1, int v2, int v3) {
	return ((v1+v2+v3)/3);
}


//programa principal
int main(void) {
	TClasse Objeto;
	int Resultado;

	//chama funcao construtora
	if (FuncaoConstrutora(&Objeto) == 0)
            return 0;

	//popula objeto
	Objeto.Valor1 = 10;
	Objeto.Valor2 = 20;
	Objeto.Valor3 = 30;
	printf("\n\rValor 1 do objeto: %d\n", Objeto.Valor1);
	printf("\n\rValor 2 do objeto: %d\n", Objeto.Valor2);
	printf("\n\rValor 3 do objeto: %d\n", Objeto.Valor3);

	//chama metodo do objeto
	Resultado = Objeto.ptrMetodo(Objeto.Valor1, Objeto.Valor2, Objeto.Valor3);
	printf("\n\rResultado do metodo: %d\n\n", Resultado);
}
*/