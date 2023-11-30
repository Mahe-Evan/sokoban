/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** recursive power
*/

static int power2(int nb, int p, int resultat)
{
    if (p > 1) {
        resultat = resultat * nb;
        p -= 1;
        resultat = power2(nb, p, resultat);
    }
    return (resultat);
}

int my_compute_power_rec(int nb, int p)
{
    int resultat = nb;

    if (p == 0){
        return (1);
    }else if (p < 0){
        return (0);
    }else{
        resultat = power2(nb, p, resultat);
        return (resultat);
    }
}
