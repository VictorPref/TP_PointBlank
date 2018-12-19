//
// Created by prefo on 2018-12-17.
//

#include "Player.h"

void Player::Update(std::vector<GameObject*> level) {

    std::vector<GameObject*> collision;

    for(int i = 0 ; i < level.size();i++){
        GameObject* go =level[i];
        if(AABB::TestCollision(this,go)){

            collision.push_back(go);

        }
    }

    Vector3 direction(0,0,0);
    if(collision.size() > 0){

      if(canFall(collision)){
            direction.setZ(-1);
         }


    }else{
        direction.setZ(-1);
    }

    transform= transform +direction;
}

Player::Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color) : Cube(
        transform, scale, rotation, color) {}

Player::Player(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,
               int divisionTexture) : Cube(transform, scale, rotation, pathTexture, divisionTexture) {}

bool Player::canJump(std::vector<GameObject *> collision) {





    return false;
}

bool Player::canFall(std::vector<GameObject *> collision) {


    for(int i = 0 ; i < collision.size();i++){

        int z = collision[i]->getTransform().getZ() + collision[i]->getScale().getZ();

        if(z <=  transform.getZ()){
            return false;
        }

    }

    return true;
}
