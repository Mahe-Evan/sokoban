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


static int reset_array(char **second_array, int nb_rows)
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
    return 0;
}

static void free_first_array(char **array, char **second_array)
{
    int nb_rows = 0;

    for (int j = 0; second_array[j] != NULL; j += 1) {
        free(array[j]);
        nb_rows += 1;
    }
    free(array);
    reset_array(second_array, nb_rows);
    return;
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
        free_first_array(array, second_array);
    }
    return 1;

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
    return 1;
}

static void print_window(base_t *coordinates, char **array)
{
    clear();
    for (int i = 0; array[i] != NULL; i += 1) {
        printw(array[i]);
    }
    printw("%d\n", coordinates->player_x);
    printw("%d\n", coordinates->player_y);
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
    base_t coordinates;
    WINDOW *win;
    int nb = 1;
    int a = 0;
    
    check_player_base(array, &coordinates);
    initscr();
    set_escdelay(0);
    keypad(stdscr, TRUE);
    while (nb == 1) {
        print_window(&coordinates, array);
        a = getch();
        nb = reset_and_close(a, array, second_array, &coordinates);
        my_move(a, array, second_array, &coordinates);
    }
    free_array(array, second_array, nb_rows);
    endwin();
    free(win);
    return 0;
}