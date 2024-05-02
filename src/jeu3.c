/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/
#include "../my_hunter.h"

void click_perso(struct my_hunter *my_hunter)
{
    sfFloatRect oui = SGGB(my_hunter->chent_s);
    sfFloatRect pause = SGGB(my_hunter->bouton_pause_jeu);
    sfVector2i mouse_i = sfMouse_getPositionRenderWindow(my_hunter->windows);
    sfVector2f mouse_f = SRWMP(my_hunter->windows, mouse_i, NULL);

    if (sfFloatRect_contains(&oui, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        my_hunter->pos_chen.x = -100;
        my_hunter->pos_chen.y = rand() % 700;
        my_hunter->score++;
    }
    if (sfFloatRect_contains(&pause, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        event_pause_jeu(my_hunter);
    }
}
