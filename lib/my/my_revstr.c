/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** reverse str
*/

static char *my_revstr_two(char *str, int nb_len)
{
    char dest[nb_len + 1];
    int count = 0;

    while (str[count] != '\0') {
        dest[count] = str[count];
        count += 1;
    }
    count = 0;
    while (nb_len > 0) {
        str[count] = dest[nb_len - 1];
        nb_len -= 1;
        count += 1;
    }
    str[count] = '\0';
    return (str);
}

char *my_revstr(char *str)
{
    int nb_len = 0;

    while (str[nb_len] != '\0') {
        nb_len += 1;
    }
    my_revstr_two(str, nb_len);
    return (str);
}
