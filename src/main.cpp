#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Menu/Menu.h"


#include <iostream>
#include "GameObject/Primitive/Cube.h"
#include "Player/Player.h"
#include "Collision/AABB.h"
#include "Manager/BulletManager.h"
#include "utils/sdlglutils.h"
#include "Jeu/Jeu.h"
SDL_Window* win;
SDL_GLContext context;
bool isRunning = true;

int main(int ergc, char** args) {

    int width = 1920, height = 1080;

    Menu menu{width,height};

    menu.Init();
    menu.Start();
    menu.Clean();

    if(menu.getSelectedMenuItem() == 0)
    {
       Jeu j;
       j.initialisation();
       j.demarrerJeu();
       j.nettoyer();
    }



    return 0;
}


