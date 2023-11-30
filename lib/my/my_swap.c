/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap pointers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int chang1 = *a;
    int chang2 = *b;

    *a = chang2;
    *b = chang1;
    return;
}
