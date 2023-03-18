#include <stdio.h>
#define BOARD_SIZE 8

void initialize_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
void movimientos_validos(char board[][BOARD_SIZE], int x, int y);

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

struct Coordenadas {
    int x;
    int y;
};

void mostrarTablero(char tablero[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }

}

int caballo() {
    char tablero[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    
    struct Coordenadas caballo;
    
    printf("Introduzca las coordenadas iniciales del caballo:\n");
    printf("Coordenada x: ");
    scanf("%d", &caballo.x);
    printf("Coordenada y: ");
    scanf("%d", &caballo.y);
    
    tablero[caballo.x][caballo.y] = 'C';
    
    // Mostrar movimientos posibles
    for (int i = caballo.x - 2; i <= caballo.x + 2; i++) {
        for (int j = caballo.y - 2; j <= caballo.y + 2; j++) {
            if (i == caballo.x && j == caballo.y) {
                continue;
            }
            if (i >= 0 && i < 8 && j >= 0 && j < 8) {
                if ((i == caballo.x - 2 || i == caballo.x + 2) && (j == caballo.y - 1 || j == caballo.y + 1)) {
                    tablero[i][j] = 'X';
                } else if ((i == caballo.x - 1 || i == caballo.x + 1) && (j == caballo.y - 2 || j == caballo.y + 2)) {
                    tablero[i][j] = 'X';
                }
            }
        }
    }
    
    mostrarTablero(tablero);
    
    return 0;
}

void menu() {
    int opcion;

    do {
        printf("Bienvenido al menú.\n");
        printf("1. Rey\n");
        printf("2. Reina\n");
        printf("3. Alfil\n");
        printf("4. Torre\n");
        printf("5. Caballo\n");
        printf("6. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                Rey();
                break;
            case 2:
                Reina();
                break;
            case 3:
                alfil();
                break;
            case 4:
                torre();
                break;
            case 5:
                caballo();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Elige una opción del 1 al 6.\n");
                break;
        }
    } while (opcion != 6);
}

int main() {
    menu();
    return 0;
}