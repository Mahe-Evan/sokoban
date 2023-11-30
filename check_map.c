/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** checking and loading file
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

static int second_array(char **array, int nb_rows, int nb_cols)
{
    char **second_array = malloc(sizeof(char *) * (nb_rows + 1));
    char *nb;

    second_array[nb_rows] = NULL;
    for (int i = 0; i < nb_rows; i += 1) {
        second_array[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    for (int i = 0; i < nb_rows; i += 1) {
        for (int j = 0; j <= nb_cols; j += 1) {
            second_array[i][j] = array[i][j];
        }
    }
    return window(array, second_array, nb_rows);
}

static int check_car(char **array, int i, int j)
{
    if (array[i][j] != '#' && array[i][j] != 'O' && array[i][j] != 'P'
        && array[i][j] != '\n' && array[i][j] != ' ' && array[i][j] != 'X') {
        my_putchar(array[i][j]);
        my_put_nbr(i);
        my_put_nbr(j);
        write(2, "84\n", 3);
        return 84;
    }
    return 0;
}

static int check_array(char **array, int nb_rows, int nb_cols)
{
    int error = 0;
    int i = 0;

    for (int i = 0; i < nb_rows; i += 1) {
        for (int j = 0; j < nb_cols ; j += 1) {
            //error += check_car(array, i, j);
        }
    }
    if (error != 0) {
        write(2, "84\n", 3);
        return 84;
    }
    return second_array(array, nb_rows, nb_cols);
}

static int set_array(int nb_rows, int nb_cols, char *buffer)
{
    char **array = malloc(sizeof(char *) * (nb_rows + 1));
    char *nb;
    int placement = 0;

    array[nb_rows] = NULL;
    for (int i = 0; i < nb_rows; i += 1) {
        array[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    for (int i = 0; i < nb_rows; i += 1) {
        for (int j = 0; j < nb_cols; j += 1) {
            array[i][j] = buffer[placement];
            placement += 1;
        }
    }
    free(buffer);
    return check_array(array, nb_rows, nb_cols);
}

int load_array(char *buffer)
{
    int nb_rows = 0;
    int nb_cols = 0;
    int nb_cols_max = 0;
    int loop = 0;

    for (int i = 0; buffer[i * nb_rows] != '\0'; i += 1) {
        while (buffer[loop] == '#' || buffer[loop] == 'O' || 
            buffer[loop] == 'P'|| buffer[loop] == ' ' || buffer[loop] == 'X') {
            nb_cols += 1;
            loop += 1;
        }
        if (nb_cols > nb_cols_max) {
            nb_cols_max = nb_cols;
        }
        loop += 1;
        nb_rows += 1;
        nb_cols = 0;
    }
    return set_array(nb_rows, nb_cols_max, buffer);
}

int load_file_array(char const *filepath, struct stat *head_stat)
{
    char *buffer = malloc(head_stat->st_size + 1);
    int nb_rows = 0;
    int nb_cols = 0;

    if (read(open(filepath, O_RDONLY), buffer, head_stat->st_size) != -1) {
        return load_array(buffer);
    }
    free(buffer);
    return 84;
}