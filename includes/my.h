/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** .h of lbrary
*/

#ifndef MY_H_
    #define MY_H_

#include <sys/stat.h>
#include "my_struct.h"

void my_putchar(char c);
void my_array_swap(char *a, char *b);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_put_long_nbr(long nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int window(char **array, char **second_array, int nb_rows);
int load_file_array(char const *filepath, struct stat *head_stat);
void check_down(base_t *coordinates, char **array);
void check_up(base_t *coordinates, char **array);
void check_right(base_t *coordinates, char **array);
void check_left(base_t *coordinates, char **array);
void check_player_base(char **array, base_t *coordinates);
void check_player(char **array, base_t *coordinates);

#endif /*MY_H_*/
