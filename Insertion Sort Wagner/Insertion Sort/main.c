#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortCrescente (int *vetor, int tamanhoVetor);
void insertionSortDecrescente (int *vetor, int tamanhoVetor);

int main()
{
    int tamanho;
    int i;
    int opcao;
    int *numeros;

    srand((unsigned)time(NULL));

    printf("Tamanho do vetor: ");
    scanf ("%d", &tamanho);

    numeros = (int *) calloc (tamanho, sizeof(int));

    printf ("Preenchimento automatico? 1=S, 0=N\n");
    scanf ("%d", &opcao);
    if (opcao == 0) {
        for (i = 0; i < tamanho; i++) {
            printf ("Vetor [%2d]: ", i);
            scanf ("%d", &numeros[i]);
        }
    }
    else {
        for (i = 0; i < tamanho; i++) {
            numeros[i] = 1 + (rand() % 100); //números aleatórios de 1 a 100
            printf("Vetor [%2d]: %d\n", i, numeros[i]);
        }
    }

    printf("\nVetor ordenado:\n");
    insertionSortDecrescente(numeros, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("Vetor [%2d]: %d\n", i, numeros[i]);
    }
    return 0;
}

void insertionSortCrescente (int *vetor, int tamanhoVetor) {

    int temp, i, j;
    for (j = 1; j < tamanhoVetor; j++) {
        i = j-1;
        temp = vetor[j];
        while ((i >= 0) && (temp < vetor[i])) {
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = temp;
    }
}

void insertionSortDecrescente (int *vetor, int tamanhoVetor) {

    int temp, i, j;
    for (j = 1; j < tamanhoVetor; j++) {
        i = j-1;
        temp = vetor[j];
        while ((i >= 0) && (temp > vetor[i])) {
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = temp;
    }
}
