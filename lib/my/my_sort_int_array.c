/*
** EPITECH PROJECT, 2023
** my_sort_int_array.c
** File description:
** rework too
*/

#include "my.h"

void swap_array(int *small, int *big)
{
    int swap = *small;

    *small = *big;
    *big = swap;
}

void my_sort_int_array(int *array, int size)
{
    int check = 0;

    if (size == 0) {
        return;
    }
    for (int i = 0; i < size - 1; i += 1) {
        if (array[i] < array[i + 1]) {
            swap_array(&array[i], &array[i + 1]);
            check += 1;
        }
        if (check == 0) {
            return;
        }
        my_sort_int_array(array, size - 1);
    }
}
