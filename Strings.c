#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Pequena adaptacao do codigo feito em sala

int main()
{

    char sorte[] = "amor";
    int tam = strlen(sorte);

    char tentativa[tam + 1];

    int chances = tam;

    // inicializar a string tentativa com _
    for (int i = 0; i < tam; i++)
    {
        tentativa[i] = '_';
    }

    do
    {
        printf("Status: ");

        for (int i = 0; i < tam; i++)
        {
            printf("%c ", tentativa[i]);
        }

        char letra;

        printf("\nDigite uma letra: ");
        scanf("%c", &letra);
        getchar();

        // Navegar pela palavra sorte e atualizar a palavra tentativa com os acertos
        int acertou = 0;
        for (int i = 0; i < tam; i++)
        {
            if (sorte[i] == letra)
            {
                tentativa[i] = letra;
                acertou = 1;
            }
        }

        if (acertou != 1)
        {
            chances--;
        }

        printf("\n");
    } while (strncmp(tentativa, sorte, tam) != 0 && chances > 0);

    if (chances > 0)
    {
        printf("Voce venceu!");
    }
    else
    {
        printf("Morreu!");
    }

    return 0;
}
