#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 50


typedef char NAME[MAX_NAME_LENGTH];
typedef char TELEFONE[MAX_NAME_LENGTH];

struct __attribute__((packed)) gpio_t {
    uint8_t pin_1 : 1;
    uint8_t pin_2 : 1;
    uint8_t pin_3 : 1;
    uint8_t pin_4 : 1;
    uint8_t pin_5 : 1;
    uint8_t pin_6 : 1;
    uint8_t pin_7 : 1;
    uint8_t pin_8 : 1;
};
typedef struct gpio_t GPIO_A;

struct __attribute__((packed)) ficticio_struct {
    uint8_t id;
    NAME name;
    uint8_t flag;
    uint32_t gpio_b;
    //DIGITOS* ptrDigitos; 
    GPIO_A* ptrA;
};




#endif // STRUCT_H

