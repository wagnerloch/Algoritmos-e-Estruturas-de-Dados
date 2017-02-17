/*
Wagner Loch
14100530 - Engenharia de Computação
2016/2

2) (3 Pontos) Implemente a seguinte função. Ela recebe um ponteiro para um buffer que contém uma sequência

de números inteiros e o total de números nessa sequência, respectivamente. Por exemplo: {1, 3, 2, 2, 5, 2} e 6. A

função deve retornar 0 se todos os números que aparecem no buffer aparecem um número ímpar de vezes e 1 caso

contrário. No exemplo a função retorna 0, já no seguinte exemplo retorna 1: {1, 3, 2, 2, 5, 2, 5} e 7. Após

implementar diga qual a complexidade do seu algoritmo no melhor e no pior caso, citando quais são ambos os casos.

int numeros(void *pN, unsigned int t);
*/


#include <stdio.h>
#include <stdlib.h>

int numeros(void *pN, unsigned int t);

int main()
{
    int tamanho, i, retorno;
    printf ("Tamanho do vetor: ");
    scanf ("%d", &tamanho);
    int *vetor = (int *) calloc (tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        printf ("[%d] = ", i);
        scanf ("%d", &vetor[i]);
    }
    retorno = numeros(vetor, tamanho);
    printf ("Retorno da funcao: %d", retorno);
    return 0;
}

int numeros(void *pN, unsigned int t) {
    int i, valor = 0;
    int num1, num2;
    for (i = 0; i < t; i++) {
        num1 = *(int*)(pN);
        pN += sizeof(int);
        num2 = *(int*)pN;
        pN += sizeof(int);
        if (num1 == num2) {
            valor++;
        }
    }
    if ((valor % 2) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
