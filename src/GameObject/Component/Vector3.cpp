//
// Created by prefo on 2018-12-17.
//

#include "Vector3.h"

double Vector3::getX() const {
    return x;
}

void Vector3::setX(double x) {
    Vector3::x = x;
}

double Vector3::getY() const {
    return y;
}

void Vector3::setY(double y) {
    Vector3::y = y;
}

double Vector3::getZ() const {
    return z;
}

void Vector3::setZ(double z) {
    Vector3::z = z;
}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3::Vector3() {}
