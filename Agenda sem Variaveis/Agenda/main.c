#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int indice;
    char nome[30];
    char telefone[15];
} agenda;

void *Excluir (void *PrimeiroContato, char *nomeParaExcluir, int *QuantidadeDeContatos);
void Inserir (void *Contato, int *Quantidade);
void Listar (void *PrimeiroContato, int *QuantidadeDeContatos);
void Buscar (void *PrimeiroContato, char *nome, int *QuantidadeDeContatos);
void Ordenar (void *Buffer, agenda *PosicaoPrimeiroContato, agenda *PosicaoUltimoContato, int *i, int *j, int *k, void *VetorTemp, int *qtdContatos);

int main()
{
    void *buffer = malloc (6*sizeof(int) //variáveis de controle
                           + 1*sizeof (agenda) //aloca pelo menos o espaço de um contato na agenda
                           + 30*sizeof(char));
    void *bufferTemp;
    void *enderecoExclusao;
    int *menu;
    int *quantidadeDeContatos; //quantidade de contatos que estão na agenda
    int *quantidadeDeContatosAuxiliar;
    int *i;
    int *j;
    int *k;
    char *buscaNome;
    agenda *primeiroContato;
    agenda *proximoContato;

    if (buffer == NULL) {   //verifica se a alocação foi feita com sucesso
        printf ("NAO FOI POSSIVEL ALOCAR MEMORIA!\n");
        exit (1);
    }

    menu = buffer; //primeira posição serve para controle do menu
    quantidadeDeContatos = buffer+1*sizeof(int); //segunda posição de inteiros do buffer vai guardar quantos contatos temos na agenda
    *quantidadeDeContatos = 0; //no começo não temos nenhum contato
    quantidadeDeContatosAuxiliar = buffer+2*sizeof(int);
    *quantidadeDeContatosAuxiliar = 0;
    i = buffer+3*sizeof(int);
    *i = 0;
    j = buffer+4*sizeof(int);
    *j = 0;
    k = buffer+5*sizeof(int);
    *k = 0;
    buscaNome = buffer+6*sizeof(int);
    primeiroContato = buffer+6*sizeof(int)+30*sizeof(char);
    proximoContato = primeiroContato;
    do {
        *quantidadeDeContatosAuxiliar = *quantidadeDeContatos;
        if (*(quantidadeDeContatos) >= 2) {
            //chama função para ordenar com Merge Sort
            bufferTemp = calloc (6*sizeof(int)  //alocando em outro posição, depois tem que transferir pra alocar no buffer
                                 + (*(quantidadeDeContatos)+1)*sizeof (agenda), 1);
            Ordenar(buffer, primeiroContato, proximoContato, i, j, k, bufferTemp, quantidadeDeContatosAuxiliar);
            free (bufferTemp);
        }
        printf ("1 - Inserir\n");
        printf ("2 - Excluir\n");
        printf ("3 - Listar\n");
        printf ("4 - Buscar\n");
        printf ("5 - Sair\n");
        scanf ("%d", menu);
        if (*(menu) == 1) {
            Inserir (proximoContato, quantidadeDeContatos);
            *(quantidadeDeContatosAuxiliar) = *(quantidadeDeContatos);
            buffer = realloc (buffer, (6*sizeof(int)
                                       + ((*(quantidadeDeContatos))+1)*sizeof (agenda)
                                       + 30*sizeof(char))
                              );
            if (buffer == NULL) {
                printf ("Nao foi possivel alocar memoria. Realloc\n");
                exit(1);
            }
            menu = buffer;     //atualiza os ponteiros com os novos endereços de memória
            quantidadeDeContatos = buffer+1*sizeof(int);
            quantidadeDeContatosAuxiliar = buffer+2*sizeof(int);
            i = buffer+3*sizeof(int);
            j = buffer+4*sizeof(int);
            k = buffer+5*sizeof(int);
            buscaNome= buffer+6*sizeof(int);
            primeiroContato = buffer+(6*sizeof(int)) + 30*sizeof(char)+1; //MAIS UM ADICIONADO COM AUXILIO DA PLANILHA
            proximoContato = buffer+(6*sizeof(int) + 30*sizeof(char) + (*(quantidadeDeContatos))*sizeof(agenda)); //MENOS UM REMOVIDA DAQUI
        }
        else if (*(menu) == 2) {
            fflush (stdin);
            printf ("Nome para excluir: ");
            fgets (buscaNome, 30, stdin);
            primeiroContato = buffer+(6*sizeof(int) + 30*sizeof(char));
            enderecoExclusao = Excluir(primeiroContato, buscaNome, quantidadeDeContatosAuxiliar);
            if (enderecoExclusao == NULL) {
                printf ("Contato nao localizado para exclusao!\n");
            }
            else {
                    /*
                        implementar aqui a transferência do próximo contato no contato que foi excluído
                    */
                (*(quantidadeDeContatos))--;

                buffer = realloc (buffer, (6*sizeof(int)
                                       + (*(quantidadeDeContatos))*sizeof (agenda)
                                       + 30*sizeof(char))
                              );
                if (buffer == NULL) {
                    printf ("Nao foi possivel alocar memoria. Realloc\n");
                    exit(1);
                }
                menu = buffer;     //atualiza os ponteiros com os novos endereços de memória
                quantidadeDeContatos = buffer+1*sizeof(int);
                quantidadeDeContatosAuxiliar = buffer+2*sizeof(int);
                i = buffer+3*sizeof(int);
                j = buffer+4*sizeof(int);
                k = buffer+5*sizeof(int);
                buscaNome= buffer+6*sizeof(int);
                primeiroContato = buffer+(6*sizeof(int)) + 30*sizeof(char)+1; //MAIS UM ADICIONADO COM AUXILIO DA PLANILHA
                proximoContato = buffer+(6*sizeof(int) + 30*sizeof(char) + (*(quantidadeDeContatos))*sizeof(agenda) + 1); //MENOS UM REMOVIDA DAQUI
                printf("Contato excluido com sucesso!\n");
                *quantidadeDeContatosAuxiliar = *quantidadeDeContatos;
            }
        }
        else if (*(menu) == 3) {
            primeiroContato = buffer+(6*sizeof(int) + 30*sizeof(char));
            Listar (primeiroContato, quantidadeDeContatosAuxiliar);
        }
        else if (*(menu) == 4) {
            fflush (stdin);
            printf ("Nome para buscar: ");
            fgets (buscaNome, 30, stdin);
            primeiroContato = buffer+(6*sizeof(int) + 30*sizeof(char));
            Buscar (primeiroContato, buscaNome, quantidadeDeContatosAuxiliar);
        }
        else if (*(menu) == 5) {
            free (buffer);  //libera a memória e encerra o programa
            exit(0);
        }
    } while (1);
    return 0;
}

void Inserir (void *Contato, int *Quantidade) {
    fflush (stdin);
    (*(Quantidade))++; //incrementa a quantidade de contatos na agenda
    *(int*)Contato = *Quantidade;
    Contato = Contato + sizeof(int);
    printf ("Nome: ");
    fgets (Contato, 30, stdin);
    Contato = Contato + 30;
    printf ("Telefone: ");
    fgets (Contato, 15, stdin);
    Contato = Contato + 15;
}

void Listar (void *PrimeiroContato, int *QuantidadeDeContatos) {
    printf ("\n===============LISTAGEM DA AGENDA===========\n");
    while (*(QuantidadeDeContatos) > 0) {
        printf ("%d)\n", *(int*)PrimeiroContato);
        PrimeiroContato += sizeof(int);
        printf ("%-8s: %s","Nome", (char*)PrimeiroContato);
        PrimeiroContato += 30;
        printf ("%s: %s","Telefone", (char*)PrimeiroContato);
        PrimeiroContato += 15;
        (*(QuantidadeDeContatos))--;
    }
    printf("\n======================FIM===================\n\n");
}
void Buscar (void *PrimeiroContato, char *nome, int *QuantidadeDeContatos) {
    while (*(QuantidadeDeContatos) > 0) {
        if (strstr(nome, PrimeiroContato) != NULL) {
            printf ("%-8s: %s","Nome", (char*)PrimeiroContato);
            PrimeiroContato += 30;
            printf ("%s: %s","Telefone", (char*)PrimeiroContato);
            return;
        } else {
            PrimeiroContato += sizeof(agenda);
        }
        (*(QuantidadeDeContatos))--;
    }
    printf ("Contato nao localizado!\n");
}

void *Excluir (void *PrimeiroContato, char *nomeParaExcluir, int *QuantidadeDeContatos) {
    while (*(QuantidadeDeContatos) > 0) {
        if (strstr(nomeParaExcluir, PrimeiroContato) != NULL) {    //achou o contato para exclusão
            PrimeiroContato = (PrimeiroContato + sizeof(agenda)); //sobrepõe o próximo contato no contato excluído
            return PrimeiroContato;   //excluído com sucesso
        }
        PrimeiroContato += sizeof(agenda);
        (*(QuantidadeDeContatos))--;
    }
    return NULL; //contato não localizado para exclusão
}

void Ordenar (void *Buffer, agenda *PosicaoPrimeiroContato, agenda *PosicaoUltimoContato, int *i, int *j, int *k, void *VetorTemp, int *qtdContatos) {
    if (PosicaoPrimeiroContato == PosicaoUltimoContato) {
        return;
    }
}
