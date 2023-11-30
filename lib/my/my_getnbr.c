/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** for library (need rework bcs not done)
*/

#include "my.h"

void nb_negative(char const *str)
{
    int negative = 0;

    for (int i = 0; i < my_strlen(str); i += 1) {
        if (str[i] == '-') {
            negative += 1;
        }
    }
    if (negative % 2 == 1) {
        my_putchar('-');
    }
    return;
}

int my_getnbr(char const *str)
{
    int nbr = 0;

    if (my_strlen(str) == 0) {
        return 0;
    }
    nb_negative(str);
    for (int i = 0; i < my_strlen(str); i += 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr *= 10;
            nbr = str[i] + 48;
        }
    }
    if (nbr >= 2147483647 || nbr <= -2147483648) {
        return 0;
    }
    return nbr;
}
