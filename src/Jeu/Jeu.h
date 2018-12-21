//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_JEU_H
#define TP_POINTBLANK_JEU_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <random>
#include <vector>
#include <time.h>
#include "../Player/Player.h"
#include "../Manager/PlayerManager.h"
#include "../GameObject/GameObject.h"
#include "vector"
class PlayerManager;
class Jeu {

    PlayerManager* playerManager;


public:
    void initialisation();
    void demarrerJeu();
    void nettoyer();
	SDL_Window* win;
	std::vector<Player> players;
	std::vector<GameObject*> level;
	bool isRunning;
	int timeOfDay;
	void dessinerSurRender();
	void Update();
	
private:
    void effacer();
	Cube* sol ;
  BulletManager* bulletManager;
	Player* player;
	SDL_GLContext context;
    
};


#endif //TP_POINTBLANK_JEU_H
