/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** main function
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <sys/stat.h>

void print_rules(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("      map file representing the warehouse map, containing '#'");
    my_putstr(" for walls,\n");
    my_putstr("          'P' for the player, 'X' for boxes and");
    my_putstr("'O' for storage locations.\n");
    return;
}

int main(int argc, char **argv)
{
    struct stat head_stat;
    char *filepath = NULL;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
            print_rules();
            return 0;
    }
    filepath = argv[1];
    if (stat(filepath, &head_stat) != -1) {
        return load_file_array(filepath, &head_stat);
    }
    return write(2, "84\n", 3);
}
