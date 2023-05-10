#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Node {
    int data;
    struct Node* next;
};

// Función para insertar un nodo al final de la lista
void insert(struct Node** head_ref, int new_data) {
    // Crear el nuevo nodo
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Asignar el dato al nuevo nodo
    new_node->data = new_data;
    // Si la lista está vacía, el nuevo nodo será el primero y el último
    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
        return;
    }
    // Encontrar el último nodo
    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    // Insertar el nuevo nodo después del último
    last->next = new_node;
    new_node->next = *head_ref;
}

// Función para eliminar un nodo de la lista
void delete(struct Node** head_ref, int key) {
    // Si la lista está vacía, no se puede eliminar nada
    if (*head_ref == NULL) {
        return;
    }
    // Si el nodo a eliminar es el primero, actualizar la cabeza de la lista
    if ((*head_ref)->data == key) {
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        *head_ref = (*head_ref)->next;
        last->next = *head_ref;
        free(last);
        return;
    }
    // Buscar el nodo anterior al que se desea eliminar
    struct Node* prev = *head_ref;
    while (prev->next != *head_ref && prev->next->data != key) {
        prev = prev->next;
    }
    // Si el nodo no se encontró, no se puede eliminar nada
    if (prev->next == *head_ref) {
        return;
    }
    // Eliminar el nodo y liberar memoria
    struct Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// Función para imprimir la lista
void printList(struct Node* head) {
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Función para liberar la memoria ocupada por la lista
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head_ref);
    *head_ref = NULL;
}

int main() {
    // Crear la lista inicial
    struct Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Menú de opciones
    int option;
    do {
        printf("\n1. Insertar un elemento\n");
        printf("2. Eliminar un elemento\n");
        printf("3. Imprimir la lista\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:

                // Pedir al usuario el valor a insertar
                {
                int value;  
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &value);
                // Insertar el valor en la lista
                insert(&head, value);
                printf("Elemento insertado correctamente.\n");
                // Mostrar la lista actualizada
                printf("Lista actualizada: ");
                printList(head);
                }
                break;  
                
            case 2:

                // Pedir al usuario el valor a eliminar
                {
                    int key; 
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &key);
                // Eliminar el valor de la lista
                delete(&head, key);
                printf("Elemento eliminado correctamente.\n");
                // Mostrar la lista actualizada
                printf("Lista actualizada: ");
                printList(head);
                }

                break;
            case 3:
                // Imprimir la lista
                printf("Lista: ");
                printList(head);
                break;
            case 4:
                // Salir del programa
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intente de nuevo.\n");
                break;
        }
    } while (option != 4);

    // Liberar la memoria ocupada por la lista
    freeList(&head);

    return 0;
}