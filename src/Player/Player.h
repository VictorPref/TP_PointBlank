//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_PLAYER_H
#define TP_POINTBLANK_PLAYER_H

#include "../GameObject/Primitive/Cube.h"
#include "Input.h"
class Player: public Cube {

    int id;
    Input input;

public:
    void Update();


};


#endif //TP_POINTBLANK_PLAYER_H
