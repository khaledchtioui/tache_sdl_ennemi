#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct enemie {
    SDL_Surface *spritesheet;
    int direction;
    SDL_Rect pos, xminimale, xmaximale;
    SDL_Rect posspritesheet;
} enemie;

typedef struct {
    SDL_Surface *perso;
    SDL_Rect perso_pos;
} personnage;

void init_enemie(enemie *E);
void afficher_enemie(enemie *E, SDL_Surface *screen);
void animate_enemie(enemie *E);
void deplacer(enemie *E);
void deplacerIA(enemie *E, SDL_Rect posPerso);
void initialiser_perso(personnage *p);
void afficher_perso(personnage *p, SDL_Surface *screen);

#endif // ENNEMI_H_INCLUDED

