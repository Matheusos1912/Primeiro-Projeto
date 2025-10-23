#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declaração das variáveis
    int start_size;
    int end_size;
    int years = 0;

    // Obtém o tamanho inicial da população (mínimo 9)
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Obtém o tamanho final da população (deve ser maior que o inicial)
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calcula o número de anos necessários
    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }

    // Imprime o resultado
    printf("Years: %i\n", years);
}
