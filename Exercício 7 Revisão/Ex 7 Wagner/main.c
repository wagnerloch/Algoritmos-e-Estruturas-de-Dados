/*
7) Faça um programa que lê n números decimas (n fornecido pelo
usuário), armazenando-os em um vetor. Logo após, uma função deve
retirar os números duplicados que eventualmente possam existir neste
vetor, deixando apenas uma ocorrência de cada número. Ao final, o vetor
resultante deve ser impresso na tela.

Wagner Loch - 14100530
Engenharia de Computação - UFPel
2016/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void removerRepetidos (int *vetor, int *tamanho);
void insertionSort (int *vetor, int tamanhoVetor);
void mergeSort (int *vetor, int posicaoInicio, int posicaoFim);

int main() {
    srand((unsigned)time(NULL));    //semente para gerar números aleatórios

    int *tamanho = (int*) calloc (1, sizeof(int));  //guarda o tamanho do vetor
    int i;
    int *vetor;

    printf ("Tamanho do vetor: ");
    scanf ("%d", tamanho);

    vetor = (int*) calloc (*tamanho, sizeof(int));

    int opcao;
    printf ("Preenchimento manual? 1-S/0-N\n"); //preenchimento automático do vetor com números aleatórios
    scanf ("%d", &opcao);

    if (opcao == 0) { //preenchimento automático
        for (i = 0; i < *(tamanho); i++) {
            vetor[i] = 1 + (rand() % 100); //números de 1 à 100
            printf ("[%2d] = %d\n", i, vetor[i]);
        }
    }
    else if (opcao == 1) {
        for (i = 0; i < *(tamanho); i++) {
            printf ("[%2d] = ", i);
            scanf ("%d", &vetor[i]);
        }
    }
    while (1) {
        int menu;
        printf ("\n1 - Remover numeros repetidos\n");
        printf ("2 - Ordenar com Insertion Sort (vetores pequenos)\n");
        printf ("3 - Ordenar com Merge Sort (vetores maiores)\n");
        printf ("0 - Sair\n");
        scanf ("%d", &menu);
        switch (menu) {
        case 1:
            removerRepetidos (vetor, tamanho);
            printf ("Vetor sem repeticoes:\n");
            for (i = 0; i < *tamanho; i++) {
                printf ("[%2d] = %d\n", i, vetor[i]);
            }
            break;
        case 2:
            insertionSort(vetor, *tamanho);
            printf ("Vetor ordenado com Insertion Sort:\n");
            for (i = 0; i < *tamanho; i++) {
                printf ("[%2d] = %d\n", i, vetor[i]);
            }
            break;
        case 3:
            mergeSort(vetor, 0, *tamanho);
            printf ("Vetor ordenado com Merge Sort:\n");
            for (i = 0; i < *tamanho; i++) {
                printf ("[%2d] = %d\n", i, vetor[i]);
            }
            break;
        case 0:
            free (tamanho);
            free (vetor);
            exit (0);
            break;
        default :
            printf ("Opcao invalida!\n");
        }
    }

    return 0;
}

void removerRepetidos (int *vetor, int *tamanho) {
    int i, j, k;

    for (i = 0; i < *(tamanho); i++) { //percorre todos os valores a partir do primeiro e do segundo testando
        for (j = i+1; j < *(tamanho); j++) {   //se são iguais
            if (vetor[i] == vetor [j]) {
                for (k = j+1; k < *(tamanho); k++) {    //quando acha um valor igual, remover aquele valor puxando os outros
                    vetor [k-1] = vetor [k];    //para frente
                }
                (*(tamanho))--;     //tamanho do vetor diminuiu
                vetor = (int*) realloc (vetor, (*tamanho)*sizeof(int)); //realoca o vetor com o tamanho novo
            }
        }
    }
}

void insertionSort (int *vetor, int tamanhoVetor) {
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

void mergeSort (int *vetor, int posicaoInicio, int posicaoFim) {
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
