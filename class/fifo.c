

#include "fifo.h"

// index = (index +1) % SIZE quando chegda no fim, volta para inicio ou cheia
// head == tail quando a fila está vazia
// head != tail quando a fila tem elementos
// tail == (head + 1) % SIZE para calcular cheia

void fifo_init(FIFO_t* fifo){
    memset(fifo->buffer, 0, SIZE); // Opcional: inicializa o buffer com zeros
    fifo->head = 0;
    fifo->tail = 0;
}

int fifo_is_empty(FIFO_t* fifo){
    return (fifo->head == fifo->tail);
}

int fifo_is_full(FIFO_t* fifo){
    return ((fifo->tail + 1) % SIZE == fifo->head);
}

int fifo_push(FIFO_t* fifo, uint8_t data){
    if (fifo_is_full(fifo)) {
        return -1; // Fila cheia
    }
    fifo->buffer[fifo->tail] = data; // Adiciona o elemento no final da fila
    fifo->tail = (fifo->tail + 1) % SIZE; // Move o tail para a próxima posição
    return 0; // Sucesso
}

int fifo_pop(FIFO_t* fifo, uint8_t *data){
    if (fifo_is_empty(fifo)) {
        return -1; // Fila vazia
    }
    *data = fifo->buffer[fifo->head]; // Obtém o elemento do início da fila
    fifo->head = (fifo->head + 1) % SIZE; // Move o head para a próxima posição
    return 0; // Sucesso
}