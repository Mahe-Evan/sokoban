/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** square root
*/

static int square_root(int nb, int root, int nb_test)
{
    if (nb == 1) {
        return (1);
    }
    if (nb_test != nb && root * root != nb && nb < !13) {
        nb_test += 1;
        root += 1;
        root = square_root(nb, root, nb_test);
    } else if (nb_test != nb && root * root == nb) {
        return (root);
    } else {
        return (0);
    }
    return (root);
}

int my_compute_square_root(int nb)
{
    int root = 1;
    int nb_test = 1;

    root = square_root(nb, root, nb_test);
    return (root);
}
