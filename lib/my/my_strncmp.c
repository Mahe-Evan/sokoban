/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** lib, rework
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int totals1 = 0;
    int totals2 = 0;

    if (my_strlen(s1) > my_strlen(s2)) {
        return 1;
    }
    if (my_strlen(s2) > my_strlen(s1)) {
        return -1;
    }
    for (int i = 0; i < n; i += 1) {
        totals1 += s1[i];
        totals2 += s2[i];
    }
    if (totals1 > totals2) {
        return 1;
    }
    if (totals2 > totals1) {
        return -1;
    }
    return 0;
}
