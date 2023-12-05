/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** Struct of coordinates
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_


typedef struct coordinates_base {
    int player_base_x;
    int player_base_y;
    int player_x;
    int player_y;
    char obj;
} base_t;

typedef struct nb_game {
    int storage;
    int box;
    int player;
    int good_storage;
    int lines;
    int cols;
    int block_storage;
    int nb_wall;
} nb_t;

#endif /* !MY_STRUCT_H_ */
