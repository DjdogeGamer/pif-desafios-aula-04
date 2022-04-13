#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Pericles, estou enviando o codigo que foi desenvolvido em classe
int main()
{

  srand(time(NULL));
  int mat_jog1[SIZE][SIZE], mat_jog2[SIZE][SIZE];
  int barcos_jog1 = 10, barcos_jog2 = 10;

  for (int l = 0; l < SIZE; l++)
  {
    for (int c = 0; c < SIZE; c++)
    {
      mat_jog1[l][c] = 0;
      mat_jog2[l][c] = 0;
    }
  }

  for (int barco = 1; barco <= barcos_jog1;)
  {
    int b_l = rand() % SIZE;
    int b_c = rand() % SIZE;

    if (mat_jog1[b_l][b_c] == 0)
    {
      mat_jog1[b_l][b_c] = 1;
      barco++;
    }
  }

  for (int barco = 1; barco <= barcos_jog2;)
  {
    int b_l = rand() % SIZE;
    int b_c = rand() % SIZE;

    if (mat_jog2[b_l][b_c] == 0)
    {
      mat_jog2[b_l][b_c] = 2;
      barco++;
    }
  }

  int jog_atual = 1;
  do
  {

    for (int l = 0; l < SIZE; l++)
    {
      for (int c = 0; c < SIZE; c++)
      {
        printf("%i ", mat_jog1[l][c]);
      }
      printf("\n");
    }

    printf("\n\n");

    for (int l = 0; l < SIZE; l++)
    {
      for (int c = 0; c < SIZE; c++)
      {
        printf("%i ", mat_jog2[l][c]);
      }
      printf("\n");
    }

    int linha, coluna;

    printf("Jogador %i, digite a coordenada desejada: ", jog_atual);
    scanf("%i %i", &linha, &coluna);
    getchar();

    if (jog_atual == 1)
    {
      if (mat_jog2[linha][coluna] == 2)
      {
        mat_jog2[linha][coluna] = 0;
        barcos_jog2--;

        printf("\nVoce acertou!\n");
      }
      jog_atual = 2;
    }
    else if (jog_atual == 2)
    {
      if (mat_jog1[linha][coluna] == 1)
      {
        mat_jog1[linha][coluna] = 0;
        barcos_jog1--;

        printf("\nVoce acertou!\n");
      }
      jog_atual = 1;
    }

    printf("\n\n");
  } while (1);

  return 0;
}