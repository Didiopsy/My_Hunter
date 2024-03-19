/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/

#include "my_hunter.h"

int main(void)
{
    struct my_hunter my_hunter;
    sfVideoMode mode = {1920, 1080, 32};

    my_hunter.mode = mode;
    fenetre(&my_hunter);
}

void init_menu(struct my_hunter *my_hunter)
{
    sfVector2f scale_fond = {1.09, 1.09};
    sfVector2f scale_start = {3, 3};
    sfVector2f scale_exit = {3, 3};
    sfVector2f pos_exit = {13, 925};
    sfVector2f pos_bouton = {1, 10};

    my_hunter->texture = STCF("./image/fond.png", NULL);
    my_hunter->sprite = sfSprite_create();
    my_hunter->start = STCF("./image/start.png", NULL);
    my_hunter->bouton_start = sfSprite_create();
    my_hunter->exit = STCF("./image/quit.png", NULL);
    my_hunter->bouton_exit = sfSprite_create();
    my_hunter->scale_fond = scale_fond;
    my_hunter->scale_start = scale_start;
    my_hunter->scale_exit = scale_exit;
    my_hunter->pos_exit = pos_exit;
    my_hunter->pos_bouton = pos_bouton;
}

void init_menu2(struct my_hunter *my_hunter)
{
    sfVector2f scale_option = {3, 3};
    sfVector2f pos_option = {13, 120};

    my_hunter->option = STCF("./image/option.png", NULL);
    my_hunter->bouton_option = sfSprite_create();
    my_hunter->scale_option = scale_option;
    my_hunter->pos_option = pos_option;
}

void gestion_sprite(struct my_hunter *my_hunter)
{
    SST(my_hunter->sprite, my_hunter->texture, sfTrue);
    sfSprite_setScale(my_hunter->sprite, my_hunter->scale_fond);
    SST(my_hunter->bouton_exit, my_hunter->exit, sfTrue);
    sfSprite_setScale(my_hunter->bouton_exit, my_hunter->scale_exit);
    SSTP(my_hunter->bouton_exit, my_hunter->pos_exit);
    SST(my_hunter->bouton_start, my_hunter->start, sfTrue);
    sfSprite_setScale(my_hunter->bouton_start, my_hunter->scale_start);
    SSTP(my_hunter->bouton_start, my_hunter->pos_bouton);
    SST(my_hunter->bouton_option, my_hunter->option, sfTrue);
    sfSprite_setScale(my_hunter->bouton_option, my_hunter->scale_option);
    SSTP(my_hunter->bouton_option, my_hunter->pos_option);
}

void fenetre(struct my_hunter *my_hunter)
{
    init_menu(my_hunter);
    init_menu2(my_hunter);
    gestion_sprite(my_hunter);
    my_hunter->windows = SRWC(my_hunter->mode, "SFMLwindow", ECR, NULL);
    sfRenderWindow_setFramerateLimit(my_hunter->windows, 30);
    while (sfRenderWindow_isOpen(my_hunter->windows)) {
        close_event(my_hunter);
        click(my_hunter);
        SRWS(my_hunter->windows, my_hunter->sprite, NULL);
        SRWS(my_hunter->windows, my_hunter->bouton_start, NULL);
        SRWS(my_hunter->windows, my_hunter->bouton_exit, NULL);
        SRWS(my_hunter->windows, my_hunter->bouton_option, NULL);
        sfRenderWindow_display(my_hunter->windows);
    }
    sfRenderWindow_destroy(my_hunter->windows);
}
