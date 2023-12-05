/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** boostrap
*/

#include <ncurses.h>
#include "my.h"
#include <stdlib.h>
#include "my_struct.h"
#include <stddef.h>


static void reset_array(char **second_array, int nb_rows)
{
    char **array = malloc(sizeof(char *) * (nb_rows + 1));
    char *nb;

    clear();
    array[nb_rows] = NULL;
    for (int i = 0; second_array[i] != NULL; i += 1) {
        array[i] = malloc(sizeof(char) * (my_strlen(second_array[i]) + 1));
    }
    for (int i = 0; second_array[i] != NULL; i += 1) {
        for (int j = 0; j < my_strlen(second_array[i]); j += 1) {
            array[i][j] = second_array[i][j];
        }
    }
    refresh();
    return;
}

static void free_array(char **array, char **second_array)
{
    for (int j = 0; array[j] != NULL; j += 1) {
        free(array[j]);
    }
    free(array);
    for (int j = 0; second_array[j] != NULL; j += 1) {
        free(second_array[j]);
    }
    free(second_array);
    return;
}

static int my_move(int a, char **array, char **second_array,
    base_t *coordinates)
{
    if (a == KEY_UP) {
        check_up(coordinates, array);
    }
    if (a == KEY_DOWN) {
        check_down(coordinates, array);
    }
    if (a == KEY_RIGHT) {
        check_right(coordinates, array);
    }
    if (a == KEY_LEFT) {
        check_left(coordinates, array);
    }
    return 2;
}

static int reset_and_close(int a, char **array, char **second_array,
    base_t *coordinates)
{
    if (a == 27) {
        return 0;
    }
    if (a == 32) {
        coordinates->player_x = coordinates->player_base_x;
        coordinates->player_y = coordinates->player_base_y;
    }
    my_move(a, array, second_array, coordinates);
    return 2;
}

static void print_window(base_t *coordinates, char **array, nb_t *number,
    int nb)
{
    clear();
    for (int i = 0; array[i] != NULL; i += 1) {
        printw(array[i]);
    }
    refresh();
    return;
}

int window(char **array, char **second_array, int nb_rows, nb_t *number)
{
    base_t coordinates = {.obj = ' '};
    int nb = 2;
    int a = 0;

    check_player_base(array, &coordinates);
    initscr();
    set_escdelay(0);
    keypad(stdscr, TRUE);
    while (nb == 2) {
        print_window(&coordinates, array, number, nb);
        a = getch();
        nb = reset_and_close(a, array, second_array, &coordinates);
        if (nb == 2)
            nb = check_win(nb, number, array, second_array);
    }
    free_array(array, second_array);
    endwin();
    return nb;
}
