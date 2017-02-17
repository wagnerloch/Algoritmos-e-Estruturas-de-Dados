#include <stdio.h>
#include <stdlib.h>

int **criarMatriz (int linhas, int colunas);

int **inverterMatriz (int **matriz);

int **desalocarMatriz (int linhas, int colunas, int **matriz);

int MATRIZ = 0;

int main (void) {

    int **matrizPtr;
    int i, j;
    int auxiliar;

    matrizPtr = criarMatriz(5, 5);

    printf ("MATRIZ INSERIDA:\n\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf ("%2d ", matrizPtr[i][j]);
        }
        printf ("\n");
    }

    for (i = 0; i < 5; i++) {
        for (j = i+1; j <5; j++) {
            auxiliar = matrizPtr[i][j];
            matrizPtr[i][j] = matrizPtr[j][i];
            matrizPtr[j][i] = auxiliar;
        }
    }

    printf ("\nMATRIZ INVERTIDA:\n\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf ("%2d ", matrizPtr[i][j]);
        }
        printf("\n");
    }

    free (matrizPtr);
    matrizPtr = NULL;

    return 0;
}

int **criarMatriz (int linhas, int colunas) {

    int **matriz;
    int i, j;
    int valor = 1;

    matriz = (int**) calloc (linhas, sizeof(int*));

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int*) calloc (colunas, sizeof(int));
    }
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = valor;
            valor++;
        }
    }

    return (matriz);
}
