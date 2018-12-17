//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_JEU_H
#define TP_POINTBLANK_JEU_H

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../Player/Player.h"
#include "../Manager/PlayerManager.h"
#include "../GameObject/GameObject.h"

class Jeu {

    PlayerManager playerManager;


public:
    void initialisation();
    void demarrerJeu();
    void nettoyer();

private:
    void effacer(void);
    void dessinerSurRender();
    void Update(void);
};


#endif //TP_POINTBLANK_JEU_H
