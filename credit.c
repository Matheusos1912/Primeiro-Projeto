#include <cs50.h>
#include <stdio.h>

int get_length(long number);
bool check_luhn(long number);
void check_card_type(long number);

int main(void)
{
    // Solicita o número do cartão
    long card_number = get_long("Número: ");

    // Verifica se o número é válido pelo algoritmo de Luhn
    if (!check_luhn(card_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // Identifica e imprime o tipo do cartão
    check_card_type(card_number);
    return 0;
}

// Função para obter o comprimento do número
int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

// Implementação do algoritmo de Luhn
bool check_luhn(long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }

        sum += digit;
        alternate = !alternate;
        number /= 10;
    }

    return (sum % 10) == 0;
}

// Função para verificar e imprimir o tipo do cartão
void check_card_type(long number)
{
    int length = get_length(number);

    // Obtém os primeiros dois dígitos
    while (number >= 100)
    {
        number /= 10;
    }
    int first_two_digits = number;

    // Verifica AMEX (15 dígitos, começa com 34 ou 37)
    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
        return;
    }

    // Verifica MASTERCARD (16 dígitos, começa com 51-55)
    if (length == 16 && first_two_digits >= 51 && first_two_digits <= 55)
    {
        printf("MASTERCARD\n");
        return;
    }

    // Verifica VISA (13 ou 16 dígitos, começa com 4)
    if ((length == 13 || length == 16) && (first_two_digits / 10 == 4))
    {
        printf("VISA\n");
        return;
    }

    printf("INVALID\n");
}
