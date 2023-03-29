#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

void enqueue(struct Queue *q, int val) {
    if (q->rear == MAX_SIZE - 1) {
        printf("La cola esta llena.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = val;
}

int dequeue(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("La cola esta vacia.\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front++;
    return val;
}

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, int val) {
    if (s->top == MAX_SIZE - 1) {
        printf("Ya no hay turnos disponibles \n");
        return;
    }
    s->top++;
    s->data[s->top] = val;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Ya no hay turnos disponibles \n");
        return -1;
    }
    int val = s->data[s->top];
    s->top--;
    return val;
}

void printTop(struct Stack *s) {
    if (s->top == -1) {
        printf("Ya no hay turnos disponibles\n");
        return;
    }
    printf("El valor en el tope de la pila es %d.\n", s->data[s->top]);
}

void printLast(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("La cola esta vacia.\n");
        return;
    }
    printf("El ultimo elemento en formarse tiene el valor de turno %d.\n", q->data[q->rear]);
}

int main() {
    struct Queue q;
    initQueue(&q);

    struct Stack s;
    initStack(&s);

    for (int i = 10; i > 0; i--) {
        push(&s, i);
    }

    int choice, val;

    do {
        printf("\nElige una opcion:\n");
        printf("1. Formarse\n");
        printf("2. Salir\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                val = pop(&s);
                if (val != -1) {
                    enqueue(&q, val);
                    printf("Se encuentra formado en el turno %d \n", val);
                }
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (choice != 2);

    printTop(&s);
    printLast(&q);

    return 0;
}