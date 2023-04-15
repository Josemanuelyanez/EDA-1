#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char str[]) {
    int len = strlen(str);
    char deque[len];
    int front = -1, rear = -1;
    
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (isalnum(c)) {  
            if (front == -1) {
                front = 0;
            }
            rear++;
            deque[rear] = tolower(c);
        }
    }
    
    while (front < rear) {
        if (deque[front] != deque[rear]) {
            return false;
        }
        front++;
        rear--;
    }
    return true;
}

int main() {
    char input[100];
    printf("Ingrese una cadena de caracteres: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    if (isPalindrome(input)) {
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena no es un palíndromo.\n");
    }
    return 0;
}
