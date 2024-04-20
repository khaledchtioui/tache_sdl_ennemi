#include "ennemi.h"

void init_enemie(enemie *E) {
    E->spritesheet = IMG_Load("hero_spr.png");
    E->pos.x = 510;
    E->pos.y = 480;
    E->direction = 0;

    E->posspritesheet.x = 0;
    E->posspritesheet.y = 0;
    E->posspritesheet.h = 100;
    E->posspritesheet.w = 100;

    E->xminimale.x = 500;
    E->xmaximale.x = 700;
}

void afficher_enemie(enemie *E, SDL_Surface *screen) {
    SDL_BlitSurface(E->spritesheet, &E->posspritesheet, screen, &E->pos);
}

void animate_enemie(enemie *E) {
    E->posspritesheet.y = E->direction * E->posspritesheet.h;
    if (E->posspritesheet.x >= 300) {
        E->posspritesheet.x = 0;
    } else {
        E->posspritesheet.x += E->posspritesheet.w; // +=100
    }
}

void deplacer(enemie *E) {
    if (E->pos.x < E->xminimale.x) {
        E->direction = 0;
    } else if (E->pos.x > E->xmaximale.x) {
        E->direction = 1;
    }

    if (E->direction == 0) {
        E->pos.x += 15;
    }
    if (E->direction == 1) {
        E->pos.x -= 15;
    }
}

void deplacerIA(enemie *E, SDL_Rect posPerso) {
    int distance = E->pos.x - posPerso.x;
    if (distance < 200 && distance > 80) {
        E->direction = 1;
        E->pos.x -= 20;
    } else if (distance < -80 && distance > -200) {
        E->direction = 0;
        E->pos.x += 20;
    } else if (distance <= 80 && distance >= 0) {
        E->direction = 3;
    } else if (distance <= 0 && distance >= -80) {
        E->direction = 2;
    }
}

int collision(SDL_Rect E, SDL_Rect p) {
    if ((p.x + p.w) < E.x || p.x > (E.x + E.w) || (p.y + p.h) < E.y || p.y > (E.y + E.h)) {
        return 0;
    } else {
        return 1;
    }
}

void initialiser_perso(personnage *p) {
    p->perso = IMG_Load("perso1.png");
    p->perso_pos.x = 100;
    p->perso_pos.y = 520;
    p->perso_pos.h = 281;
    p->perso_pos.w = 217;
}

void afficher_perso(personnage *p, SDL_Surface *screen) {
    SDL_BlitSurface(p->perso, NULL, screen, &p->perso_pos);
    SDL_Delay(100); // Adds a pause of 100 milliseconds to the program
}

