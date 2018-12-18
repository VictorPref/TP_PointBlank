//
// Created by Jean-François on 12/17/2018.
//

#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager* InputManager::getInstance()
{
    if (!instance)
    {
        instance = new InputManager();
    }

    return instance;
}

InputManager::InputManager()
{}

Input InputManager::GetKeysInput(SDL_Joystick* controller) {
    Input toRet;

    if(controller)
    {
        if( SDL_JoystickGetAxis(controller, 1) < -10000 )
        {
            toRet.leftRightDir = -1;
        }
        else if( SDL_JoystickGetAxis(controller, 1) > 10000 )
        {
            toRet.leftRightDir = 1;
        }

        if( SDL_JoystickGetAxis(controller, 0) < -10000 )
        {
            toRet.upDownDir = -1;
        }
        else if( SDL_JoystickGetAxis(controller, 0) > 10000 )
        {
            toRet.upDownDir = 1;
        }

        if( SDL_JoystickGetAxis(controller, 3) < -10000 )
        {
            toRet.leftRightCam = -1;
        }
        else if( SDL_JoystickGetAxis(controller, 3) > 10000 )
        {
            toRet.leftRightCam = 1;
        }

        if( SDL_JoystickGetAxis(controller, 4) < -10000 )
        {
            toRet.upDownCam = -1;
        }
        else if( SDL_JoystickGetAxis(controller, 4) > 10000 )
        {
            toRet.upDownCam = 1;
        }

        if(SDL_JoystickGetButton(controller, SDL_CONTROLLER_BUTTON_A) > 0 )
        {

            toRet.A = true;
        }

        if (SDL_JoystickGetButton(controller, SDL_CONTROLLER_BUTTON_B) >0)
        {
            toRet.B = true;
        }

        if (SDL_JoystickGetButton(controller, SDL_CONTROLLER_BUTTON_X) >0)
        {
            toRet.X = true;
        }

        if (SDL_JoystickGetButton(controller, SDL_CONTROLLER_BUTTON_Y) >0)
        {
            toRet.Y = true;
        }

        if (SDL_JoystickGetButton(controller, 4) > 0)
        {
            toRet.lb = true;
        }

        if (SDL_JoystickGetButton(controller, 5) > 0)
        {
            toRet.rb = true;
        }

        if (SDL_JoystickGetAxis(controller, 2) > 10000)
        {
            toRet.lt = true;
        }
        if (SDL_JoystickGetAxis(controller, 5) >10000)
        {
            toRet.rt = true;
        }

        if (SDL_JoystickGetButton(controller, SDL_CONTROLLER_BUTTON_START) >0)
        {
            toRet.start = true;
        }

    }

    return toRet;
}
