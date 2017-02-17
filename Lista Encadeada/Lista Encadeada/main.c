#include <stdio.h>
#include <stdlib.h>

struct listaNo {
    int data; //cada listaNo cant�m um n�mero
    struct listaNo *proximoPonteiro; //ponteiro para o pr�ximo n�
};

typedef struct listaNo ListaNo;
typedef ListaNo *ListaNoPonteiro;

void inserir (ListaNoPonteiro *sPtr, int valor);
int excluir (ListaNoPonteiro *sPtr, int valor);
int estaVazia (ListaNoPonteiro sPtr);
void imprimirLista (ListaNoPonteiro atualPtr);
void instrucoes (void);

int main()
{
    ListaNoPonteiro inicioPtr = NULL; //inicialmente n�o existem n�s
    int escolha; //escolha do usu�rio
    int dado; //valor inserido pelo usu�rio

    instrucoes(); //exibe o menu
    printf ("?\n");
    scanf("%d", &escolha);

    while (escolha != 4) {
        switch (escolha) {
        case 1: //inserir na lista
            printf ("Digite um numero: ");
            scanf ("%d", &dado);
            inserir(&inicioPtr, dado);
            break;
        case 2: //excluir da lista
            if (!estaVazia(inicioPtr)) { //se a lista n�o estiver vazia
                printf ("Digite o valor a ser excluido: ");
                scanf ("%d", &dado);
                //se o valor for encontrado, � removido
                if (excluir(&inicioPtr, dado)) {
                    printf ("%d excluido.\n", dado);
                }
                else {
                    printf ("O valor %d nao foi encontrado.\n", dado);
                }
            }
            else {
                printf ("A lista esta vazia.\n\n");
            }
            break;
        case 3:
            imprimirLista(inicioPtr);
            break;
        default:
            printf ("Escolha invalida.\n\n");
            instrucoes();
            break;
        }
        printf ("?\n");
        scanf ("%d", &escolha);
    }

    printf ("Fim da execucao!\n\n");
    return 0;
}

//imprime as instru��es na tela
void instrucoes(void) {
    printf ("Digite sua escolha:\n"
            "   1 para inserir um elemento na lista.\n"
            "   2 para excluir um elemento da lista.\n"
            "   3 para imprimir a lista.\n"
            "   4 para terminar");
}

//insere um novo elemento na lista
void inserir (ListaNoPonteiro *sPtr, int valor) {
	ListaNoPonteiro novoPtr; //ponteiro para o novo n�
	ListaNoPonteiro anteriorPtr; //ponteiro para o n� anterior na lista
	ListaNoPonteiro atualPtr; //ponteiro para o n� atual na lista

	novoPtr = malloc (sizeof (ListaNo)); //cria o n�

	if (novoPtr != NULL) { //tudo ok!
		novoPtr -> data = valor; //coloca o valor no n�
		novoPtr -> proximoPonteiro = NULL; //n� n�o se une a outro n�

		anteriorPtr = NULL;
		atualPtr = *sPtr;

		//loop para achar o local correto na lista
		while (atualPtr != NULL && valor > atualPtr -> data) {
			anteriorPtr = atualPtr; //caminha para...
			atualPtr = atualPtr -> proximoPonteiro; // ... pr�ximo n�
		}

		//insere novo n� no in�cio da lista
		if (anteriorPtr == NULL) {
			novoPtr -> proximoPonteiro = *sPtr;
			*sPtr = novoPtr;
		}
		else { //insere novo n� entre anteriorPtr e atualPtr
			anteriorPtr -> proximoPonteiro = novoPtr;
			novoPtr -> proximoPonteiro = atualPtr;
		}
	}
	else {
		printf ("%d nao inserido. Sem memoria disponivel.\n", valor);
	}
}

int excluir (ListaNoPonteiro *sPtr, int valor) {
	ListaNoPonteiro anteriorPtr; //ponteiro para o n� anterior na lista
	ListaNoPonteiro atualPtr; // ponteiro para o n� atual na lista
	ListaNoPonteiro tempPtr; //ponteiro para um n� tempor�rio

	//exclui o primeiro n�
	if (valor == (*sPtr) -> data) {
		tempPtr = *sPtr; //aponta para o n� que est� sendo removido
		*sPtr = (*sPtr) -> proximoPonteiro; //retira thread do n�
		free (tempPtr); //libera o n� com thread retirado
		return valor;
	}
	else {
		anteriorPtr = *sPtr;
		atualPtr = (*sPtr) -> proximoPonteiro;

		//loop para achar local correto na lista
		while (atualPtr != NULL && atualPtr -> data != valor) {
			anteriorPtr = atualPtr; //caminha at�...
			atualPtr = atualPtr -> proximoPonteiro; // ...pr�ximo n�
		}

		//exclui n� em atualPtr;
		if (atualPtr != NULL) {
			tempPtr = atualPtr;
			anteriorPtr -> proximoPonteiro = atualPtr -> proximoPonteiro;
			free (tempPtr);
			return valor;
		}
	}
	return 0;
}

//retorna 1 se a lista estiver vazia, 0 se estiver cheia
int estaVazia (ListaNoPonteiro sPtr) {
	return sPtr == NULL;
}

void imprimirLista (ListaNoPonteiro atualPtr) {
	//se a lista estiver vazia
	if (atualPtr == NULL) {
		printf("Lista esta vazia.\n\n");
	}
	else {
		printf("A lista e:\n");
		//enquanto n�o chegar ao final da lista
		while (atualPtr != NULL) {
			printf("%d --> ", atualPtr -> data);
			atualPtr = atualPtr -> proximoPonteiro;
		}
		printf("NULL\n\n");
	}
}

