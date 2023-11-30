/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap pointers
*/

#include "my.h"

void my_array_swap(char *a, char *b)
{
    char chang1 = *a;
    char chang2 = *b;

    *a = chang2;
    *b = chang1;
    return;
}
