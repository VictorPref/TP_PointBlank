//
// Created by prefo on 2018-12-19.
//

#ifndef TP_POINTBLANK_BULLETMANAGER_H
#define TP_POINTBLANK_BULLETMANAGER_H

#include "vector"
#include "../GameObject/Primitive/Bullet.h"
#include "../Player/Player.h"

class Camera;
class Player;


class BulletManager {

    std::vector<Bullet*> bullets;
    static BulletManager* instance;
    BulletManager();

public:

    static BulletManager* getInstance();
    void CreateBullet(Player* player);
    void UpdateBullets();
    void DrawBullets();



};


#endif //TP_POINTBLANK_BULLETMANAGER_H
