//
// Created by prefo on 2018-12-18.
//

#ifndef TP_POINTBLANK_AABB_H
#define TP_POINTBLANK_AABB_H

#include "../GameObject/Component/Vector3.h"
#include "../GameObject/Primitive/Cube.h"

class AABB {

    Vector3 minExtends;
    Vector3 maxExtends;


public:
    AABB( Vector3 &minExtends,  Vector3 &maxExtends);

    bool Intersect(AABB aabb);

     Vector3 &getMinExtends() ;

    void setMinExtends( Vector3 &minExtends);

     Vector3 &getMaxExtends() ;

    void setMaxExtends( Vector3 &maxExtends);

    float MaxDistance(Vector3 distance);
   static bool TestCollision(GameObject* a,GameObject* b);

};


#endif //TP_POINTBLANK_AABB_H
