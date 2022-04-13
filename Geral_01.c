#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BOARD_SIZE 8
#define SORT_SIZE 10

int main()

{
    srand(time(NULL));

    int aux_line, aux_column, placed = 0, kill = 0;
    int i, j;
    int board[BOARD_SIZE][BOARD_SIZE];

    // Preenche inicialmente todos os valores como zero
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Coloca as peças no board
    for (i = 0; i <= SORT_SIZE; i++) // Roda uma vez a mais para colocar a torre
    {
        placed = 0;

        // Roda até conseguir colocar em uma posição não ocupada
        do
        {
            aux_line = rand() % BOARD_SIZE;
            aux_column = rand() % BOARD_SIZE;

            // Verifica se a posição está ocupada
            if (i != SORT_SIZE && board[aux_line][aux_column] == 0)
            {
                board[aux_line][aux_column] = 1; // Caso nao, a peca e colocada
                placed = 1;                      // E o booleano informa que ela foi colocada para encerrar o do-while
            }

            // Na ultima iteracao, a torre sera adiciona em uma posicao nao ocupada
            else if (i == SORT_SIZE && board[aux_line][aux_column] == 0)
            {
                board[aux_line][aux_column] = 2; // Como é a última iteração, essa informação ficará salva nas auxiliares
                placed = 1;
            }
        } while (placed == 0);
    }

    // Print de checagem
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Verifica se torre consegue derrubar uma peca
    for (i = 0; i < BOARD_SIZE; i++)
    {
        // Itera dentro de uma coluna fixa as outras 7 posicoes e checa se ha uma posicao ocupada
        if (i != aux_line && board[i][aux_column] != 0)
        {
            printf("jogador2 derruba uma pedra na vertical\n");
            kill = 1; // Evita o print caso nenhuma pedra tenha sido identificad
            break;    // Termina o loop ja que um alvo ja foi identificado
        }

        // Realiza o processo descrito acima dentro de uma linha fixa
        if (i != aux_column && board[aux_line][i] != 0)
        {
            printf("jogador2 derruba uma pedra na horizontal\n");
            kill = 1;
            break;
        }
    }

    // Caso nenhuma kill tenha sido registrada, ele informa
    if (kill == 0)
    {
        printf("jogador2 nao derruba nenhuma pedra\n");
    }

    return 0;
}