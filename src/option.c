/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/
#include "../my_hunter.h"

void init_option(struct my_hunter *my_hunter)
{
    my_hunter->fond_option_t = STCF("./image/fond_option.png", NULL);
    my_hunter->fond_option_s = sfSprite_create();
    sfSprite_setScale(my_hunter->fond_option_s, my_hunter->scale_fond);
    SST(my_hunter->fond_option_s, my_hunter->fond_option_t, sfTrue);
}

void init_music(struct my_hunter *my_hunter)
{
    sfVector2f scale_music = {3, 3};
    sfVector2f pos_music = {1, 10};

    my_hunter->music = STCF("./image/music.png", NULL);
    my_hunter->bouton_music = sfSprite_create();
    my_hunter->scale_music = scale_music;
    my_hunter->pos_music = pos_music;
    SST(my_hunter->bouton_music, my_hunter->music, sfTrue);
    sfSprite_setScale(my_hunter->bouton_music, my_hunter->scale_music);
    sfSprite_setPosition(my_hunter->bouton_music, my_hunter->pos_music);
}

void init_pause(struct my_hunter *my_hunter)
{
    sfVector2f scale_pause = {3, 3};
    sfVector2f pos_pause = {1, 725};

    my_hunter->pause = STCF("./image/pause.png", NULL);
    my_hunter->bouton_pause = sfSprite_create();
    my_hunter->scale_pause = scale_pause;
    my_hunter->pos_pause = pos_pause;
    SST(my_hunter->bouton_pause, my_hunter->pause, sfTrue);
    sfSprite_setScale(my_hunter->bouton_pause, my_hunter->scale_pause);
    sfSprite_setPosition(my_hunter->bouton_pause, my_hunter->pos_pause);
}

void click_option(struct my_hunter *my_hunter)
{
    sfFloatRect pause_float = SGGB(my_hunter->bouton_pause);
    sfVector2i mouse_i = sfMouse_getPositionRenderWindow(my_hunter->windows);
    sfVector2f mouse_f = SRWMP(my_hunter->windows, mouse_i, NULL);

    if (sfFloatRect_contains(&pause_float, mouse_f.x, mouse_f.y) == sfTrue &&
    my_hunter->event.type == sfEvtMouseButtonPressed) {
        my_hunter->end = 1;
    }
}

void option(struct my_hunter *my_hunter)
{
    init_option(my_hunter);
    init_music(my_hunter);
    init_pause(my_hunter);
    my_hunter->end = 0;
    while (sfRenderWindow_isOpen(my_hunter->windows) && my_hunter->end == 0) {
        close_event(my_hunter);
        click_option(my_hunter);
        SRWS(my_hunter->windows, my_hunter->fond_option_s, NULL);
        SRWS(my_hunter->windows, my_hunter->bouton_music, NULL);
        SRWS(my_hunter->windows, my_hunter->bouton_pause, NULL);
        sfRenderWindow_display(my_hunter->windows);
    }
}