//
// Created by prefo on 2018-12-17.
//

#ifndef TP_POINTBLANK_INPUT_H
#define TP_POINTBLANK_INPUT_H

#include <iostream>

class Input {
public :
    int leftRightDir = 0,upDownDir = 0, leftRightCam = 0, upDownCam = 0;
    bool A = false, B = false,X= false,Y= false,start= false,rb= false,lb= false,rt= false,lt= false;

    void Show();
};


#endif //TP_POINTBLANK_INPUT_H
