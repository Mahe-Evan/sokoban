/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** lib, rw
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0' ; i += 1) {
        if (str[i] >= 'A' && str[i] <= 'A') {
            str[i] += 32;
        }
    }
    return str;
}
