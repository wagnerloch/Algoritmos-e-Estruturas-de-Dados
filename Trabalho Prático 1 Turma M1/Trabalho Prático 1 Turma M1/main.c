#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sair (char *primeiraPalavra, int *quantidadePalavras);

int main()
{
    void *buffer = calloc (2*sizeof(int) + 20*sizeof(char), 1);
    int *menu = &buffer[0];
    int *quantidadeDePalavras = &buffer[sizeof(int)];
    char *primeiraPalavra = &buffer[2*sizeof(int)];
    char *proximaPalavra = &buffer[2*sizeof(int)];
    *quantidadeDePalavras = 0;

    do {
        fflush (stdin);
        fgets (proximaPalavra, 20, stdin);
        printf ("1 - Nova palavra\n0 - Sair\n");
        scanf ("%d", menu);
        if (*(menu) == 1) {
            (*(quantidadeDePalavras))++;
            buffer = realloc (buffer, (2*sizeof(int) + (20*sizeof(char) * (*quantidadeDePalavras+1))));
            menu = &buffer[0];
            quantidadeDePalavras = &buffer[sizeof(int)];
            primeiraPalavra = &buffer[2*sizeof(int)];
            proximaPalavra = &buffer[(2*sizeof(int) + (20*sizeof(char)*(*(quantidadeDePalavras))))];
        }
        else {
            while (*(quantidadeDePalavras) > 0) {
                if (strcmp (primeiraPalavra, proximaPalavra) > 0) { //compara a primeira com a última palavra
                    printf ("%s", proximaPalavra);
                }
                *(quantidadeDePalavras) = *(quantidadeDePalavras)-1;
            }
            sair (primeiraPalavra, quantidadeDePalavras);
            free (buffer);
            exit (0);
        }
    } while(1);

    return 0;
}

void sair (char *primeiraPalavra, int *quantidadePalavras) {

}
