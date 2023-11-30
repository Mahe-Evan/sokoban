/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** go len
*/

int my_strlen(char const *str)
{
    int nb;

    nb = 0;
    while (str[nb] != '\0') {
        nb += 1;
    }
    return (nb);
}
