//
// Created by Jean-François on 12/17/2018.
//

#ifndef TP_POINTBLANK_INPUTMANAGER_H
#define TP_POINTBLANK_INPUTMANAGER_H

#include "../Player/Input.h"
#include <SDL2/SDL.h>

class InputManager {

private:

    static InputManager* instance;
    InputManager();

public:
    static InputManager* getInstance();
    Input GetKeysInput(SDL_Joystick* controller);
};


#endif //TP_POINTBLANK_INPUTMANAGER_H
