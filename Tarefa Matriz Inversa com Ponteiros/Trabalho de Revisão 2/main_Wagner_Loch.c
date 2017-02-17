/*  Wagner Loch
    14100530
    Engenharia de Computação
    Tarefa prática de revisão (2)
    Inverter Matriz
*/
#include <stdio.h>
#include <stdlib.h>

int **criarMatriz(int linhas, int colunas);

int main()
{
    int **matrizPtr;
    int qtdLinhas, qtdColunas;
    int i, j;
    int auxiliar;

    printf("Quantidade de linhas: ");
    scanf("%d", &qtdLinhas);
    printf("Quantidade de colunas: ");
    scanf("%d", &qtdColunas);

    matrizPtr = criarMatriz (qtdLinhas, qtdColunas);

    printf("MATRIZ INSERIDA:\n\n");
    for (i = 0; i < qtdLinhas; i++) {
        for (j = 0; j < qtdColunas; j++) {
            printf("%2d ", matrizPtr[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < qtdLinhas; i++){
        for(j = i+1; j < qtdColunas; j++){
            auxiliar = matrizPtr[i][j];
            matrizPtr[i][j] = matrizPtr[j][i];
            matrizPtr[j][i] = auxiliar;
        }
    }

    printf("\nMATRIZ INVERTIDA:\n\n");
    for (i = 0; i < qtdLinhas; i++) {
        for (j = 0; j < qtdColunas; j++) {
            printf("%2d ", matrizPtr[i][j]);
        }
        printf("\n");
    }

    free (matrizPtr);


    return 0;
}

int **criarMatriz(int linhas, int colunas) {

    int **matriz;
    int i, j;
    int valor = 1;

    matriz = (int**) calloc (linhas, sizeof(int*));

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int*) calloc (colunas, sizeof(int));
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = valor++;
        }
    }
    return matriz;
}
