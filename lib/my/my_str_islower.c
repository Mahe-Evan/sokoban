/*
** EPITECH PROJECT, 2023
** my_str_islower.c
** File description:
** lib, rw
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int check = 0;

    if (my_strlen(str) == 0) {
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            check += 1;
        }
    }
    if (check == my_strlen(str)) {
        return 1;
    }
    return 0;
}
