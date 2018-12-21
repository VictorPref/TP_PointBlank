//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_PLAYER_H
#define TP_POINTBLANK_PLAYER_H

#include "../GameObject/Primitive/Cube.h"
#include "Input.h"
#include "../Collision/AABB.h"
#include "../Manager/InputManager.h"
#include "../Manager/BulletManager.h"
#include "../Camera/Camera.h"
#include "../GameObject/Component/UI.h"
class BulletManager;
class Player: public Cube {

    int id;
    SDL_Joystick* controller;
    double vitesse = 1;
    Input input;
    BulletManager* bulletManager;
    Camera  camera;
    float health =1;
    UI* ui;


public:
    void Update(std::vector<GameObject*> level);

    Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color, int id);

    Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,
           int divisionTexture, int id);

    bool canJump(std::vector<GameObject*> collision);
    bool canFall(std::vector<GameObject*> collision);


    void canMove(std::vector<GameObject *> collision,Vector3 oldPos);
    Vector3 MoveForward();


    Vector3 MoveBackward();


    Vector3 MoveLeft();


    Vector3 MoveRight();

    void setController(SDL_Joystick *controller);

    Camera &getCamera();

    int getId() const;

    UI *getUi() const;

    float getHealth() const;


};


#endif //TP_POINTBLANK_PLAYER_H
