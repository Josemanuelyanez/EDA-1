#include <stdio.h>

//este programa cifra mensajes para convertirlos en codigo cesar

#define TAM_PALABRA 20
#define TAM_ABC 26

char abecedario[TAM_ABC] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char abecedarioCifrado [26] = {'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C'};

void cifrar (char *TextoOriginal );
void descifrar (char *Textocifrado);

int main () {

    short opcion = 0, contador; 
    char palabra[TAM_PALABRA]; 
    while (1){ 
        printf("\n \tCIFRAR MENSAJES CON EL METODO CESAR \n"); 
        for (contador=0 ; contador<26; contador++) 
        printf("%c", *(abecedario+contador)); 
         printf("\n"); 
        for (contador=0 ; contador<26; contador++) 
            printf("%c", *(abecedarioCifrado+contador)); 
            printf("\nElegir una opción:\n"); 
            printf("1) Cifrar\n"); 
            printf("2) Descifrar.\n"); 
            printf("3) Salir.\n"); 
            scanf("%d", &opcion);
         switch(opcion){ 
            case 1: 
                printf("Ingresar la palabra a cifrar (en mayúsculas): ");  scanf("%s", palabra); 
                 cifrar(palabra); 
            break; 
            case 2: 
                printf("Ingresar la palabra a descifrar (en mayúsculas): ");  scanf("%s", palabra);
                descifrar(palabra); 
            break; 
            case 3: 
            return 0; 
                default: 
                printf("Opción no válida."); 
            } 
        }   
    return 0; 
} 
void cifrar(char *TextoOriginal){ 
    printf("El texto %s cifrado es: ", TextoOriginal); 
    int contadorAbcedario, contadorPalabra, indice = 0; 
    for (contadorPalabra=0 ; contadorPalabra<TextoOriginal[contadorPalabra] ; contadorPalabra++) 
     for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++) 
     if (abecedario[contadorAbcedario] == 
        TextoOriginal[contadorPalabra]){ 
     printf("%c", abecedarioCifrado[contadorAbcedario]);  contadorAbcedario = 26; 
    } 
 printf("\n"); 
} 
void descifrar(char *textoCifrado){ 
    printf("El texto %s descifrado es: ", textoCifrado); 
    int contadorAbcedario, contadorPalabra, indice = 0; 
    for (contadorPalabra=0 ; contadorPalabra<textoCifrado[contadorPalabra] ; contadorPalabra++) 
    for (contadorAbcedario=0 ; contadorAbcedario<TAM_ABC ; contadorAbcedario++) 
    if (abecedarioCifrado[contadorAbcedario] == 
    textoCifrado[contadorPalabra]){ 
    printf("%c", abecedario[contadorAbcedario]);  contadorAbcedario = 26; 
    } 
 printf("\n"); 
}