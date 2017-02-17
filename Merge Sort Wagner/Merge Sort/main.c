#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort (int *vetor, int posicaoInicio, int posicaoFim);

int main()
{
    srand((unsigned)time(NULL));
    int tamanho, i, opcao;
    int *vetor;

    printf ("Tamanho do vetor: ");
    scanf ("%d", &tamanho);

    vetor = (int *) calloc (tamanho, sizeof(int));

    printf ("Preenchimento automatico? 1-S / 0-N\n");
    scanf ("%d", &opcao);

    if (opcao == 0) {
        for (i = 0; i < tamanho; i++) {
            printf ("[%2d] = ", i);
            scanf ("%d", &vetor[i]);
        }
    }
    else {
        for (i = 0; i < tamanho; i++) {
            vetor[i] = 1 + (rand() % 100); //números aleatórios de 1 a 100
            printf ("[%2d] = %d\n", i, vetor[i]);
        }
    }

    printf ("\nVETOR ORDENADO:\n");
    mergeSort (vetor, 0, tamanho-1);
    for (i = 0; i < tamanho; i++) {
        printf ("[%2d] = %d\n", i, vetor[i]);
    }
    return 0;
}

void mergeSort (int *vetor, int posicaoInicio, int posicaoFim){
    int i, j, k, metadeTamanho;
    int *vetorTemp;

    if (posicaoInicio == posicaoFim) {
        return;
    }

    metadeTamanho = (posicaoInicio + posicaoFim) / 2;

    mergeSort (vetor, posicaoInicio, metadeTamanho);
    mergeSort (vetor, metadeTamanho+1, posicaoFim);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;

    vetorTemp = (int *) malloc (sizeof (int) * (posicaoFim-posicaoInicio+1));
    while ((i < metadeTamanho+1) || (j < posicaoFim+1)) {
        if (i == metadeTamanho+1) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim+1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }

    for (i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i-posicaoInicio];
    }
    free (vetorTemp);
}
