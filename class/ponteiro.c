
#include <stdio.h>
#include <stdlib.h>


void foo(int *p) { // função errada, pq quando acaba a função o ponteiro desaparece.
    int x = 50;
    p = &x;
}

int main() {
    int a = 10;
    foo(&a);
    printf("%d\n", a);
}

int* func() { // função certa, inclui o static na variável.
    static int x = 100;
    return &x;
}


void foo(int **p) { //função funciona.
    static int x = 30; //não está na stack .persiste durante toda a execução
    *p = &x; //faz o ponteiro apontar para x
}

int main() {  //continuação da função anteiorfunciona. 
    int *ptr = NULL;
    foo(&ptr);
    printf("%d\n", *ptr);
}
/*
| Expressão | Resultado              |
| --------- | ---------------------- |
| `*p++`    | usa valor, depois anda |
| `(*p)++`  | incrementa valor       |
| `*++p`    | anda, depois usa       | */


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

void set_bit(uint8_t *reg, uint8_t bit) {
    *reg |= (1 << bit);
}

void clear_bit(uint8_t *reg, uint8_t bit) {
    *reg &= ~(1 << bit);
}

int test_bit(uint8_t *reg, uint8_t bit) {
    return (*reg & (1 << bit)) != 0;
}

#include <stdio.h>

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
