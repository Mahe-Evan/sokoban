/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** prime number
*/

static int prime(int nb, int check, int loop)
{
    if (loop != nb && nb % loop != 0) {
        loop += 1;
        check = prime(nb, check, loop);
    } else if (loop != nb && nb % loop == 0) {
        return (0);
    } else {
        check += 1;
        return (check);
    }
    return (check);
}

int my_is_prime(int nb)
{
    int loop = 3;
    int check = 0;

    if (nb == 1 || nb == 0 || (nb != 2 && nb % 2 == 0)) {
        return (0);
    }else{
        check = prime(nb, check, loop);
        return (check);
    }
}
