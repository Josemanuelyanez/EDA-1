
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