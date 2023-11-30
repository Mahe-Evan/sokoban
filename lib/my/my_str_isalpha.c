/*
** EPITECH PROJECT, 2023
** my_str_isalpha.
** File description:
** check if the char is alpha.
*/

#include "my.h"

int my_str_isalpha(char str)
{
    if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')) {
            return 1;
        }
    return 0;
}
