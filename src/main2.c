/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/
#include "../my_hunter.h"

void close_event(struct my_hunter *my_hunter)
{
    while (sfRenderWindow_pollEvent(my_hunter->windows, &my_hunter->event)){
        if (my_hunter->event.type == sfEvtClosed) {
            sfRenderWindow_close(my_hunter->windows);
        }
    }
}

void click(struct my_hunter *my_hunter)
{
    sfFloatRect start_float = SGGB(my_hunter->bouton_start);
    sfFloatRect quit_float = SGGB(my_hunter->bouton_exit);
    sfFloatRect otpion_float = SGGB(my_hunter->bouton_option);
    sfVector2i mouse_i = sfMouse_getPositionRenderWindow(my_hunter->windows);
    sfVector2f mouse_f = SRWMP(my_hunter->windows, mouse_i, NULL);

    if (sfFloatRect_contains(&start_float, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        jeu(my_hunter);
    }
    if (sfFloatRect_contains(&quit_float, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        sfRenderWindow_close(my_hunter->windows);
    }
    if (sfFloatRect_contains(&otpion_float, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        option(my_hunter);
    }
}