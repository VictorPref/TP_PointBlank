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


void BulletManager::CreateBullet(int id) {

}

void BulletManager::UpdateBullets() {

}

BulletManager::BulletManager() {}
