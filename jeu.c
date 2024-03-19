/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/
#include "my_hunter.h"

void jeu(struct my_hunter *my_hunter)
{
    init_jeu(my_hunter);
    init2(my_hunter);
    init_vie1(my_hunter);
    init_pause_jeu(my_hunter);
    sfSprite_setTextureRect(my_hunter->chent_s, my_hunter->chen_ani);
    my_hunter->end = 0;
    my_hunter->val = 5;
    my_hunter->mul = 1;
    my_hunter->score = 0;
    while (sfRenderWindow_isOpen(my_hunter->windows) && my_hunter->end == 0) {
        close_event(my_hunter);
        clock(my_hunter);
        animation(my_hunter);
        SRWS(my_hunter->windows, my_hunter->fond_jeu_s, NULL);
        SRWS(my_hunter->windows, my_hunter->chent_s, NULL);
        SRWS(my_hunter->windows, my_hunter->bouton_pause_jeu, NULL);
        affiche_etoile(my_hunter);
        click_perso(my_hunter);
        sfRenderWindow_display(my_hunter->windows);
    }
}

void clock(struct my_hunter *my_hunter)
{
    float seconds;
    sfTime time;

    time = sfClock_getElapsedTime(my_hunter->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        mouvement(my_hunter);
        sfClock_restart(my_hunter->clock);
    }
    res_lvl(my_hunter);
}

void animation(struct my_hunter *my_hunter)
{
    sfTime time = sfClock_getElapsedTime(my_hunter->anim);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.1f) {
        if (my_hunter->chen_ani.left == 24 * 3) {
            my_hunter->chen_ani.left = 0;
        } else {
            my_hunter->chen_ani.left += 24;
        }
        sfSprite_setTextureRect(my_hunter->chent_s, my_hunter->chen_ani);
        sfClock_restart(my_hunter->anim);
    }
}

void res_lvl(struct my_hunter *my_hunter)
{
    int sc = my_hunter->score;
    int scc = my_hunter->mul * 5;

    if (sc >= scc) {
        my_hunter->val += 5;
        my_hunter->mul++;
    }
}

void mouvement(struct my_hunter *my_hunter)
{
    if (my_hunter->pos_chen.x <= 1920) {
        my_hunter->pos_chen.x += my_hunter->val;
        SSTP(my_hunter->chent_s, my_hunter->pos_chen);
    }
    if (my_hunter->pos_chen.x > 1920) {
        my_hunter->pos_chen.x = -10;
        my_hunter->vie--;
        SSTP(my_hunter->chent_s, my_hunter->pos_chen);
    }
    if (my_hunter->vie < 0) {
        my_hunter->end++;
    }
}
