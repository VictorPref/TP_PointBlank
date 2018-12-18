//
// Created by prefo on 2018-12-17.
//

#include "Input.h"

void Input::Show() {

    std::cout << "vertical Direction : " << leftRightDir << std::endl;
    std::cout << "horizontal Direction : " << upDownDir << std::endl;
    std::cout << "vertical Camera : " << leftRightCam << std::endl;
    std::cout << "horizontal Camera : " << upDownCam << std::endl;
    std::cout << "A : " << A << std::endl;
    std::cout << "B : "<< B << std::endl;
    std::cout << "X : "<< X << std::endl;
    std::cout << "Y : "<< Y << std::endl;
    std::cout << "Start : "<< start<< std::endl;
    std::cout << "LB : "<< lb<< std::endl;
    std::cout << "LT : "<< lt<< std::endl;
    std::cout << "RB : "<< rb<< std::endl;
    std::cout << "RT : "<< rt<< std::endl;
}
