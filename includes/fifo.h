
#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SIZE 20

struct __attribute__((packed)) fifo_str {
    uint8_t buffer[SIZE];
    uint8_t head;
    uint8_t tail;
};
typedef struct fifo_str FIFO_t;

void fifo_init(FIFO_t* fifo);
int fifo_is_empty(FIFO_t* fifo);
int fifo_is_full(FIFO_t* fifo);
int fifo_push(FIFO_t* fifo, uint8_t data);
int fifo_pop(FIFO_t* fifo, uint8_t *data);

#endif // FIFO_H