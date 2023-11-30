/*
** EPITECH PROJECT, 2023
** my_strcmp.
** File description:
** lib, rework
*/

#include "my.h"

static int check(int totals1, int totals2, int nb)
{
    if (totals1 > totals2) {
        nb = 1;
        return nb;
    }
    if (totals2 > totals1) {
        nb = -1;
        return nb;
    }
    return nb;
}

int my_strcmp(char const *s1, char const *s2)
{
    int totals1 = 0;
    int totals2 = 0;
    int i = 0;
    int j = 0;
    int nb = 0;

    while (s1[i] != '\0' && s1[i] != '"') {
        totals1 += s1[i];
        i += 1;
        
    }
    while (s2[j] != '\0' && s2[j] != '"') {
        totals2 += s2[j];
        j += 1;
    }
    nb = check(totals1, totals2, nb);
    return nb;
}
