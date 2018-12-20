//
// Created by prefo on 2018-12-19.
//

#include "BulletManager.h"

BulletManager* BulletManager::instance = nullptr;
BulletManager* BulletManager::getInstance()
{
    if (!instance)
    {
        instance = new BulletManager();
    }

    return instance;
}


void BulletManager::CreateBullet(Player* player) {


    Vector3 t = player->getTransform();
    Vector3 f = player->getRotation();
    Vector3 r(0,0,0);
    Bullet* b = new Bullet(t,Vector3(1,500,1),f + r,Vector3(255,255,255),player->getId());
    bullets.push_back(b);

}

void BulletManager::UpdateBullets() {

}

BulletManager::BulletManager() {}

void BulletManager::DrawBullets() {

    for(int i = 0; i < bullets.size();i++){

        bullets[i]->draw();

    }

}
