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

void Camera::Look(Vector3 &playerTransform) {
    glRotatef(angleXRotationCamera,1,0,0);
    glRotatef(angleZRotationCamera,0,1,0);
    gluLookAt(playerTransform.getX(),playerTransform.getY(), playerTransform.getZ()+1,playerTransform.getX(), playerTransform.getY()+1, playerTransform.getZ()+1, 0, 0, 1);

}

void Camera::Update() {

}

Camera::Camera(const Vector3 &playerTransform) : playerTransform(playerTransform) {}


