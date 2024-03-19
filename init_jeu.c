/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** main.c
*/
#include "my_hunter.h"

void init2(struct my_hunter *my_hunter)
{
    sfClock *clock;
    sfClock *anim;

    clock = sfClock_create();
    my_hunter->clock = clock;
    anim = sfClock_create();
    my_hunter->anim = anim;
}

void init_jeu(struct my_hunter *my_hunter)
{
    sfVector2f scale_chen = {4, 4};
    sfIntRect chen_ani;
    sfVector2f pos_chen = {-100, 500};

    chen_ani.height = 33;
    chen_ani.width = 24;
    chen_ani.left = 0;
    chen_ani.top = 0;
    my_hunter->fond_jeu_t = STCF("./image/fond_jeu.jpg", NULL);
    my_hunter->fond_jeu_s = sfSprite_create();
    my_hunter->chen_t = STCF("./image/chen.png", NULL);
    my_hunter->chent_s = sfSprite_create();
    my_hunter->scale_chen = scale_chen;
    my_hunter->pos_chen = pos_chen;
    my_hunter->chen_ani = chen_ani;
    sfSprite_setTexture(my_hunter->fond_jeu_s, my_hunter->fond_jeu_t, sfTrue);
    sfSprite_setTexture(my_hunter->chent_s, my_hunter->chen_t, sfTrue);
    sfSprite_setScale(my_hunter->chent_s, my_hunter->scale_chen);
    sfSprite_setPosition(my_hunter->chent_s, my_hunter->pos_chen);
}

void init_vie1(struct my_hunter *my_hunter)
{
    sfVector2f scale_etoile1 = {3, 3};
    sfVector2f pos_etoile1 = {1, 925};

    my_hunter->vie = 3;
    my_hunter->etoile1 = STCF("./image/etoile1.png", NULL);
    my_hunter->bouton_etoile1 = sfSprite_create();
    my_hunter->scale_etoile1 = scale_etoile1;
    my_hunter->pos_etoile1 = pos_etoile1;
    sfSprite_setTexture(my_hunter->bouton_etoile1, my_hunter->etoile1, sfTrue);
    sfSprite_setScale(my_hunter->bouton_etoile1, my_hunter->scale_etoile1);
    sfSprite_setPosition(my_hunter->bouton_etoile1, my_hunter->pos_etoile1);
    init_vie2(my_hunter);
}

void init_vie2(struct my_hunter *my_hunter)
{
    sfVector2f scale_etoile2 = {3, 3};
    sfVector2f pos_etoile2 = {80, 925};

    my_hunter->etoile2 = STCF("./image/etoile2.png", NULL);
    my_hunter->bouton_etoile2 = sfSprite_create();
    my_hunter->scale_etoile2 = scale_etoile2;
    my_hunter->pos_etoile2 = pos_etoile2;
    SST(my_hunter->bouton_etoile2, my_hunter->etoile2, sfTrue);
    sfSprite_setScale(my_hunter->bouton_etoile2, my_hunter->scale_etoile2);
    sfSprite_setPosition(my_hunter->bouton_etoile2, my_hunter->pos_etoile2);
    init_vie3(my_hunter);
}

void init_vie3(struct my_hunter *my_hunter)
{
    sfVector2f scale_etoile3 = {3, 3};
    sfVector2f pos_etoile3 = {160, 925};

    my_hunter->etoile3 = STCF("./image/etoile3.png", NULL);
    my_hunter->bouton_etoile3 = sfSprite_create();
    my_hunter->scale_etoile3 = scale_etoile3;
    my_hunter->pos_etoile3 = pos_etoile3;
    SST(my_hunter->bouton_etoile3, my_hunter->etoile3, sfTrue);
    sfSprite_setScale(my_hunter->bouton_etoile3, my_hunter->scale_etoile3);
    sfSprite_setPosition(my_hunter->bouton_etoile3, my_hunter->pos_etoile3);
}