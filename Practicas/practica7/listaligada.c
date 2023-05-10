#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *current = head;
    printf("Lista: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    // Crear la lista ligada circular con los numeros del 1 al 5
    Node *head = NULL;
    Node *current = NULL;
    for (int i = 1; i <= 5; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
    }
    current->next = head;

    // Solicitar al usuario un numero para buscar
    int searchNum;
    printf("Ingrese un numero para buscar en la lista: ");
    scanf("%d", &searchNum);

    // Buscar el numero en la lista
    Node *temp = head;
    int found = 0;
    do {
        if (temp->data == searchNum) {
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    // Mostrar el resultado
    if (found) {
        printf("El número se encuentra dentro de la lista .\n" );
        printList(head);
    } else {
        printf("El número no se encuentra dentro de la lista .\n" );
        printList(head);
    }

    // Liberar la memoria
    Node *ptr = head;
    do {
        Node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    } while (ptr != head);

    return 0;
}
