//
// Created by prefo on 2018-12-19.
//

#ifndef TP_POINTBLANK_BULLETMANAGER_H
#define TP_POINTBLANK_BULLETMANAGER_H

#include "vector"
#include "../GameObject/Primitive/Bullet.h"

class BulletManager {

    std::vector<Bullet*> bullets;
    static BulletManager* instance;
    BulletManager();

public:

    static BulletManager* getInstance();
    void CreateBullet(int id);
    void UpdateBullets();



};


#endif //TP_POINTBLANK_BULLETMANAGER_H
