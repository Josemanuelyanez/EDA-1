#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    char input[MAX];
    char deque[MAX];
    int front = -1, rear = -1;

    printf("Ingrese una cadena de caracteres: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = 0;

    int i = 0;
    while (input[i] != '\0' && i < MAX) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
        }
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            if (front == -1) {
                front = 0;
            }
            rear++;
            deque[rear] = c;
        }
        i++;
    }

    while (front < rear) {
        if (deque[front] != deque[rear]) {
            printf("La cadena no es un palíndromo.\n");
            return 0;
        }
        front++;
        rear--;
    }
    printf("La cadena es un palíndromo.\n");
    return 0;
}