#include <stdio.h>
#define SIZE 100

int main()
{
    int codes[SIZE], qt[SIZE], code, index = 0;
    float price[SIZE], sum = 0;
    int code_exists = 0;

    int option = 0;

    do
    {
        printf("MENU\n1 - Cadastrar mercadoria\n2 - Consultar mercadoria\n3 - Valor total em mercadorias\n4 - Sair\n=> ");
        scanf("%d", &option);

        switch (option)
        {
        // 1- Cadastrar mercadoria
        case 1:
            code_exists = 0;

            printf("Codigo: ");
            scanf("%d", &code);

            // Verifica se o codigo ja esta cadastrado
            for (int i = 0; i < index; i++)
            {
                if (code == codes[i])
                {
                    printf("Quantidade nova: ");
                    scanf("%d", &qt[i]);
                    printf("Valor unitario (caso deseje mudar): ");
                    scanf("%f", &price[i]);
                    i = index;       // para terminar o loop
                    code_exists = 1; // para nao rodar o proximo trecho
                }
            }

            // Se nao estiver cadastrado
            if (code_exists == 0)
            {
                codes[index] = code;
                printf("Quantidade: ");
                scanf("%d", &qt[index]);
                printf("Valor unitario: ");
                scanf("%f", &price[index]);
                index++; // O index armazena o real tamanho ocupado pelos vetores
            }
            break;

        // 2 - Consultar mercadoria
        case 2:
            // Verifica se o codigo ja esta cadastrado
            code_exists = 0;

            printf("Codigo: ");
            scanf("%d", &code);

            for (int i = 0; i < index; i++)
            {
                if (code == codes[i])
                {
                    printf("Quantidade: %d\n", qt[i]);
                    printf("Valor unitario: %f\n\n", price[i]);
                    code_exists = 1;
                    i = index; // para encerrar o loop
                }
            }

            if (code_exists == 0)
            {
                printf("O codigo nao foi achado\n");
            }
            break;

        // 3 - Valor total em mercadorias
        case 3:
            for (int i = 0; i < index; i++)
            {
                sum += (float)qt[i] * price[i];
            }
            printf("O valor total da mercadoria e de R$%.2f\n", sum);
            sum = 0; // Reseta o valor da mercadoria
            break;

        // 4 - Sair
        case 4:
            printf("Encerrando...\n");
            break;

        // Caso de códigos aleatórios
        default:
            printf("Nao reconheci este comando\n\n");
        }
    } while (option != 4);

    return 0;
}