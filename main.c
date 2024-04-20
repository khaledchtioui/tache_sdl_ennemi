#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "ennemi.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 720
#define FPS 60

SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;

int initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 0;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    SDL_WM_SetCaption("ENTITE SECONDAIRE", NULL);
    return 1;
}

void cleanup() {
    SDL_FreeSurface(background);
    SDL_Quit();
}

int main() {
    if (!initSDL())
        return 1;

    srand(time(NULL)); // Initialize random seed

    background = IMG_Load("back.png");
    if (background == NULL) {
        printf("Unable to load background image: %s\n", IMG_GetError());
        cleanup();
        return 1;
    }

    enemie E;
    init_enemie(&E);

    personnage p;
    initialiser_perso(&p);

    SDL_Event event;
    int done = 1;
    Uint32 startTime, endTime, frameTime;

    while (done) {
        startTime = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = 0;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT:
                        p.perso_pos.x += 20;
                        break;
                    case SDLK_LEFT:
                        p.perso_pos.x -= 20;
                        break;
                    case SDLK_UP:
                        p.perso_pos.y -= 20;
                        break;
                    case SDLK_DOWN:
                        p.perso_pos.y += 20;
                        break;
                }
            }
        }

        SDL_BlitSurface(background, NULL, screen, NULL);
        afficher_enemie(&E, screen);
        animate_enemie(&E);
        deplacerIA(&E, p.perso_pos);
        deplacer(&E);
        afficher_perso(&p, screen);
        SDL_Flip(screen);

        endTime = SDL_GetTicks();
        frameTime = endTime - startTime;
        if (frameTime < 1000 / FPS) {
            SDL_Delay(1000 / FPS - frameTime);
        }
    }

    cleanup();
    return 0;
}

