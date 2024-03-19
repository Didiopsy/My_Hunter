/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_hunter.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <stdio.h>
    #include <stdlib.h>
    #define EXIT_ERROR 84
    #define SRWC sfRenderWindow_create
    #define SRWS sfRenderWindow_drawSprite
    #define SST sfSprite_setTexture
    #define SSTP sfSprite_setPosition
    #define SSSC sfSprite_setScale
    #define SGGB sfSprite_getGlobalBounds
    #define SRWMP sfRenderWindow_mapPixelToCoords
    #define ECR sfResize | sfClose
    #define STCF(x, y) sfTexture_createFromFile(x, y)
    #define PER_X my_hunter->pos_chen.x
    #define PER_Y my_hunter->pos_chen.y

typedef struct my_hunter {
    sfVideoMode mode;
    sfRenderWindow* windows;
    sfEvent event;
    sfMusic* yes;
    sfFont* font;
    sfVector2i mouse;
    sfClock *clock;
    sfClock *anim;
    sfTime time;
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f scale_fond;
    sfTexture* fond_option_t;
    sfSprite* fond_option_s;
    sfVector2f scale_option_ss;
    sfTexture* start;
    sfSprite* bouton_start;
    sfVector2f scale_start;
    sfTexture* exit;
    sfSprite* bouton_exit;
    sfVector2f scale_exit;
    sfTexture* music;
    sfVector2f scale_music;
    sfSprite* bouton_music;
    sfTexture* pause;
    sfSprite* bouton_pause;
    sfVector2f scale_pause;
    sfTexture* option;
    sfSprite* bouton_option;
    sfVector2f scale_option;
    sfVector2f pos_bouton;
    sfVector2f pos_exit;
    sfVector2f pos_music;
    sfVector2f pos_pause;
    sfVector2f pos_option;
    sfTexture* fond_jeu_t;
    sfSprite* fond_jeu_s;
    int vie;
    int end;
    int score;
    float temps;
    int val;
    int pause_count;
    int mul;
    sfTexture* etoile1;
    sfTexture* etoile2;
    sfTexture* etoile3;
    sfSprite* bouton_etoile1;
    sfSprite* bouton_etoile2;
    sfSprite* bouton_etoile3;
    sfVector2f scale_etoile1;
    sfVector2f scale_etoile2;
    sfVector2f scale_etoile3;
    sfVector2f pos_etoile1;
    sfVector2f pos_etoile2;
    sfVector2f pos_etoile3;
    sfTexture* pause_jeu;
    sfSprite* bouton_pause_jeu;
    sfVector2f scale_pause_jeu;
    sfVector2f pos_pause_jeu;
    sfTexture* pause_pause;
    sfSprite* bouton_pause_pause;
    sfVector2f scale_pause_pause;
    sfVector2f pos_pause_pause;
    sfTexture* chen_t;
    sfSprite* chent_s;
    sfVector2f pos_chen;
    sfVector2f scale_chen;
    sfIntRect chen_ani;
} my_hunter;

void close_event(struct my_hunter *my_hunter);
void fenetre(struct my_hunter *my_hunter);
void jeu(struct my_hunter *my_hunter);
void click(struct my_hunter *my_hunter);
void click_perso(struct my_hunter *my_hunter);
void mouvement(struct my_hunter *my_hunter);
void clock(struct my_hunter *my_hunter);
void option(struct my_hunter *my_hunter);
void init_vie3(struct my_hunter *my_hunter);
void init_vie1(struct my_hunter *my_hunter);
void init_vie2(struct my_hunter *my_hunter);
void res_lvl(struct my_hunter *my_hunter);
void animation(struct my_hunter *my_hunter);

#endif
