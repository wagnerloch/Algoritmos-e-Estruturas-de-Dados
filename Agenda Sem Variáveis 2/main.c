/*
*   AGENDA SEM VARIÁVEIS UTILIZANDO LISTA ENCADEADA
*   WAGNER LOCH
*   14100530
*   DISCIPLINA DE ALGORÍTMOS E ESTRUTURAS DE DADOS 1 (AED1) 2016/2
*   CURSO DE ENGENHARIA DE COMPUTAÇÃO
*   UNIVERSIDADE FEDERAL DE PELOTAS (UFPEL)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda {
    char nome[30];
    char telefone[15];
    struct agenda *proximoPonteiro;
};

typedef struct agenda Agenda;
typedef Agenda *AgendaPonteiro;

void inserir (AgendaPonteiro *sPtr);
void excluir (AgendaPonteiro *sPtr);
void imprimirAgenda (AgendaPonteiro atualPtr);
void instrucoes (void);

int main()
{
    AgendaPonteiro inicioPtr = NULL;
    int *escolha = (int*) malloc (sizeof(int));

    instrucoes();
    scanf ("%d", escolha);

    while (*escolha != 4) {
        switch (*escolha) {
        case 1:
            inserir(&inicioPtr);
            break;
        case 2:
            excluir(&inicioPtr);
            break;
        case 3:
            imprimirAgenda(inicioPtr);
            break;
        default:
            printf ("Opcao invalida!\n\n");
            break;
        }
        instrucoes();
        scanf ("%d", escolha);
    }
    printf ("Fim da execucao!\n\n");
    free (escolha);
    return 0;
}

void instrucoes(void) {
    printf("AGENDA SEM VARIAVEIS FEITA POR WAGNER LOCH\n\n"
           "    1 - Inserir contato na agenda.\n"
           "    2 - Excluir contato da agenda.\n"
           "    3 - Listar todos os contatos da agenda.\n"
           "    4 - Encerrar execucao.\n");
}

void inserir (AgendaPonteiro *sPtr) {
    AgendaPonteiro novoPtr;
    AgendaPonteiro anteriorPtr;
    AgendaPonteiro atualPtr;

    novoPtr = malloc (sizeof (Agenda));

    if (novoPtr != NULL) {
        fflush(stdin);
        printf ("Nome: ");
        fgets (novoPtr->nome, 30, stdin);
        printf ("Telefone: ");
        fgets (novoPtr->telefone, 15, stdin);
        novoPtr->proximoPonteiro = NULL;

        anteriorPtr = NULL;
        atualPtr = *sPtr;

        /*
        * FAZER AQUI ORDENAÇÃO
        */

        if (anteriorPtr == NULL) {
            novoPtr->proximoPonteiro = *sPtr;
            *sPtr = novoPtr;
        }
        else {
            anteriorPtr->proximoPonteiro = novoPtr;
            novoPtr->proximoPonteiro = atualPtr;
        }
        printf ("\n\nContato adicionado com sucesso!\n");
    }
    else {
        printf ("\nContato nao inserido. Sem memoria disponivel!\n\n");
    }
}

void excluir (AgendaPonteiro *sPtr) {
    AgendaPonteiro anteriorPtr;
    AgendaPonteiro atualPtr;
    AgendaPonteiro tempPtr;

    char *nomeTemp = (char*) malloc (30*sizeof(char));
    fflush(stdin);
    printf ("Nome do contato para exclusao: ");
    fgets (nomeTemp, 30, stdin);

    if (strcmp(nomeTemp, (*sPtr)->nome) == 0) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr) -> proximoPonteiro;
        free (tempPtr);
    }
    else {
        anteriorPtr = *sPtr;
        atualPtr = (*sPtr)->proximoPonteiro;
        while (atualPtr != NULL && (stricmp(nomeTemp, (*sPtr)->nome) != 0)) { //?
            anteriorPtr = atualPtr;
            atualPtr = atualPtr->proximoPonteiro;
        }
        if (atualPtr != NULL) {
            tempPtr = atualPtr;
            anteriorPtr->proximoPonteiro = atualPtr->proximoPonteiro;
            free(tempPtr);
        }
    }
    free(nomeTemp);
}

void imprimirAgenda (AgendaPonteiro atualPtr) {
    if (atualPtr == NULL) {
        printf ("A agenda esta vazia!\n\n");
    }
    else {
        printf ("==============================================\n\n");
        while (atualPtr != NULL) {
            printf ("Nome: %s\nTelefone: %s\n", atualPtr->nome, atualPtr->telefone);
            atualPtr = atualPtr->proximoPonteiro;
        }
        printf ("\n============================================\n\n");
    }
}
