/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** liv, rx
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0' ; i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}
