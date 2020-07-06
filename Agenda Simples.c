/*
	Tentem entender o código feito abaixo.
	Está com comentários e acredito que esteja bem didático.
	Se tiverem alguma dúvida é só chamar!!

	Wagner Loch
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 5

/*
	Perfeito, criou uma estrutura do tipo de usuário! Ok.
*/
typedef struct{
	char nome[50];
	char telefone[20]; //+xx xx xxxxx xxxx
	char email [50];
} tipo_pessoa;

/*
	Optei por criar o vetor de forma global, para poder acessar em outras funções sem se precisar com passagem de argumentos...
	Como não há restrição, não vejo problema por agora...
*/
tipo_pessoa lista[TAM];

/*
	Aqui são declaradas as funções que serão utilizadas no programa...
*/
void imprimirMenu();
void cadastrarUsuario(int i);
void exibirLista (int qtdUsuariosCadastrados);

int main(){

	//Declaro variáveis para controle
    int option;
    int qtdUsuariosCadastrados = 0;

    //Aqui é a jogada, faz um loop infinito com o controle do usuário
    //Primeiro imprime as opções do menu e logo em seguida captura a opção do suário
    //Com cada opção, faz uma rotina diferente
    //O ideal seria utilizar switch, mas não tem problema com if's
    while (1) {
        imprimirMenu();
        scanf("%d", &option);
        if (option == 0) {
        	return 0;
        }
        else if (option == 1) {
        	//É importante verificar se atingiu o tamanho máximo, pois daí informa pro usuário e não faz mais inserções
            if (qtdUsuariosCadastrados == TAM) {
                printf("Quantidade máxima!!!\n");
            } else {
            	//Se tiver lugar ainda chama a rotina de inserção
                cadastrarUsuario(qtdUsuariosCadastrados);
                //Depois de cadastrar o usuário, incrementa o controle de quantos usuários estão cadastrados
                qtdUsuariosCadastrados++;
                printf("Usuario cadastrado com sucesso!\n\n");
            }
        }
        else if (option == 2) {
        	//Chama a função para exibir a lista informando quantos usuários estão cadastrados
            exibirLista(qtdUsuariosCadastrados);
        } else {
        	printf("Opção não encontrada!!\n");
        }
    }
}

void imprimirMenu() {
    printf("SELECIONE A OPÇÃO DESEJADA\n");
    printf("1 - Cadastrar novo cliente.\n");
    printf("2 - Visualizar clientes cadastrados.\n");
    printf("0 - Finalizar programa.\n");
}

void cadastrarUsuario(int i) {
    fflush(stdin);
    printf("Insira o nome da pessoa %d:\n", i+1);
    gets(lista[i].nome);
    fflush(stdin);
    printf("Insira o telefone de pessoa %d (+XX XX XXXXX XXXX):\n", i+1);
    gets(lista[i].telefone);
    fflush(stdin);
    printf("Insira o e-mail da pessoa %d:\n", i+1);
    gets(lista[i].email);
    fflush(stdin);
}

void exibirLista (int qtdUsuariosCadastrados) {
	//Imprime todos os usuários que estão cadastrados conforme a estrutura abaixo...
    for (int i = 0; i < qtdUsuariosCadastrados; i++) {
        printf("====== USUARIO %d ======\n", i);
        printf("Nome: %s\n", lista[i].nome);
        printf("Telefone: %s\n", lista[i].telefone);
        printf("E-mail: %s\n", lista[i].email);
        printf("==============================\n");
    }
}
