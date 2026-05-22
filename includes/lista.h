/* List operations */
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Buffer size for names */
#define BUFFER_SIZE 50

/* Type definition for a name */
typedef char NAME[BUFFER_SIZE];

/* Type definition for the data structure */
typedef struct {
    uint8_t id;
    NAME name;
} dados_st;

/* Type definition for a node in the list */
typedef struct Node {
    dados_st data;
    struct Node* next;
} Node;

/* Function prototypes */
Node* createNode(dados_st data);
int push(Node** head, dados_st data);
Node* searchName(Node* head, NAME name);
Node* searchId(Node* head, uint8_t id);
Node* deleteId(Node* head, uint8_t id);
Node* deleteName(Node* head, NAME name);
uint8_t lastId(Node* head);
void printList(Node* head);
int includeName(Node** head, NAME name);
int deleteNameFromList(Node** head, NAME name);
int changeName(Node* head, NAME name, NAME new_name);

#endif // LISTA_H