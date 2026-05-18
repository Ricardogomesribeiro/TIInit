#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

typedef struct Node{
    dados data;
    struct Node* next;
} Node;

int push(Node** head, dados new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        return 0; // Failed to allocate memory
    }

    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
    return 1; // Success
}

int pop(Node** head, dados* data){
    if(*head == NULL) {
        return 0; // Stack is empty
    }
    Node* temp = *head;
    *data = temp->data; // Copy data to output parameter
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free the old head node
    return 1; // Success
}

dados* searchId(Node* head, uint8_t id) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            return &(current->data); // Return pointer to the found data
        }
        current = current->next;
    }
    return NULL; // Not found
}

dados* searchName(Node* head, NAME name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return &(current->data); // Return pointer to the found data
        }
        current = current->next;
    }
    return NULL; // Not found
}

Node* deleteNode(Node* head, uint8_t id) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data.id == id) {
            if (previous == NULL) {
                head = current->next; // Deleting the head node
            } else {
                previous->next = current->next; // Bypass the current node
            }
            free(current); // Free the deleted node
            return head; // Return the new head of the list
        }
        previous = current;
        current = current->next;
    }
    return head; // Return the head if no node was deleted
}

Node* deleteName(Node* head, NAME name) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                head = current->next; // Deleting the head node
            } else {
                previous->next = current->next; // Bypass the current node
            }
            free(current); // Free the deleted node
            return head; // Return the new head of the list
        }
        previous = current;
        current = current->next;
    }
    return head; // Return the head if no node was deleted
}

/*
int main(int argc, char const *argv[])
{
    Node* lista = NULL;   
    return 0;
}*/
