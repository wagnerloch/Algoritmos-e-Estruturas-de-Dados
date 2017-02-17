#include <stdio.h>
#include <stdlib.h>

struct filaNo {
	int data;
	struct filaNo *proximoPonteiro;
};

typedef struct filaNo FilaNo;
typedef FilaNo *FilaNoPonteiro;

void imprimirFila (FilaNoPonteiro atualPonteiro);
int estaVazia (FilaNoPonteiro cabecaPonteiro);
int desenfileirar (FilaNoPonteiro *cabecaPonteiro, FilaNoPonteiro *caudaPonteiro);
void enfileirar (FilaNoPonteiro *cabecaPonteira, FilaNoPonteiro *caudaPonteiro, int value);
void instrucoes (void);

int main()
{
    FilaNoPonteiro cabecaPonteiro = NULL;
    FilaNoPonteiro caudaPonteiro = NULL;
    int escolha;
    int valor;

    instrucoes ();
    printf("?\n");
    scanf ("%d", &escolha);

    //enquanto o usuário não digitar 4
    while (escolha != 4) {
    	switch (escolha) {
    		case 1: //enfileira valor
    			printf ("Digite um valor: ");
    			scanf ("%d", &valor);
    			enfileirar (&cabecaPonteiro, &caudaPonteiro, valor);
    			break;
    		case 2: //desenfileira valor
    			//se a fila não estiver vazia
    			if (!estaVazia(cabecaPonteiro)) {
    				printf ("%d saiu da fila!\n", desenfileirar(&cabecaPonteiro, &caudaPonteiro));
    			}
    			break;
    		case 3: //imprime a fila
    			imprimirFila (cabecaPonteiro);
    			break;
    		default:
    			printf("Escolha invalida!\n\n");
    			instrucoes();
    			break;
    	}
    	printf("?\n");
    	scanf ("%d", &escolha);
    }
    printf("Fim da execucao!\n");
    return 0;
}


void instrucoes (void) {
	printf("Digite sua escolha:\n"
		"	1 para incluir um item na fila.\n"
		"	2 para remover um item da fila.\n"
		"	3 para imprimir a fila.\n"
		"	4 para encerrar.\n");
}

//insere um nó na cauda da fila
void enfileirar (FilaNoPonteiro *cabecaPonteiro, FilaNoPonteiro *caudaPonteiro, int value) {
	FilaNoPonteiro novoPonteiro; //ponteiro para um novo nó
	novoPonteiro = malloc (sizeof (FilaNo));

	if (novoPonteiro != NULL) {
		novoPonteiro->data = value;
		novoPonteiro->proximoPonteiro = NULL;

		//se estiver vazia insere nó na cabeça
		if (estaVazia (*cabecaPonteiro)) {
			*cabecaPonteiro = novoPonteiro;
		}
		else {
			(*caudaPonteiro)->proximoPonteiro = novoPonteiro;
		}
		*caudaPonteiro = novoPonteiro;
	}
	else {
		printf ("%d nao inserido. Nao ha memoria disponivel.\n", value);
	}
}

//remove nó da cabeça da fila
int desenfileirar (FilaNoPonteiro *cabecaPonteiro, FilaNoPonteiro *caudaPonteiro) {
	int valor; //valor do nó
	FilaNoPonteiro tempPonteiro; //ponteiro de nó temporário

	valor = (*cabecaPonteiro) -> data;
	tempPonteiro = *cabecaPonteiro;
	*cabecaPonteiro = (*cabecaPonteiro) -> proximoPonteiro;

	//se a fila estiver vazia
	if (*cabecaPonteiro == NULL) {
		*caudaPonteiro = NULL;
	}

	free (tempPonteiro);
	return valor;
}

//retorna 1 se a lista estiver vazia; caso contrário, retorna 0
int estaVazia (FilaNoPonteiro cabecaPonteiro) {
	return cabecaPonteiro == NULL;
}

//imprime a fila
void imprimirFila (FilaNoPonteiro atualPonteiro) {
	//se a fila estiver vazia
	if (atualPonteiro == NULL) {
		printf ("A fila esta vazia!\n\n");
	}
	else {
		printf("A fila e:\n");
		//enquanto não for fim da fila
		while (atualPonteiro != NULL) {
			printf("%d --> ", atualPonteiro -> data);
			atualPonteiro = atualPonteiro -> proximoPonteiro;
		}

		printf ("NULL\n\n");
	}
}
