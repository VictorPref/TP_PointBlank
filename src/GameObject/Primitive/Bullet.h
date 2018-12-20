//
// Created by prefo on 2018-12-19.
//

#ifndef TP_POINTBLANK_BULLET_H
#define TP_POINTBLANK_BULLET_H

#include "Cube.h"
class Bullet: public Cube {

    int id;
    int time;

public:
    Bullet(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color, int id);

};


#endif //TP_POINTBLANK_BULLET_H
