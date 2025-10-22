#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Weight: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // Imprime os espaços em branco
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Imprime os blocos "#" da esquerda
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // imprime dois espaos entre as piramedes
        printf("  ");

        // imprime os blocos "#" da direita
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
