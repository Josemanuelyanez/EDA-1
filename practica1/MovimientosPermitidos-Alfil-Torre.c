#include <stdio.h>

#define BOARD_SIZE 8

int alfil() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int x, y;
    printf("Introduce las coordenadas del alfil *0-7* *con un espacio* (x y): ");
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        printf("Coordenadas inválidas.\n");
        return 1;
    }
    printf("\n");
    // Marcar la posición actual del alfil
    board[x][y] = 1;
    // Marcar los movimientos permitidos del alfil
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (x+i < BOARD_SIZE && y+i < BOARD_SIZE) {
            board[x+i][y+i] = 2;
        }
        if (x-i >= 0 && y-i >= 0) {
            board[x-i][y-i] = 2;
        }
        if (x+i < BOARD_SIZE && y-i >= 0) {
            board[x+i][y-i] = 2;
        }
        if (x-i >= 0 && y+i < BOARD_SIZE) {
            board[x-i][y+i] = 2;
        }
    }
    // Mostrar el tablero con los movimientos permitidos
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int torre() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int x, y;
    printf("Introduce las coordenadas de la torre *0-7* *con un espacio* (x y): ");
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        printf("Coordenadas inválidas.\n");
        return 1;
    }
    printf("\n");
    // Marcar la posición actual de la torre
    board[x][y] = 1;
    // Marcar los movimientos permitidos de la torre
    for (int i = x+1; i < BOARD_SIZE; i++) {
        board[i][y] = 2;
        if (board[i][y] == 3) break;
        if (board[i][y] == 1) {
            board[i][y] = 3;
            break;
        }
    }
    for (int i = x-1; i >= 0; i--) {
        board[i][y] = 2;
        if (board[i][y] == 3) break;
        if (board[i][y] == 1) {
            board[i][y] = 3;
            break;
        }
    }
    for (int j = y+1; j < BOARD_SIZE; j++) {
        board[x][j] = 2;
        if (board[x][j] == 3) break;
        if (board[x][j] == 1) {
            board[x][j] = 3;
            break;
        }
    }
    for (int j = y-1; j >= 0; j--) {
        board[x][j] = 2;
        if (board[x][j] == 3) break;
        if (board[x][j] == 1) {
            board[x][j] = 3;
            break;
        }
    }
    // Mostrar el tablero con los movimientos permitidos
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int opcion;
    while (1) {
        printf("Elija una opcion:\n");
        printf("1. alfil\n");
        printf("2. torre\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                alfil();
                break;
            case 2:
                torre();
                break;
            case 3:
                printf("Adios!\n");
                return 0;
            default:
                printf("Opcion no valida\n");
        }
    }
    return 0;
}
