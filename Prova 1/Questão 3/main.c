/*
Wagner Loch
14100530 - Engenharia de Computação
2016/2

3) (4 Pontos) Implemente a seguinte função. Ela recebe uma string que contém uma ou mais palavras, a função

deve alterar a string para que a menção as palavras seja na ordem inversa. Por exemplo: entrada “estudante sou eu”

saída “eu sou estudante”. A função não pode usar alocação dinâmica de memória nem usar vetores ou matrizes

além da string de entrada.

void inverte(char *pS);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char *pS);

int main (void) {
    char string[100];
    printf ("Frase: ");
    fgets (string, 100, stdin);
    inverte (string);
    return 0;
}

void inverte(char *pS) {
    int tamanhoFrase = strlen(pS);
    int tamanhoPalavra = 0;
    int i, j;
    printf ("Tamanho: %d\n", tamanhoFrase);
    for (i = tamanhoFrase-2; i >= 0; i--) {
        tamanhoPalavra++;
        if ((pS[i] == ' ') || (i == 0)) {    //se o conteúdo for um espaço
            for (j = i; j < tamanhoPalavra+i; j++) {
                printf ("%c", pS[j]);
            }
            printf (" ");
            tamanhoPalavra = 0;
        }
    }
}
