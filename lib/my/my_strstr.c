/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** library, rework
*/

#include "my.h"
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int n = my_strlen(to_find);

    if (n > my_strlen(str)) {
        return NULL;
    }
    for (int i; str[i] != '\0'; i += 1) {
        if (my_strncmp(str, to_find, n) == 0) {
            return (str);
        } else {
            str += 1;
        }
    }
    return NULL;
}
