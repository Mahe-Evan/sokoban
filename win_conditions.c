/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Check_win and lose conditions
*/

#include "my.h"
#include "my_struct.h"
#include <stddef.h>
#include <ncurses.h>
#include <unistd.h>

static void check_o(char **array, char **second_array, int i, int j)
{
    if (second_array[i][j] == 'O' && array[i][j] == ' ') {
        array[i][j] = 'O';
    }
    return;
}

static void checking_pose(char **array, int i, char **second_array,
    nb_t *number)
{
    for (int j = 0; j < my_strlen(array[i]); j += 1) {
        if (second_array[i][j] == 'O' && array[i][j] == 'X') {
            number->good_storage += 1;
        }
    }
    return;
}

static int print_end(char **array, nb_t *number)
{
    clear();
    for (int i = 0; array[i] != NULL; i += 1) {
        printw(array[i]);
    }
    refresh();
    usleep(100000);
    return 0;
}

static void check_nb_wall(char **array, nb_t *number, int i, int j)
{
    if (number->nb_wall < 2 ||
        ((array[i - 1][j] == ' ' || array[i - 1][j] == 'P') &&
        (array[i + 1][j] == ' ' || array[i + 1][j] == 'P')) ||
        ((array[i][j - 1] == ' ' || array[i][j - 1] == 'P') &&
        (array[i][j + 1] == ' ' || array[i][j + 1] == 'P'))) {
        return;
    } else {
        number->block_storage += 1;
    }
    return;
}

static void check_bloqued_box(char **array, nb_t *number, int i, int j)
{
    if (array[i][j] == 'X') {
        if (array[i - 1][j] == '#' || array[i - 1][j] == 'X') {
            number->nb_wall += 1;
        }
        if (array[i][j - 1] == '#' || array[i][j - 1] == 'X') {
            number->nb_wall += 1;
        }
        if (array[i + 1][j] == '#' || array[i + 1][j] == 'X') {
            number->nb_wall += 1;
        }
        if (array[i][j + 1] == '#' || array[i][j + 1] == 'X') {
            number->nb_wall += 1;
        }
    check_nb_wall(array, number, i, j);
    }
    return;
}

static int check_lose(nb_t *number, char **array)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        for (int j = 0; j < my_strlen(array[i]); j += 1) {
            check_bloqued_box(array, number, i, j);
            number->nb_wall = 0;
        }
    }
    if (number->block_storage == number->storage) {
        print_end(array, number);
        return 1;
    }
    number->block_storage = 0;
    return 2;
}

int check_win(int nb, nb_t *number, char **array, char **second_array)
{
    for (int i = 0; second_array[i] != NULL; i += 1) {
        for (int j = 0; j < my_strlen(second_array[i]); j += 1) {
            check_o(array, second_array, i, j);
        }
    }
    for (int i = 0; array[i] != NULL; i += 1) {
            checking_pose(array, i, second_array, number);
    }
    if (number->good_storage == number->storage) {
        return print_end(array, number);
    }
    number->good_storage = 0;
    return check_lose(number, array);
}
