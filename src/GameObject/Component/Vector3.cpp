//
// Created by prefo on 2018-12-17.
//

#include "Vector3.h"
#include "math.h"

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


Vector3 Vector3::operator-(Vector3 b){

    double xToRet = this->x-b.getX();
    double yToRet = this->getY()-b.getY();
    double zToRet = this->getZ()-b.getZ();

    Vector3 toRet(xToRet,yToRet,zToRet);

    return toRet;

}
Vector3 Vector3::operator+(Vector3 b){

    double xToRet = this->x+b.getX();
    double yToRet = this->getY()+b.getY();
    double zToRet = this->getZ()+b.getZ();

    Vector3 toRet(xToRet,yToRet,zToRet);

    return toRet;

}


Vector3 Vector3::Max(Vector3 a,Vector3 b){

    
    double x1,y1,z1;


    if(abs(a.x) > abs(b.x))
        x1 = a.x;
    else
        x1 =b.x;

    if(abs(a.y) > abs(b.y))
        y1 = a.y;
    else
        y1 =b.y;

    if(abs(a.z) > abs(b.z))
        z1 = a.z;
    else
        z1 =b.z;

    Vector3 max(x1,y1,z1);

    return  max;

}