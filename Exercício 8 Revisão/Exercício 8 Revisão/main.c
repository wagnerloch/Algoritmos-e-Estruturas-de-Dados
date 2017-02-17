/*
    8) Faça um programa que leia uma string (de 80 caracteres) chamada linha
    e, com uma função, identifique cada palavra (substring) desta linha
    copiando-a para um novo vetor. Ao final, o programa deve imprimir as
    palavras separadas, uma palavra por linha.
    Dicas: i) faça uma função para identificar o fim e/ou o início de cada substring em linha

    Wagner Loch - 14100530
    Engenharia de Computação - 2016/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring (char *frase);

int main()
{
    char *linha = (char *) calloc (80, sizeof(char));
    fgets (linha, 80, stdin);
    substring (linha);
    free (linha);
    return 0;
}

void substring (char *frase) {
    char *token;
    token = strtok (frase, " ,.-!?"); //strtok retorna NULL no ponteiro onde tem os caracteres
    while (token != NULL) {
        printf ("%s\n", token);
        token = strtok (NULL, " ,.-!?");
    }
}
