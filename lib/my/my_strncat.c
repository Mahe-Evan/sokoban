/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** concatenates n elements in str
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int count_dest = my_strlen(dest);
    int count = 0;

    while (count < nb) {
        dest[count_dest] = src[count];
        count_dest += 1;
        count += 1;
    }
    dest[count_dest] = '\0';
    return (dest);
}
