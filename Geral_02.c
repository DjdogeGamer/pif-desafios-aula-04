#include <stdio.h>

#define BOARD_SIDE 3

int main()
{
    int board[BOARD_SIDE][BOARD_SIDE];
    int i, j, placed = 0, winner = 0, valid = 0;
    int pos_line, pos_column;

    // Preenche inicialmente todos os valores como zero
    for (i = 0; i < BOARD_SIDE; i++)
    {
        for (j = 0; j < BOARD_SIDE; j++)
        {
            board[i][j] = 0;
        }
    }

    do
    {
        // Sendo o == 1 e x == 2

        if (placed % 2 == 0)
        {
            printf("Insira a posicao de o => ");
        }
        else
        {
            printf("Insira a posicao de x => ");
        }

        // Recebe a posicao do proximo elemento ate ela ser valida
        do
        {
            valid = 0;
            scanf("%d%d", &pos_line, &pos_column);

            if (board[pos_line][pos_column] == 0)
            {
                board[pos_line][pos_column] = (placed % 2) + 1;
                valid = 1;
                placed++;
            }
            else
            {
                printf("Informe uma posicao nao ocupada\n");
            }
        } while (valid == 0);

        // Print de checagem
        for (i = 0; i < BOARD_SIDE; i++)
        {
            for (j = 0; j < BOARD_SIDE; j++)
            {
                if (board[i][j] == 1)
                {
                    printf("o ");
                }
                else if (board[i][j] == 2)
                {
                    printf("x ");
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Repete o processo para cada uma das opcoes
        for (int option = 1; option < 3; option++)
        {
            // Processo de verificacao se ha vencedor
            int qt_dp = 0, qt_ds = 0;

            for (i = 0; i < BOARD_SIDE; i++)
            {
                // Verificacao da diagonal principal e secundaria
                if (board[i][i] == option)
                {
                    qt_dp++;
                }
                if (board[i][BOARD_SIDE - 1 - i] == option)
                {
                    qt_ds++;
                }
                if (qt_dp == BOARD_SIDE || qt_ds == BOARD_SIDE)
                {
                    winner = option;
                    break;
                }

                // Verificacao na horizontal e vertical
                int qt_hor = 0, qt_ver = 0;

                for (j = 0; j < BOARD_SIDE; j++)
                {
                    if (board[i][j] == option)
                    {
                        qt_hor++;
                    }
                    if (board[j][i] == option)
                    {
                        qt_ver++;
                    }
                }
                if (qt_hor == BOARD_SIDE || qt_ver == BOARD_SIDE)
                {
                    winner = option;
                    break;
                }
            }
        }
    } while (placed < BOARD_SIDE * BOARD_SIDE && winner == 0);

    // Informa o resultado do jogo
    if (winner != 0)
    {
        printf("O vencedor foi o Jogador %d!\n", winner);
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}