/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** prime
*/

static int prime_two(int nb, int check, int loop)
{
    if (loop != nb && nb % loop != 0) {
        loop += 1;
    } else if (loop != nb && nb % loop == 0) {
        return (0);
    } else {
        check += 1;
        return (check);
    }
    return (check);
}

int my_find_prime_sup(int nb)
{
    int loop = 3;
    int check = 0;

    if (nb == 1 || nb == 0 || (nb != 2 && nb % 2 == 0)) {
        return (0);
    }else if (nb == 2) {
        return (1);
    }else{
        check = prime_two(nb, check, loop);
        return (check);
    }
}
