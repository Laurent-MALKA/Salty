#include "Jeu.hpp"

int init(int);
void close();

int main() {

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;

    if(init(flags)){
        return 1;
    }

    Jeu jeu;

    if(!jeu.getWindow() || !jeu.getRend()){
        close();
        return 1;
    }

    jeu.gameLoop();

    close();

    return 0;
}

int init(int flags){

    if(SDL_Init(SDL_INIT_VIDEO) == 1){
        fprintf(stderr,"Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (TTF_Init() != 0){
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    if((IMG_Init(flags)&flags) != flags){
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        TTF_Quit();
        SDL_Quit();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void close(){
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}