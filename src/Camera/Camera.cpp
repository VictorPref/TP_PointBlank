//
// Created by Jean-François on 12/19/2018.
//

#include "Camera.h"

Camera::Camera() {}

void Camera::LookLeft() {

    angleZRotationCamera--;
}

void Camera::LookRight() {

    angleZRotationCamera++;
}

void Camera::LookUp() {

    if(angleXRotationCamera>-angleMaxView)
        angleXRotationCamera--;
}

void Camera::LookDown() {

    if(angleXRotationCamera < angleMaxView)
        angleXRotationCamera++;
}
