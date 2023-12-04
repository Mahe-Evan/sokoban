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
    array[coordinates->player_x][coordinates->player_base_y + 1];

    if (array[coordinates->player_x][coordinates->player_y + 1] != '#') {
        array[coordinates->player_x][coordinates->player_y + 1] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] =
        char_switch;
        coordinates->player_y += 1;
    }
    return;
}

void check_left(base_t *coordinates, char **array)
{
    char char_switch = 
    array[coordinates->player_x][coordinates->player_base_y - 1];

    if (array[coordinates->player_x][coordinates->player_y - 1] != '#') {
        array[coordinates->player_x][coordinates->player_y - 1] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] =
        char_switch;
        coordinates->player_y -= 1;
    }
    return;
}

void check_down(base_t *coordinates, char **array)
{
    char char_switch = 
    array[coordinates->player_x + 1][coordinates->player_base_y];

    if (array[coordinates->player_x + 1][coordinates->player_y] != '#') {
        array[coordinates->player_x + 1][coordinates->player_y] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] =
        char_switch;
        coordinates->player_x += 1;
    }
    return;
}

void check_up(base_t *coordinates, char **array)
{
    char char_switch = 
    array[coordinates->player_x - 1][coordinates->player_base_y];

    if (array[coordinates->player_x - 1][coordinates->player_y] != '#') {
        array[coordinates->player_x - 1][coordinates->player_y] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] =
        char_switch;
        coordinates->player_x -= 1;
    }
    return;
}