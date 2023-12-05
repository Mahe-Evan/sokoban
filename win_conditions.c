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
        clear();
        for (int i = 0; array[i] != NULL; i += 1) {
            printw(array[i]);
        }
        refresh();
        usleep(100000);
        return 0;
    } else {
        number->good_storage = 0;
        return 2;
    }
}
