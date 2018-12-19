//
// Created by prefo on 2018-12-18.
//

#include "AABB.h"
#include <iostream>

AABB::AABB( Vector3 &minExtends, Vector3 &maxExtends) : minExtends(minExtends), maxExtends(maxExtends) {}

bool AABB::Intersect(AABB aabb) {

    bool t =(minExtends.getX() <= aabb.maxExtends.getX() && maxExtends.getX() >= aabb.minExtends.getX()) &&
    (minExtends.getY() <= aabb.maxExtends.getY() && maxExtends.getY() >= aabb.minExtends.getY()) &&
    (minExtends.getZ() <= aabb.maxExtends.getZ() && maxExtends.getZ() >= aabb.minExtends.getZ());

    return t;

}

 Vector3 &AABB::getMinExtends()  {
    return minExtends;
}

void AABB::setMinExtends( Vector3 &minExtends) {
    AABB::minExtends = minExtends;
}

 Vector3 &AABB::getMaxExtends()  {
    return maxExtends;
}

void AABB::setMaxExtends( Vector3 &maxExtends) {
    AABB::maxExtends = maxExtends;
}
float AABB::MaxDistance(Vector3 distances)
{
    float max;
    if (distances.getX() > distances.getY() && distances.getX() > distances.getZ())
    {
        max = distances.getX();
    }
    else if (distances.getY() > distances.getX() && distances.getY() > distances.getZ())
    {
        max = distances.getY();
    }
    else
    {
        max = distances.getZ();
    }

    return max;
}


bool AABB::TestCollision(GameObject* player,GameObject* b){

    Vector3 playerMax(player->getTransform().getX()+player->getScale().getX(),player->getTransform().getY()+player->getScale().getY(),player->getTransform().getZ()+player->getScale().getZ());

    Vector3 playerMin(player->getTransform().getX(),player->getTransform().getY(),player->getTransform().getZ());
    Vector3 bMax(b->getTransform().getX()+b->getScale().getX(),b->getTransform().getY()+b->getScale().getY(),b->getTransform().getZ()+b->getScale().getZ());

    Vector3 bMin (b->getTransform().getX(),b->getTransform().getY(),b->getTransform().getZ());


    AABB play(playerMin, playerMax);
    AABB bb (bMin, bMax);



    return play.Intersect(bb);


}