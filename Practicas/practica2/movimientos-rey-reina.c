#include <stdio.h>
#define BOARD_SIZE 8

void initialize_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
void movimientos_validos(char board[][BOARD_SIZE], int x, int y);

int Reina() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col;

    initialize_board(board);

    printf("Ingrese las coordenadas de la reina (x - y) (0 a 7): ");
    scanf("%d", &row);
    scanf("%d", &col);

    movimientos_validos(board, row, col);

    print_board(board);

    return 0;
}

void initialize_board(char board[][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[][BOARD_SIZE]) {
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void movimientos_validos(char board[][BOARD_SIZE], int x, int y) {
    int i, j;

   
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[x][i] != 'X') board[x][i] = '.';
        if (board[i][y] != 'X') board[i][y] = '.';
    }

    
    i = x;
    j = y;
    while (i >= 0 && j >= 0) {
        if (board[i][j] != 'X') board[i][j] = '.';
        i--;
        j--;
    }

    i = x;
    j = y;
    while (i >= 0 && j < BOARD_SIZE) {
        if (board[i][j] != 'X') board[i][j] = '.';
        i--;
        j++;
    }

    i = x;
    j = y;
    while (i < BOARD_SIZE && j >= 0) {
        if (board[i][j] != 'X') board[i][j] = '.';
        i++;
        j--;
    }

    i = x;
    j = y;
    while (i < BOARD_SIZE && j < BOARD_SIZE) {
        if (board[i][j] != 'X') board[i][j] = '.';
        i++;
        j++;
    }

    board[x][y] = 'Q';
}

int Rey() {
    int tablero[8][8] = {0}; 
    int x, y; 
    int i, j; 
    int* ptr; 

    printf("Ingrese las coordenadas del Rey: (X-Y) (0-7) \n");
    scanf("%d %d", &x, &y);

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < 8 && j >= 0 && j < 8) {
                ptr = &tablero[i][j]; 
                if (*ptr != 1) { 
                    *ptr = 2; 
                }
            }
        }
    }

    ptr = &tablero[x][y];
    *ptr = 1;

    printf("   0  1  2  3  4  5  6  7\n"); 
    for (i = 0; i < 8; i++) {
        printf("%d ", i); 
        for (j = 0; j < 8; j++) {
            ptr = &tablero[i][j];
            switch (*ptr) {
                case 0: printf(" . "); break;
                case 1: printf(" R "); break;
                case 2: printf(" * "); break;
            }
        }
        printf("\n");
    }

    return 0;
}

int main() {
    int opcion;
    while (1) {
        printf("Elija una opcion:\n");
        printf("1. Rey\n");
        printf("2. Reina\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                Rey();
                break;
            case 2:
                Reina();
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