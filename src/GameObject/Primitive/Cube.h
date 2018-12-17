//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_CUBE_H
#define TP_POINTBLANK_CUBE_H

#include "../GameObject.h"


class Cube: public GameObject {

public:
    Cube(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const Vector3 &color);

    Cube(const Vector3 &transform, const Vector3 &scale, const Vector3 &rotation, const std::string &pathTexture,
         int divisionTexture);

};


#endif //TP_POINTBLANK_CUBE_H
