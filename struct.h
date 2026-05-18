#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 50
#define SIZE 20

typedef enum {
    DIGITO_0 = 0,
    DIGITO_1 = 1,
    DIGITO_2 = 2,
    DIGITO_3 = 3,
    DIGITO_4 = 4,
    DIGITO_5 = 5,
    DIGITO_6 = 6,
    DIGITO_7 = 7,
    DIGITO_8 = 8,
    DIGITO_9 = 9,
}DIGITOS;

typedef char NAME[MAX_NAME_LENGTH];
typedef char TELEFONE[MAX_NAME_LENGTH];

struct __attribute__((packed)) gpio_a_t {
    uint8_t pin_1 : 1;
    uint8_t pin_2 : 1;
    uint8_t pin_3 : 1;
    uint8_t pin_4 : 1;
    uint8_t pin_5 : 1;
    uint8_t pin_6 : 1;
    uint8_t pin_7 : 1;
    uint8_t pin_8 : 1;
};
typedef struct gpio_a_t GPIO_A;

struct __attribute__((packed)) ficticio_struct {
    uint8_t id;
    NAME name;
    uint8_t flag;
    uint32_t gpio_b;
    DIGITOS* ptrDigitos; 
    GPIO_A* ptrA;
};

struct __attribute__((packed)) fifo_struct {
    uint8_t buffer[SIZE];
    uint8_t head;
    uint8_t tail;
};
typedef struct fifo_struct FIFO;

typedef struct str_dados
{
    NAME name;
    TELEFONE telefone;
    uint8_t id;
    uint8_t idade;
    uint8_t nota;
}dados;



