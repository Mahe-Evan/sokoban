/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** hey
*/

#include "my.h"

void my_putstr(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb += 1;
    }
    return;
}
