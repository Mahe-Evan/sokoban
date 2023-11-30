/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** hey
*/

#include "my.h"

static void modulo2(int reverse, int nb_base, int nb_recu)
{
    int affiche = 0;

    reverse = reverse + nb_recu;
    while (reverse >= 10) {
        affiche = reverse % 10;
        reverse = reverse / 10;
        my_putchar(affiche + 48);
    }
    my_putchar(reverse + 48);
    if (nb_base % 10 == 0) {
        my_putchar('0');
    }
    return;
}

static void modulo(int nb, int nb_base)
{
    int reverse = 0;
    int compteur = 0;
    int divise = 0;
    int nb_recu = nb;

    while (nb_recu >= 10) {
        divise = nb;
        for (divise = nb; divise > 9; divise = divise / 10) {
            compteur += 1;
            nb_recu = nb_recu % 10;
        }
        for (; compteur > 0; compteur -= 1) {
            nb_recu = nb_recu * 10;
        }
        reverse = reverse + nb_recu;
        nb = nb / 10;
        nb_recu = nb;
    }
    modulo2(reverse, nb_base, nb_recu);
    return;
}

void my_put_nbr(int nb)
{
    int nb_base = nb;

    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    modulo(nb, nb_base);
    return;
}
