/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** check the position of the player a start and during the game
*/

#include "my_struct.h"
#include <stddef.h>
#include "my.h"

static void check_P_base(char **array, base_t *coordinates, int i, int j)
{
    if (array[i][j] == 'P') {
        coordinates->player_base_x = i;
        coordinates->player_x = i;
        coordinates->player_base_y = j;
        coordinates->player_y = j;
    }
    return;
}

void check_player_base(char **array, base_t *coordinates)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        for (int j = 0; j < my_strlen(array[i]); j += 1) {
            check_P_base(array, coordinates, i, j);
        }
    }
    return;
}