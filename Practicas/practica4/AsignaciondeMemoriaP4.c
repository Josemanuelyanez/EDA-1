#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 8

struct Position {
    int x;
    int y;
};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE;
}

void markPossibleMoves(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char piece) {
    if (piece == 'c') {
        int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
        int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && board[nx][ny] == ' ') {
                board[nx][ny] = 'x';
            }
        }
    } else if (piece == 't') {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i != y && board[x][i] == ' ') {
                board[x][i] = 'x';
            }
            if (i != x && board[i][y] == ' ') {
                board[i][y] = 'x';
            }
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char piece;
    struct Position pos;

    printf("¿Qué pieza de ajedrez desea conocer su posición? (c: caballo, t: torre)\n");
    scanf("%c", &piece);

    printf("Ingrese las coordenadas de la pieza (x, y): ");
    scanf("%d, %d", &pos.x, &pos.y);

    // inicializar el tablero
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    board[pos.x][pos.y] = piece;
    markPossibleMoves(board, pos.x, pos.y, piece);
    printBoard(board);

    return 0;
}
