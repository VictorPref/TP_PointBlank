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
    Camera camera = player->getCamera();
    Vector3 r = camera.getRotation();




    Bullet* b = new Bullet(t,Vector3(1,100,1),r,Vector3(255,255,255),player->getId());
    bullets.push_back(b);


    std::cout<<"X: "<<r.getX()<<"  Y: "<<r.getY()<<"  Z: "<<r.getZ()<<std::endl;
}

void BulletManager::UpdateBullets() {

}

BulletManager::BulletManager() {}

void BulletManager::DrawBullets() {

    for(int i = 0; i < bullets.size();i++){

        bullets[i]->draw();

    }

}
