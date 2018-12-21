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

SDL_Window* win;
SDL_GLContext context;
bool isRunning = true;

int main(int ergc, char** args) {

    // int width = 800, height = 600;

    // Menu menu{width,height};

    // menu.Init();
    // menu.Start();
    // menu.Clean();

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    win = SDL_CreateWindow("OpenGl Test", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GLContext context = SDL_GL_CreateContext(win);
    //   SDL_GL_SetSwapInterval(10);
    //charger la matrice de transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,(double)800/600,1,1000);

    SDL_Event event;


    // gluLookAt(100,100,100,0,0,0,0,0,1);


    Player* player = new Player(Vector3(0,0,60),Vector3(10,10,10),Vector3(0,0,0),Vector3(250,120,40),0);
    Cube* sol = new Cube (Vector3(-60,-100,0),Vector3(300,300,1),Vector3(0,0,0),Vector3(120,40,250));
    Cube* testCollision = new Cube (Vector3(0,0,0),Vector3(20,20,20),Vector3(0,0,0),Vector3(255,0,0));



    SDL_Joystick* gGameController = nullptr;
    if( SDL_NumJoysticks() < 1 )
    {
        printf( "Warning: No joysticks connected!\n" );
    }
    else
    {
        //Load joystick
        gGameController = SDL_JoystickOpen( 0 );
        if( gGameController == NULL )
        {
            printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
        }
    }

    player->setController(gGameController);


    BulletManager* bulletManager = BulletManager::getInstance();




    std::vector<GameObject*> levels;
    levels.push_back(sol);
    levels.push_back(testCollision);

    while (isRunning) {

        //effacer le tampon d’affichage



        glClearColor(1.f, 1.f, 1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        //gestion evenement
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isRunning = false;

        }

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        const Uint8 *state = SDL_GetKeyboardState(NULL);


        //dessiner sur le buffer



        player->Update(levels);


        // player->draw();
        sol->draw();
        testCollision->draw();
        bulletManager->DrawBullets();
        glPushMatrix();
        glTranslatef(player->getTransform().getX(),player->getTransform().getY(),player->getTransform().getZ());
        drawAxis(50);
        glPopMatrix();

        //pause
        SDL_Delay(15);
        //mise a jour de l'ecran
        glFlush();
        SDL_GL_SwapWindow(win);
    }
    //vider la memoire
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;


    return 0;
}


