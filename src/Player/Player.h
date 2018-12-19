//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_PLAYER_H
#define TP_POINTBLANK_PLAYER_H

#include "../GameObject/Primitive/Cube.h"
#include "Input.h"
#include "../Collision/AABB.h"
class Player: public Cube {

    int id;
    SDL_Joystick* controller;

public:
    void Update(std::vector<GameObject*> level);

    Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color);

    Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,
           int divisionTexture);

    bool canJump(std::vector<GameObject*> collision);
    bool canFall(std::vector<GameObject*> collision);


};


#endif //TP_POINTBLANK_PLAYER_H
