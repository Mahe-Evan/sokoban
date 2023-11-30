/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** lib, rw
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int count_dest = my_strlen(dest);
    int count = 0;

    while (src[count] != '\0') {
        dest[count_dest] = src[count];
        count_dest += 1;
        count += 1;
    }
    dest[count_dest] = '\0';
    return (dest);
}
