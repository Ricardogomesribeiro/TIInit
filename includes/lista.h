#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 50

typedef char NAME[BUFFER_SIZE];

typedef struct {
    uint8_t id;
    NAME name;
} dados_st;

typedef struct Node {
    dados_st data;
    struct Node* next;
} Node;

#endif // LISTA_H