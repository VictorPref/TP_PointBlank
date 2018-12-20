//
// Created by prefo on 2018-12-19.
//

#include "Bullet.h"

Bullet::Bullet(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color, int id)
        : Cube(transform, scale, rotation, color), id(id) {}
