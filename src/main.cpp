#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Menu/Menu.h"
#include "utils/Utils.h"
#include "Jeu/Jeu.h"

int main(int ergc, char** args) {

    int width = 1600, height = 900;
    Menu menu{width,height};

    menu.Init();
    menu.Start();
    menu.Clean();
    Jeu jeu;
    jeu.initialisation();
	jeu.demarrerJeu();
		

    return 0;
}