/*
    Trabalho Prática 1 Turma M2
    Wagner Loch - 14100530
    Engenharia de Computação - 2016/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerFrase (void *Buffer);
void imprimirMaiusculo (void *Buffer);

int main()
{
    void *buffer = calloc (2 * sizeof(int)
                           + 100 * sizeof(char), 1); //espaço para a primeira frase
    if (buffer == NULL) {
        printf ("Memoria insuficiente!\n");
        exit (-1);
    }
    int *menu = &buffer[0]; //buffer[0] <=> controle do menu
    int *quantidadeDeFrases = &buffer[1 * sizeof(int)]; //buffer[4] <=> quantidade de frases que tem no buffer
    *quantidadeDeFrases = 0;
    char *primeiraFrase = &buffer[2*sizeof(int)]; //buffer[8] <=> endereço da primeira frase
    char *fraseSeguinte = &buffer[2*sizeof(int)];

    do {
        lerFrase (fraseSeguinte);
        (*(quantidadeDeFrases))++;
        buffer = realloc (buffer, (2 * sizeof (int))
                         + (100 * sizeof(char) * (*quantidadeDeFrases+1)));
        fraseSeguinte = &buffer[((2*sizeof(int)) + (100 * sizeof(char) * (*quantidadeDeFrases)))];
        primeiraFrase = &buffer[2*sizeof(int)]; //como foi feita uma nova alocação de memória, tenho que atualizar
        quantidadeDeFrases = &buffer[1*sizeof(int)];    //os valores de referência
        menu = &buffer[0];
        if (buffer == NULL) {
            printf ("Memoria insuficiente!\n");
            exit (-1);
        }
        printf ("1 - Nova frase\n0 - Sair\n");
        scanf ("%d", menu);
        if (*(menu) == 0) {
            while (*(quantidadeDeFrases) > 0) {
                *quantidadeDeFrases = *quantidadeDeFrases - 1;
                imprimirMaiusculo(primeiraFrase);
                primeiraFrase += 100;
                if (*(quantidadeDeFrases) == 0) {   //está entrando nessa condição para encerrar
                    free (buffer);
                    exit (1);
                }
            }
            free (buffer);
            exit (0);
        }
    } while (1);

    return 0;
}

void lerFrase (void *Buffer) {
    fflush (stdin);
    fgets (Buffer, 100, stdin);
}

void imprimirMaiusculo (void *Buffer) {
    printf ("%s", strupr(Buffer));  //função strupr da biblioteca string.h imprime todos os caracteres em maiúsculo
}
