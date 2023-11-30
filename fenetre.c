/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** boostrap
*/

#include <curses.h>
#include "my.h"
#include <stdlib.h>
#include "my_struct.h"

static int reset_array(char **array, char **second_array)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        for (int j = 0; j != my_strlen(array[i]); j += 1) {
            array[i][j] = second_array[i][j];
        }
    }
    return 0;
}

static int my_move(int a, char **array, char **second_array,
    base_t *coordinates)
{
    if (a == 27) {
        return 0;
    }
    if (a == KEY_UP && coordinates->player_x - 1 >= 0) {
        check_up(coordinates, array);
    }
    if (a == KEY_DOWN && coordinates->player_x + 1 <= 30) {
        check_down(coordinates, array);
    }
    if (a == KEY_RIGHT && coordinates->player_y + 1 <= 30) {
        check_right(coordinates, array);
    }
    if (a == KEY_LEFT && coordinates->player_y - 1 >= 0) {
        check_left(coordinates, array);
    }
    if (a == 32) {
        reset_array(array, second_array);
    }
    return 1;
}

static void print_window(base_t *coordinates, char **array)
{
    clear();
    for (int i = 0; array[i] != NULL; i += 1) {
        printw(array[i]);
    }
    refresh();
    return;
}

static void free_array(char **array, char **second_array, int nb_rows)
{
    for (int j = 0; j < nb_rows; j += 1) {
        free(array[j]);
    }
    free(array);
    for (int j = 0; j < nb_rows; j += 1) {
        free(second_array[j]);
    }
    free(second_array);
    return;
}

int window(char **array, char **second_array, int nb_rows)
{
    base_t coordinates = {.player_base_x = 15, .player_base_y = 15,
    .player_x = 15, .player_y = 15};
    WINDOW *win;
    int nb = 1;
    int a = 0;
    
    initscr();
    keypad(stdscr, TRUE);
    while (nb == 1) {
        print_window(&coordinates, array);
        a = getch();
        nb = my_move(a, array, second_array, &coordinates);
    }
    my_put_nbr(8780);
    free_array(array, second_array, nb_rows);
    my_put_nbr(8780);
    endwin();
    free(win);
    return 0;
}