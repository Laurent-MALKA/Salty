//
// Created by laurent on 10/21/17.
//

#include "Jeu.hpp"


Jeu::Jeu() {
    window = SDL_CreateWindow("Salty", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, 0);
    rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    srand(time(NULL));
    initEspion();
    affichage.init(rend);
}

Jeu::~Jeu() {
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
}

void Jeu::gameLoop() {
    Joueur* j1;
    Joueur* j2;;

    while (keyboard.isStillReleased(SDL_SCANCODE_ESCAPE)) {
        j1= (Joueur*) espions[0];
        j2= (Joueur*) espions[1];

        affichage.displayBackgroundOnly(rend);

        do {
            keyboard.update();
        } while (keyboard.isKeyboardReleased());

        affichage.changerBackground(rend, "../img/grass2.png");

        while(keyboard.isStillReleased(SDL_SCANCODE_ESCAPE) && j1->getNbRounds()<2 && j2->getNbRounds()<2){

            while (keyboard.isStillReleased(SDL_SCANCODE_ESCAPE) && j1->getNbRounds() < 2 && j2->getNbRounds() < 2 &&
                   (!j1->estMort() && !j2->estMort())) {
                keyboard.update();

                Moteur::lecture(j1, keyboard);
                Moteur::lecture(j2, keyboard);

                Moteur::deplacements(espions);
                Moteur::testTouche(espions);

                affichage.display(rend, espions);
                SDL_Delay(16);
            }
            if(j1->estMort()){
                j2->setNbRounds(j2->getNbRounds()+1);
            }
            else if(j2->estMort()){
                j1->setNbRounds(j1->getNbRounds()+1);
            }
            resetEspions(j1, j2);
        }

        affichage.display(rend, espions);
        SDL_Delay(2000);
        affichage.changerBackground(rend, "../img/ecran_titre.png");
        j1->setNbRounds(0);
        j2->setNbRounds(0);

    }
}

void Jeu::initEspion() {
    SDL_Surface *idle_surface = IMG_Load("../img/espion.png");
    SDL_Texture *idle_texture = SDL_CreateTextureFromSurface(rend, idle_surface);

    SDL_Surface *marche1_surface = IMG_Load("../img/espionMarche1.png");
    SDL_Texture *marche1_texture = SDL_CreateTextureFromSurface(rend, marche1_surface);

    SDL_Surface *marche2_surface = IMG_Load("../img/espionMarche2.png");
    SDL_Texture *marche2_texture = SDL_CreateTextureFromSurface(rend, marche2_surface);

    SDL_Surface *mort_surface = IMG_Load("../img/mort.png");
    SDL_Texture *mort_texture = SDL_CreateTextureFromSurface(rend, mort_surface);


    SDL_Surface *arme_surface = IMG_Load("../img/arme.png");
    SDL_Texture *arme_texture = SDL_CreateTextureFromSurface(rend, arme_surface);


    SDL_FreeSurface(idle_surface);
    SDL_FreeSurface(marche1_surface);
    SDL_FreeSurface(marche2_surface);
    SDL_FreeSurface(mort_surface);

    SDL_FreeSurface(arme_surface);


    Image *image_espion = new Image();
    image_espion->addTexture(idle_texture);
    image_espion->addTexture(marche1_texture);
    image_espion->addTexture(marche2_texture);
    image_espion->addTexture(mort_texture);


    Image *image_arme = new Image();
    image_arme->addTexture(arme_texture);

    Arme arme(image_arme);

    espions.push_back(
            new Joueur(image_espion,
                       Input(SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_D, SDL_SCANCODE_A, SDL_SCANCODE_E), arme));
    espions.push_back(
            new Joueur(image_espion,
                       Input(SDL_SCANCODE_O, SDL_SCANCODE_L, SDL_SCANCODE_SEMICOLON, SDL_SCANCODE_K, SDL_SCANCODE_P),
                       arme));

    for (int i = 0; i < 20; ++i) {
        espions.push_back(new IA(image_espion));
    }
}

void Jeu::resetEspions(Joueur* j1, Joueur* j2){
    j1->setArmeSortie(false);
    j2->setArmeSortie(false);

    j1->setCdAtq(0);
    j2->setCdAtq(0);

    for(int i=0; i<espions.size(); i++){
        espions[i]->setMort(false);
        espions[i]->randomRect();
        espions[i]->setIndiceAnimation(0);
        espions[i]->setFrame(0);
    }

}

SDL_Window *Jeu::getWindow() const {
    return window;
}

SDL_Renderer *Jeu::getRend() const {
    return rend;
}
