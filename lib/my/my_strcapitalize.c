/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** lib, rw
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0' ; i += 1) {
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
            i += 1;
        }
        if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ') {
            str[i] -= 32;
        }
    }
    return str;
}
