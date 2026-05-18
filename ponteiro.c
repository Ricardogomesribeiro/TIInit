
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
