/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** checking_moves
*/

#include "my.h"
#include "my_struct.h"

static void check_o_rigth(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x][coordinates->player_y + 1] == ' ') {
        array[coordinates->player_x][coordinates->player_y + 1] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = ' ';
        coordinates->player_y += 1;
    } else if
        (array[coordinates->player_x][coordinates->player_y + 1] == 'O') {
        array[coordinates->player_x][coordinates->player_y + 1] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = 'O';
        coordinates->player_y += 1;
    }
    return;
}

void check_right(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x][coordinates->player_y + 1] == 'X') {
        if (array[coordinates->player_x][coordinates->player_y + 2] == ' ' ||
            array[coordinates->player_x][coordinates->player_y + 2] == 'O') {
            array[coordinates->player_x][coordinates->player_y + 2] = 'X';
            array[coordinates->player_x][coordinates->player_y + 1] =
            array[coordinates->player_x][coordinates->player_y];
            array[coordinates->player_x][coordinates->player_y] =
            coordinates->obj;
            coordinates->obj = ' ';
            coordinates->player_y += 1;
        }
    }
    check_o_rigth(coordinates, array);
    return;
}

static void check_o_left(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x][coordinates->player_y - 1] == ' ') {
        array[coordinates->player_x][coordinates->player_y - 1] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = ' ';
        coordinates->player_y -= 1;
    } else if
        (array[coordinates->player_x][coordinates->player_y - 1] == 'O') {
        array[coordinates->player_x][coordinates->player_y - 1] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = 'O';
        coordinates->player_y -= 1;
    }
    return;
}

void check_left(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x][coordinates->player_y - 1] == 'X') {
        if (array[coordinates->player_x][coordinates->player_y - 2] == ' ' ||
            array[coordinates->player_x][coordinates->player_y - 2] == 'O') {
            array[coordinates->player_x][coordinates->player_y - 2] = 'X';
            array[coordinates->player_x][coordinates->player_y - 1] =
            array[coordinates->player_x][coordinates->player_y];
            array[coordinates->player_x][coordinates->player_y] =
            coordinates->obj;
            coordinates->obj = ' ';
            coordinates->player_y -= 1;
        }
    }
    check_o_left(coordinates, array);
    return;
}

static void check_o_down(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x + 1][coordinates->player_y] == ' ') {
        array[coordinates->player_x + 1][coordinates->player_y] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = ' ';
        coordinates->player_x += 1;
    } else if
        (array[coordinates->player_x + 1][coordinates->player_y] == 'O') {
        array[coordinates->player_x + 1][coordinates->player_y] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = 'O';
        coordinates->player_x += 1;
        return;
    }
}

void check_down(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x + 1][coordinates->player_y] == 'X') {
        if (array[coordinates->player_x + 2][coordinates->player_y] == ' ' ||
            array[coordinates->player_x + 2][coordinates->player_y] == 'O') {
            array[coordinates->player_x + 2][coordinates->player_y] = 'X';
            array[coordinates->player_x + 1][coordinates->player_y] =
            array[coordinates->player_x][coordinates->player_y];
            array[coordinates->player_x][coordinates->player_y] =
            coordinates->obj;
            coordinates->obj = ' ';
            coordinates->player_x += 1;
        }
    }
    check_o_down(coordinates, array);
    return;
}

static void check_o_up(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x - 1][coordinates->player_y] == ' ') {
        array[coordinates->player_x - 1][coordinates->player_y] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = ' ';
        coordinates->player_x -= 1;
    } else if
        (array[coordinates->player_x - 1][coordinates->player_y] == 'O') {
        array[coordinates->player_x - 1][coordinates->player_y] =
        array[coordinates->player_x][coordinates->player_y];
        array[coordinates->player_x][coordinates->player_y] = coordinates->obj;
        coordinates->obj = 'O';
        coordinates->player_x -= 1;
    }
    return;
}

void check_up(base_t *coordinates, char **array)
{
    if (array[coordinates->player_x - 1][coordinates->player_y] == 'X') {
        if (array[coordinates->player_x - 2][coordinates->player_y] == ' ' ||
            array[coordinates->player_x - 2][coordinates->player_y] == 'O') {
            array[coordinates->player_x - 2][coordinates->player_y] = 'X';
            array[coordinates->player_x - 1][coordinates->player_y] =
            array[coordinates->player_x][coordinates->player_y];
            array[coordinates->player_x][coordinates->player_y] =
            coordinates->obj;
            coordinates->obj = ' ';
            coordinates->player_x -= 1;
        }
    }
    check_o_up(coordinates, array);
    return;
}
