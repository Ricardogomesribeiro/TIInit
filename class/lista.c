// Created by ric on 06/06/2024.

#include "../includes/lista.h"

//#define TESTE   
/* Implementation of list operations */
int push(Node** head, dados_st new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        return 0; // Failed to allocate memory
    }

    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
    return 1; // Success
}

/* Implementation of pop operation */
int pop(Node** head, dados_st* data){
    if(*head == NULL) {
        return 0; // Stack is empty
    }
    Node* temp = *head;
    *data = temp->data; // Copy data to output parameter
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free the old head node
    return 1; // Success
}

/* Implementation of search operations */
Node* searchId(Node* head, uint8_t id) {
    Node* current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            return current; // Return pointer to the found node
        }
        current = current->next;
    }
    return NULL; // Not found
}

/* Implementation of search by name */
Node* searchName(Node* head, NAME name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return current; // Return pointer to the found node
        }
        current = current->next;
    }
    return NULL; // Not found
}

/* Implementation of delete by ID  */
Node* deleteId(Node* head, uint8_t id) {
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

/* Implementation of delete by name */
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

/* Implementation of getting the last ID */
uint8_t lastId(Node* head) {
    uint8_t last_id = 0;
    Node* current = head;
    while (current != NULL) {
        if(current->data.id > last_id){
            last_id = current->data.id;
        }
        current = current->next;
    }
    return last_id; // Return the highest ID found
}

/* Implementation of printing the list */
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->data.id, current->data.name);
        current = current->next;
    }
}

/*---------------------------------------------------------------------------------------------------------------*/
/* Implementation of including a name in the list */
int includeName(Node** head, NAME name) {
    uint8_t id = lastId(*head) + 1; // Get the next ID
    dados_st new_data = {id, ""};
    /* Ensure the provided name fits in the destination buffer. */
    if (strlen(name) >= sizeof(new_data.name)) {
        return 0; // Name is too long to fit in the buffer
    }
    strncpy(new_data.name, name, strlen(name) + 1); // Copy name to new data, ensuring null-termination
    return push(head, new_data); // Add new data if name is unique
}

/* Implementation of deleting a name from the list */
int deleteNameFromList(Node** head, NAME name) {
    if (head == NULL) {
        return 0; // Node with the specified ID not found
    }
    *head = deleteName(*head, name); // Delete the node with the specified name
    return 1; // Assume deletion is successful for simplicity
}

int changeName(Node* head, NAME name, NAME new_name) {
    Node* node = searchName(head, name);
    if (node == NULL) {
        return 0; // Node with the specified ID not found
    }
    /* Ensure the provided name fits in the destination buffer. */
    if (strlen(new_name) >= sizeof(node->data.name)) {
        return 0; // New name is too long to fit in the buffer
    }
    strncpy(node->data.name, new_name, strlen(new_name) + 1); // Update name, ensuring null-termination
    return 1; // Name change successful
}

#ifdef TESTE
//Test functions

/* Main function for testing */
int main(int argc, char const *argv[])
{
    dados_st data; 
    Node* lista = NULL;   
    if(includeName(&lista, "Alice")) {
        printf("Alice added successfully.\n");
    } else {
        printf("Failed to add Alice.\n");
    }
    if(includeName(&lista, "Bob")) {
        printf("Bob added successfully.\n");
    } else {
        printf("Failed to add Bob.\n");
    }
    if(includeName(&lista, "Charlie")) {
        printf("Charlie added successfully.\n");
    } else {
        printf("Failed to add Charlie.\n");
    }
    printList(lista);
    if(deleteNameFromList(&lista, "Bob")) {
        printf("Bob deleted successfully.\n");
    } else {
        printf("Failed to delete Bob.\n");
    }
    printList(lista);

    changeName(lista, "Alice", "Debora");
    printList(lista);
    return 0;
}
#endif // TESTE