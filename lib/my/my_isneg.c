/*
** EPITECH PROJECT, 2023
** my_isneg.C
** File description:
** Search if the integer is negative, vull or positive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    }else{
        my_putchar('N');
    }
    return (0);
}
