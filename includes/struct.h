#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 50

typedef char NAME[MAX_NAME_LENGTH];

/****************** Funções para manipulação de bits ******************/
typedef union
{
    uint8_t reg;

    struct
    {
        uint8_t pin_1 : 1;
        uint8_t pin_2 : 1;
        uint8_t pin_3 : 1;
        uint8_t pin_4 : 1;
        uint8_t pin_5 : 1;
        uint8_t pin_6 : 1;
        uint8_t pin_7 : 1;
        uint8_t pin_8 : 1;
    } bits;

} gpio_t;
/*
struct __attribute__((packed)) gpio_t {
    uint8_t pin_1 : 1;
    uint8_t pin_2 : 1;
    uint8_t pin_3 : 1;
    uint8_t pin_4 : 1;
    uint8_t pin_5 : 1;
    uint8_t pin_6 : 1;
    uint8_t pin_7 : 1;
    uint8_t pin_8 : 1;
};*/
typedef gpio_t GPIO_A;
typedef gpio_t GPIO_B;

struct __attribute__((packed)) cpu_str{
    uint8_t id;
    NAME name;
    uint8_t flag;
    GPIO_A gpio_a;
    GPIO_B gpio_b;
};



// 1. Definição dos endereços de memória (Baseados no STM32F4, por exemplo)
#define GPIOA_BASE        0x40020000
#define GPIOA_MODER       (*(volatile uint32_t *)(GPIOA_BASE + 0x00)) // Reg. de Modo
#define GPIOA_ODR         (*(volatile uint32_t *)(GPIOA_BASE + 0x14)) // Reg. de Saída


// 1. Definição do mapa de registradores do periférico GPIO
typedef struct {
    volatile uint32_t MODER;   // Offset 0x00 (Modo do pino)
    volatile uint32_t OTYPER;  // Offset 0x04 (Tipo de saída)
    volatile uint32_t OSPEEDR; // Offset 0x08 (Velocidade)
    volatile uint32_t PUPDR;   // Offset 0x0C (Pull-up/Pull-down)
    volatile uint32_t IDR;     // Offset 0x10 (Registrador de Entrada)
    volatile uint32_t ODR;     // Offset 0x14 (Registrador de Saída)
} GPIO_TypeDef;

// 2. Aponta a Struct para o endereço físico da Porta A
//#define GPIOA ((GPIO_TypeDef *) 0x40020000)


#endif // STRUCT_H

