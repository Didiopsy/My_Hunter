/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/
#include "../my_hunter.h"

void init_pause_jeu(struct my_hunter *my_hunter)
{
    sfVector2f scale_pause_jeu = {3, 3};
    sfVector2f pos_pause_jeu = {1600, 925};

    my_hunter->pause_jeu = STCF("./image/pause_jeu.png", NULL);
    my_hunter->bouton_pause_jeu = sfSprite_create();
    my_hunter->scale_pause_jeu = scale_pause_jeu;
    my_hunter->pos_pause_jeu = pos_pause_jeu;
    SST(my_hunter->bouton_pause_jeu, my_hunter->pause_jeu, sfTrue);
    sfSprite_setScale(my_hunter->bouton_pause_jeu, my_hunter->scale_pause_jeu);
    SSTP(my_hunter->bouton_pause_jeu, my_hunter->pos_pause_jeu);
}

void init_pause_pause(struct my_hunter *my_hunter)
{
    sfVector2f scale_pause_pause = {5, 5};
    sfVector2f pos_pause_pause = {550, 400};

    my_hunter->pause_pause = STCF("./image/pause_pause.png", NULL);
    my_hunter->bouton_pause_pause = sfSprite_create();
    my_hunter->scale_pause_pause = scale_pause_pause;
    my_hunter->pos_pause_pause = pos_pause_pause;
    SST(my_hunter->bouton_pause_pause, my_hunter->pause_pause, sfTrue);
    SSSC(my_hunter->bouton_pause_pause, my_hunter->scale_pause_pause);
    SSTP(my_hunter->bouton_pause_pause, my_hunter->pos_pause_pause);
}

void pause_pause(struct my_hunter *my_hunter)
{
    sfFloatRect pause = SGGB(my_hunter->bouton_pause_pause);
    sfVector2i mouse_i = sfMouse_getPositionRenderWindow(my_hunter->windows);
    sfVector2f mouse_f = SRWMP(my_hunter->windows, mouse_i, NULL);

    if (sfFloatRect_contains(&pause, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        my_hunter->pause_count++;
    }
}

void event_pause_jeu(struct my_hunter *my_hunter)
{
    my_hunter->pause_count = 0;
    init_pause_pause(my_hunter);
    while (sfRenderWindow_isOpen(my_hunter->windows) &&
    my_hunter->pause_count == 0) {
        close_event(my_hunter);
        SRWS(my_hunter->windows, my_hunter->bouton_pause_pause, NULL);
        pause_pause(my_hunter);
    }
}

void affiche_etoile(struct my_hunter *my_hunter)
{
    if (my_hunter->vie >= 1) {
        SRWS(my_hunter->windows, my_hunter->bouton_etoile1, NULL);
    }
    if (my_hunter->vie >= 2) {
        SRWS(my_hunter->windows, my_hunter->bouton_etoile2, NULL);
    }
    if (my_hunter->vie == 3) {
        SRWS(my_hunter->windows, my_hunter->bouton_etoile3, NULL);
    }
}
