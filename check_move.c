/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** checking_moves
*/

#include "my.h"
#include "my_struct.h"

void check_right(base_t *coordinates, char **array)
{
    char char_switch = 
    array[coordinates->player_x][coordinates->player_base_y];

    if (array[coordinates->player_x][coordinates->player_base_y + 1] != '#') {
        array[coordinates->player_x][coordinates->player_base_y] =
        array[coordinates->player_x][coordinates->player_base_y + 1];
        array[coordinates->player_x][coordinates->player_base_y + 1] =
        char_switch;
    }
    return;
}

void check_left(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x][coordinates->player_base_y - 1] != '#') {
        my_array_swap(
        &array[coordinates->player_x][coordinates->player_base_y],
        &array[coordinates->player_x][coordinates->player_base_y - 1]);
    }
    return;
}

void check_up(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x - 1][coordinates->player_base_y] != '#') {
        my_array_swap(
        &array[coordinates->player_x][coordinates->player_base_y],
        &array[coordinates->player_x - 1][coordinates->player_base_y]);
    }
    return;
}

void check_down(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x + 1][coordinates->player_base_y] != '#') {
        my_array_swap(
        &array[coordinates->player_x][coordinates->player_base_y],
        &array[coordinates->player_x + 1][coordinates->player_base_y]);
    }
    return;
}
