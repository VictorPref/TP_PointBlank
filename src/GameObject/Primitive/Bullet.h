//
// Created by prefo on 2018-12-19.
//

#ifndef TP_POINTBLANK_BULLET_H
#define TP_POINTBLANK_BULLET_H

#include "Cube.h"
class Bullet: public Cube {

    int id;
    Uint32  tme = 50;
    bool alive = true;

public:
    Bullet(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color, int id);


    Uint32 getTme() const;

    bool isAlive() const;

    void setAlive(bool alive);
};


#endif //TP_POINTBLANK_BULLET_H
