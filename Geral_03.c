#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BOARD_SIDE 4

int main()

{
    srand(time(NULL));
    int board[BOARD_SIDE][BOARD_SIDE];
    int board_size = BOARD_SIDE * BOARD_SIDE;
    int numbs_size = board_size / 2;
    int numbs[numbs_size], found_numbs[numbs_size];

    int i, j, placed = 0, placed2 = 0, player1 = 0, player2 = 0;
    int rounds = 0;
    int aux_line, aux_column, aux_line_2, aux_column_2;

    // Preenche inicialmente todos os valores como zero
    for (i = 0; i < BOARD_SIDE; i++)
    {
        for (j = 0; j < BOARD_SIDE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Preenche os valores de numbs de 1 a N e found_numbs de 0
    for (i = 0; i < numbs_size; i++)
    {
        numbs[i] = i + 1;
        found_numbs[i] = 0;
    }

    // Sorteia os numeros no tabuleiro 2 vezes
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < numbs_size; i++)
        {
            placed = 0;

            // Roda ate conseguir colocar em uma posicao não ocupada
            do
            {
                aux_line = rand() % BOARD_SIDE;
                aux_column = rand() % BOARD_SIDE;

                // Verifica se a posicao nao esta ocupada
                if (board[aux_line][aux_column] == 0)
                {
                    board[aux_line][aux_column] = numbs[i]; // Caso nao, a peca e colocada
                    placed = 1;
                }

            } while (placed == 0);
        }
    }

    // Repete enquanto houver numeros nao descobertos no tabuleiro
    do
    {
        // Print de checagem
        printf("PLACAR: Player 1 -> %d x %d <- Player 2\n", player1, player2);
        for (i = 0; i < BOARD_SIDE; i++)
        {
            for (j = 0; j < BOARD_SIDE; j++)
            {
                int found = 0;

                // Itera sobre os elementos do jogo
                for (int k = 0; k < numbs_size; k++)
                {
                    // Se o elemento em questao for igual a um numero e este tenha sido descoberto...
                    if (board[i][j] == numbs[k] && found_numbs[k] == 1)
                    {
                        printf("%d ", numbs[k]); // ... o printa
                        found = 1;               // Impede o print do hashtag
                    }
                }
                // Caso não tenha sido descoberto, printa um hashtag
                if (found == 0)
                {
                    printf("# ");
                }
            }
            printf("\n");
        }
        printf("\n");

        int pos_line1 = 0, pos_line2 = 0, pos_column1 = 0, pos_column2 = 0;

        // Recebe os valores informados pelo usuario
        printf("Jogador %d, insira a posicao do primeiro a ser revelado => ", 1 + rounds % 2);
        scanf("%d%d", &pos_line1, &pos_column1);

        printf("Jogador %d, insira a posicao do segundo a ser revelado => ", 1 + rounds % 2);
        scanf("%d%d", &pos_line2, &pos_column2);

        // Se as posicoes coincidirem o elemento, ainda nao e bastante...
        if (board[pos_line1][pos_column1] == board[pos_line2][pos_column2] && (pos_line1 != pos_line2 || pos_column1 != pos_column2))
        {
            // Itera sobre os elementos
            for (i = 0; i < numbs_size; i++)
            {
                if (board[pos_line1][pos_column1] == numbs[i])
                {
                    // .. deve-se verificar se o numero nao foi achado antes e atribuir a pontuacao
                    if (found_numbs[i] == 0 && rounds % 2 == 0)
                    {
                        found_numbs[i] = 1;
                        player1++;
                    }
                    else if (found_numbs[i] == 0)
                    {
                        found_numbs[i] = 1;
                        player2++;
                    }
                }
            }
        }

        // Print de checagem
        for (i = 0; i < BOARD_SIDE; i++)
        {
            for (j = 0; j < BOARD_SIDE; j++)
            {
                int found = 0;

                // Caso o elemento em questão esteja na posicao informada pelo usuario, o printa
                if (i == pos_line1 && j == pos_column1)
                {
                    printf("%d ", board[i][j]);
                }
                else if (i == pos_line2 && j == pos_column2)
                {
                    printf("%d ", board[i][j]);
                }
                // Se nao, ira printar o resto normalmente
                else
                {
                    // Itera sobre os elementos do jogo
                    for (int k = 0; k < numbs_size; k++)
                    {
                        if (board[i][j] == numbs[k] && found_numbs[k] == 1)
                        {
                            printf("%d ", numbs[k]); // Caso o elemento tenha sido descoberto, o printa
                            found = 1;               // Impede o print do hashtag
                        }
                    }
                    // Caso não tenha sido descoberto, printa um hashtag
                    if (found == 0)
                    {
                        printf("# ");
                    }
                }
            }
            printf("\n");
        }
        printf("\n");

        // Mais um round é contabilizado
        rounds++;

    } while (player1 + player2 < numbs_size);

    // Exibe o resultado do jogo
    if (player1 > player2)
    {
        printf("Jogador 1 venceu de %d a %d apos %d rounds!\n", player1, player2, rounds);
    }
    else if (player1 == player2)
    {
        printf("Empate de %d a %d apos %d rounds\n", player1, player2, rounds);
    }
    else
    {
        printf("Jogador 2 venceu de %d a %d apos %d rounds\n", player2, player1, rounds);
    }

    return 0;
}