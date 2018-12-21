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
    std::cout << r.getX();
  //  if(r.getZ() >= 180){
  //      double xtemp = r.getX();
  //      r.setX(-r.getX());
       // r.setY(-r.getY());
  //      r.setZ(-r.getZ());
  ///  }
   //else{
   //    double xtemp = r.getX();
   //    r.setX(r.getZ());
   //    // r.setY(-r.getY());
   //    r.setZ(xtemp);
   //}

   if(r.getZ() > 90 && r.getZ() < 180){
       r.setX(180-r.getX());
   }else if(r.getZ() > 180 && r.getZ() < 270){
       r.setX(270-r.getX());
   }



    //if(r.getX() > 30){
  //      r.setX(30);
  //  }
   // else if(r.getX() < -30){
   //     r.setX(-30);
   // }




    Bullet* b = new Bullet(t,Vector3(1,100,1),player->getRotation(),Vector3(255,255,255),player->getId());
    bullets.push_back(b);


    std::cout<<"X: "<<r.getX()<<"  Y: "<<r.getY()<<"  Z: "<<r.getZ()<<std::endl;
    std::cout<<"X: "<<player->getRotation().getX()<<"  Y: "<<player->getRotation().getY()<<"  Z: "<<player->getRotation().getZ()<<std::endl;
}

void BulletManager::UpdateBullets() {

}

BulletManager::BulletManager() {}

void BulletManager::DrawBullets() {

    for(int i = 0; i < bullets.size();i++){

        bullets[i]->draw();

    }

}
